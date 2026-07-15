#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Mezcla dos listas ordenadas ascendentemente manteniendo el orden.
// Mezcla dos listas ordenadas ascendentemente manteniendo el orden.
// Concepto Teórico (Algoritmo de Unión de Colecciones Ordenadas / Merge):
// Dadas dos listas ordenadas, las recorremos simultáneamente usando dos iteradores ('it1' y 'it2').
// En cada iteración, comparamos los elementos actuales apuntados por ambos iteradores. Insertamos el menor
// de ellos en la lista resultante 'mergedList' y avanzamos únicamente el iterador que correspondía al menor.
// Esto permite mezclar ambas listas en un tiempo lineal de O(N + M), siendo N y M sus longitudes.
void mixLists(const DrxList<int>& firstList, const DrxList<int>& secondList, DrxList<int>& mergedList) {
    typename DrxList<int>::Iterator it1 = firstList.first();
    typename DrxList<int>::Iterator it2 = secondList.first();

    // Bucle principal: Se mantiene mientras ambas listas tengan elementos pendientes por procesar.
    while (it1 != firstList.end() && it2 != secondList.end()) {
        int* val1 = firstList.get(it1);
        int* val2 = secondList.get(it2);
        if (val1 != nullptr && val2 != nullptr) {
            // Comparación de relevancia para el orden ascendente:
            // Insertamos el más pequeño de los dos y avanzamos su respectivo iterador.
            if (*val1 <= *val2) {
                mergedList.pushBack(*val1);
                firstList.next(it1);
            } else {
                mergedList.pushBack(*val2);
                secondList.next(it2);
            }
        }
    }

    // Agregar elementos restantes de la primera lista (si la segunda lista se agotó primero).
    // Dado que la lista ya está ordenada, simplemente adjuntamos el resto de elementos al final.
    while (it1 != firstList.end()) {
        int* val = firstList.get(it1);
        if (val != nullptr) {
            mergedList.pushBack(*val);
        }
        firstList.next(it1);
    }

    // Agregar elementos restantes de la segunda lista (si la primera lista se agotó primero).
    while (it2 != secondList.end()) {
        int* val = secondList.get(it2);
        if (val != nullptr) {
            mergedList.pushBack(*val);
        }
        secondList.next(it2);
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E05-MEZCLAR-LISTAS =========]\e[0m\n\n";

    int listSize;
    std::cout << "Ingrese el tamaño de las listas: ";
    if (!(std::cin >> listSize) || listSize <= 0) return 1;

    DrxList<int> firstList, secondList;
    
    // Rellenar listas de ejemplo ordenadas
    for (int i = 0; i < listSize; i++) {
        firstList.pushBack(i * 2);
        secondList.pushBack(i * 2 + 1);
    }

    std::cout << "\n\e[0;33mPrimera Lista\e[0m: [ ";
    typename DrxList<int>::Iterator it = firstList.first();
    while (it != firstList.end()) {
        int* val = firstList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        firstList.next(it);
    }
    std::cout << "]\n";

    std::cout << "\e[0;33mSegunda Lista\e[0m: [ ";
    it = secondList.first();
    while (it != secondList.end()) {
        int* val = secondList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        secondList.next(it);
    }
    std::cout << "]\n";

    DrxList<int> mergedList;
    mixLists(firstList, secondList, mergedList);
    
    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Lista Mezclada Ordenada: [ ";
    it = mergedList.first();
    while (it != mergedList.end()) {
        int* val = mergedList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        mergedList.next(it);
    }
    std::cout << "]\n\n";

    return 0;
}
