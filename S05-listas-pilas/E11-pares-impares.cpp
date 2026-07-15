#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Generador congruencial lineal simple para obtener números pseudoaleatorios sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 12345;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 100;
}


// Clasifica los elementos de la lista en listas de pares e impares.
// Concepto Teórico (Clasificación Lineal e Inserción Dinámica):
// Recorremos la lista de entrada en tiempo O(n) y para cada nodo evaluamos su paridad 
// mediante la operación módulo (*value % 2 == 0). Según el resultado de la condición, 
// agregamos el elemento al final (pushBack) de 'evenList' o 'oddList'. 
// Este procedimiento demuestra la manipulación dinámica de colecciones para filtrado de datos.
void getEvenOdd(const DrxList<int>& initialList, DrxList<int>& oddList, DrxList<int>& evenList) {
    typename DrxList<int>::Iterator it = initialList.first();
    
    // Recorrido de un único paso
    while (it != initialList.end()) {
        int* value = initialList.get(it);
        if (value != nullptr) {
            // Clasificación por paridad aritmética
            if (*value % 2 == 0) {
                evenList.pushBack(*value); // Inserción en la lista de pares
            } else {
                oddList.pushBack(*value);  // Inserción en la lista de impares
            }
        }
        initialList.next(it); // Avanzar iterador
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E11-PARES-E-IMPARES =========]\e[0m\n\n";

    int listSize;
    std::cout << "Ingrese el tamaño de la lista: ";
    if (!(std::cin >> listSize) || listSize <= 0) return 1;

    DrxList<int> initialList, oddList, evenList;

    std::cout << "\n\e[0;33mLista Inicial\e[0m: [ ";
    for (int i = 0; i < listSize; i++) {
        int val = nextRandom();
        initialList.pushBack(val);
        std::cout << val << " ";
    }
    std::cout << "]\n";

    getEvenOdd(initialList, oddList, evenList);

    std::cout << "\n\e[0;33mLista de Pares\e[0m:   [ ";
    typename DrxList<int>::Iterator it = evenList.first();
    while (it != evenList.end()) {
        int* val = evenList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        evenList.next(it);
    }
    std::cout << "]\n";

    std::cout << "\e[0;33mLista de Impares\e[0m: [ ";
    it = oddList.first();
    while (it != oddList.end()) {
        int* val = oddList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        oddList.next(it);
    }
    std::cout << "]\n\n";

    return 0;
}
