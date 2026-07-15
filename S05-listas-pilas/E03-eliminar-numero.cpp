#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Estructura para envolver un arreglo dinámico y su tamaño.
struct ArrayWrapper {
    int* data;
    int size;
};


// Generador congruencial lineal simple para obtener números pseudoaleatorios sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 12345;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 10;
}


// Imprime una lista de vectores (arreglos).
void printArrayList(const DrxList<ArrayWrapper>& arrayList) {
    int nodeIndex = 1;
    typename DrxList<ArrayWrapper>::Iterator it = arrayList.first();
    while (it != arrayList.end()) {
        ArrayWrapper* arr = arrayList.get(it);
        if (arr != nullptr) {
            printf("Arreglo %d: [", nodeIndex);
            for (int i = 0; i < arr->size; ++i) {
                printf("%d", arr->data[i]);
                if (i < arr->size - 1) printf(", ");
            }
            printf("]\n");
        }
        nodeIndex++;
        arrayList.next(it);
    }
}


// Elimina todas las ocurrencias de deleteNumber de la lista de arreglos.
// Concepto Teórico (Recorrido de Estructuras Enlazadas y Modificación de Objetos por Referencia):
// Accedemos a cada elemento de la lista utilizando un Iterator. Dado que la lista almacena objetos
// 'ArrayWrapper' por valor/referencia de acceso, podemos modificar directamente el contenido 
// interno de los nodos (el arreglo dinámico y su tamaño) sin necesidad de reestructurar los enlaces de la lista.
void deleteListNumber(DrxList<ArrayWrapper>& arrayList, int deleteNumber) {
    typename DrxList<ArrayWrapper>::Iterator it = arrayList.first();
    
    // Recorrido secuencial de la lista: O(N * M) donde N es la cantidad de arreglos en la lista 
    // y M es el tamaño promedio de cada arreglo.
    while (it != arrayList.end()) {
        ArrayWrapper* arr = arrayList.get(it);
        if (arr != nullptr) {
            // 1. Fase de Análisis: Contar cuántos elementos sobrevivirán a la eliminación 
            //    para determinar el tamaño exacto de la nueva asignación de memoria.
            int newSize = 0;
            for (int i = 0; i < arr->size; i++) {
                if (arr->data[i] != deleteNumber) {
                    newSize++;
                }
            }

            // 2. Fase de Reasignación: Crear un nuevo arreglo dinámico en el Heap 
            //    con el tamaño ajustado de sobrevivientes.
            int* newData = new int[newSize];
            int idx = 0;
            for (int i = 0; i < arr->size; i++) {
                if (arr->data[i] != deleteNumber) {
                    newData[idx++] = arr->data[i];
                }
            }

            // 3. Fase de Liberación y Enlace (Prevención de Memory Leaks):
            //    Liberamos el bloque de memoria anterior de tamaño 'arr->size' mediante 'delete[]',
            //    luego reasignamos el puntero al nuevo bloque y actualizamos el tamaño.
            delete[] arr->data;
            arr->data = newData;
            arr->size = newSize;
        }
        arrayList.next(it); // Avanzar el iterador al siguiente nodo de la lista
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E03-ELIMINAR-NUMERO =========]\e[0m\n\n";

    int deleteNumber, arraySize;
    std::cout << "Ingrese el tamaño de los arreglos: ";
    if (!(std::cin >> arraySize) || arraySize <= 0) return 1;

    std::cout << "Ingrese el número a eliminar: ";
    if (!(std::cin >> deleteNumber)) return 1;

    DrxList<ArrayWrapper> arrayList;

    // Crear 3 arreglos aleatorios y agregarlos a la lista
    for (int k = 0; k < 3; k++) {
        ArrayWrapper arr;
        arr.size = arraySize;
        arr.data = new int[arraySize];
        for (int i = 0; i < arraySize; i++) {
            arr.data[i] = nextRandom();
        }
        arrayList.pushBack(arr);
    }

    printf("\n\e[0;33mLista Original\e[0m:\n");
    printArrayList(arrayList);

    deleteListNumber(arrayList, deleteNumber);

    printf("\n\e[0;33mLista tras eliminar el número \e[0;32m%d\e[0m:\n", deleteNumber);
    printArrayList(arrayList);
    std::cout << "\n";

    // Liberar memoria dinámica
    typename DrxList<ArrayWrapper>::Iterator it = arrayList.first();
    while (it != arrayList.end()) {
        ArrayWrapper* arr = arrayList.get(it);
        if (arr != nullptr) {
            delete[] arr->data;
        }
        arrayList.next(it);
    }

    return 0;
}
