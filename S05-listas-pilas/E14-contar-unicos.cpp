#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

struct ElementValue {
    int number;
    int occurrences = 0;
};


// Generador congruencial lineal simple para obtener números pseudoaleatorios sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 12345;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 10;
}


// Obtiene la lista de elementos únicos con su conteo de ocurrencias.
// Obtiene la lista de elementos únicos con su conteo de ocurrencias.
// Concepto Teórico (Mapeo de Frecuencia con Listas Enlazadas):
// Para contar ocurrencias de elementos sin estructuras asociativas nativas (como std::map),
// construimos una segunda lista 'uniqueList' de estructuras 'ElementValue'.
// Para cada elemento de la lista original, buscamos linealmente si ya existe en la lista de únicos.
// Si existe, incrementamos su contador; si no, lo insertamos como nuevo elemento con frecuencia 1.
// Complejidad temporal: O(N * U) donde N es el tamaño de la lista y U es la cantidad de elementos únicos.
void getOccurrences(const DrxList<int>& list, DrxList<ElementValue>& uniqueList) {
    if (list.isEmpty()) return; // Caso base: Lista vacía no tiene elementos

    typename DrxList<int>::Iterator it = list.first();
    while (it != list.end()) {
        int* number = list.get(it);
        if (number != nullptr) {
            bool isUnique = true;
            typename DrxList<ElementValue>::Iterator uIt = uniqueList.first();
            
            // Búsqueda secuencial en la lista de elementos únicos ya identificados
            while (uIt != uniqueList.end()) {
                ElementValue* val = uniqueList.get(uIt);
                // Si el número ya fue registrado previamente en 'uniqueList'
                if (val != nullptr && val->number == *number) {
                    isUnique = false;
                    val->occurrences++; // Incrementar frecuencia (colisión encontrada)
                    break; // Poda del escaneo interno, no puede haber duplicados en uniqueList
                }
                uniqueList.next(uIt);
            }

            // Si el número no se encontró en la lista de únicos, es una nueva clave
            if (isUnique) {
                ElementValue newVal;
                newVal.number = *number;
                newVal.occurrences = 1; // Inicializar frecuencia
                uniqueList.pushBack(newVal); // Agregar nuevo registro al final
            }
        }
        list.next(it); // Avanzar al siguiente número de la lista original
    }
}


// Imprime los elementos únicos y sus ocurrencias.
void printOccurrencesList(const DrxList<ElementValue>& list) {
    int index = 1;
    typename DrxList<ElementValue>::Iterator it = list.first();
    while (it != list.end()) {
        ElementValue* element = list.get(it);
        if (element != nullptr) {
            printf("Nodo %d: [Número: %d, Ocurrencias: %d]\n", index, element->number, element->occurrences);
        }
        index++;
        list.next(it);
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E14-CONTAR-UNICOS =========]\e[0m\n\n";

    int listSize;
    std::cout << "Ingrese el tamaño de la lista: ";
    if (!(std::cin >> listSize) || listSize <= 0) return 1;

    DrxList<int> messyList;

    std::cout << "\n\e[0;33mLista Desordenada\e[0m: [ ";
    for (int i = 0; i < listSize; i++) {
        int val = nextRandom();
        messyList.pushBack(val);
        std::cout << val << " ";
    }
    std::cout << "]\n";

    DrxList<ElementValue> uniqueList;
    getOccurrences(messyList, uniqueList);

    printf("\n\e[0;33mConteo de Únicos\e[0m:\n");
    printOccurrencesList(uniqueList);
    std::cout << "\n";

    return 0;
}
