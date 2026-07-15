#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

const int ARRAY_SIZE = 10; // Reducido para visualización en consola

struct ArrayWrapper {
    int* data;
    int size;
};


// Generador congruencial lineal simple para obtener números pseudoaleatorios sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 54321;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 10;
}


// Suma recursiva de los elementos de un arreglo.
// Concepto Teórico (Recursión Lineal sobre Arreglos):
// Sumar los elementos de un arreglo de tamaño N es equivalente a sumar el valor en la posición actual 
// (index) con la suma acumulada de los elementos restantes de la izquierda (desde index - 1 hasta 0).
int recursiveSum(const int array[], int index) {
    // Caso base: Cuando el índice llega a 0, significa que hemos recorrido todo el arreglo.
    // Retornamos el primer elemento (array[0]) finalizando la recursión.
    if (index == 0) return array[0];

    // Caso recursivo: Sumamos el elemento actual en la posición 'index' con el resultado de 
    // calcular recursivamente la suma de los elementos anteriores (index - 1).
    // Nota: Esta es una recursión no de cola, por lo que las sumas parciales se resuelven
    // al desapilar la pila de llamadas de C++.
    return array[index] + recursiveSum(array, index - 1);
}


// Calcula la suma de todos los elementos de los arreglos en la lista.
// Concepto Teórico (Procesamiento Híbrido: Iterativo y Recursivo):
// Recorremos la lista secuencialmente de forma iterativa usando iteradores. Para cada nodo de la lista,
// que contiene un 'ArrayWrapper', delegamos la suma de su arreglo dinámico interno a la función 
// recursiva 'recursiveSum'. Acumulamos el resultado parcial en la variable 'finalSum'.
int getListSum(const DrxList<ArrayWrapper>& myList) {
    int finalSum = 0;
    typename DrxList<ArrayWrapper>::Iterator it = myList.first();
    
    // Recorrido secuencial iterativo de la lista enlazada
    while (it != myList.end()) {
        ArrayWrapper* arr = myList.get(it);
        if (arr != nullptr) {
            // Llamada a la lógica recursiva de suma para el arreglo actual
            finalSum += recursiveSum(arr->data, arr->size - 1);
        }
        myList.next(it); // Avanzar al siguiente nodo
    }
    return finalSum;
}


int main() {
    std::cout << "\n\e[0;35m[========= E07-SUMA-RECURSIVA =========]\e[0m\n\n";

    DrxList<ArrayWrapper> randomList;

    ArrayWrapper firstArray;
    firstArray.size = ARRAY_SIZE;
    firstArray.data = new int[ARRAY_SIZE];
    std::cout << "Primer arreglo: [ ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        firstArray.data[i] = nextRandom();
        std::cout << firstArray.data[i] << " ";
    }
    std::cout << "]\n";

    ArrayWrapper secondArray;
    secondArray.size = ARRAY_SIZE;
    secondArray.data = new int[ARRAY_SIZE];
    std::cout << "Segundo arreglo: [ ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        secondArray.data[i] = nextRandom();
        std::cout << secondArray.data[i] << " ";
    }
    std::cout << "]\n";

    randomList.pushBack(firstArray);
    randomList.pushBack(secondArray);

    int finalSum = getListSum(randomList);

    printf("\nSuma total acumulada: \e[0;32m%d\e[0m\n\n", finalSum);

    // Liberar memoria dinámica
    typename DrxList<ArrayWrapper>::Iterator it = randomList.first();
    while (it != randomList.end()) {
        ArrayWrapper* arr = randomList.get(it);
        if (arr != nullptr) {
            delete[] arr->data;
        }
        randomList.next(it);
    }

    return 0;
}
