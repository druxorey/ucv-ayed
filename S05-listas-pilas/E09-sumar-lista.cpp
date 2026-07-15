#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Generador congruencial lineal simple para obtener números pseudoaleatorios sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 12345;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 100;
}


// Suma de todos los elementos de la lista.
// Concepto Teórico (Acumulación en Estructuras Lineales):
// Para obtener la suma de los valores en una lista enlazada, realizamos una reducción lineal:
// inicializamos un acumulador en 0 y recorremos la lista de izquierda a derecha agregando 
// el valor de cada nodo. Este proceso tiene una complejidad temporal de O(n) y espacial de O(1),
// al utilizar únicamente variables temporales constantes.
int sumList(const DrxList<int>& myList) {
    int finalSum = 0; // Acumulador (elemento neutro de la suma)
    typename DrxList<int>::Iterator it = myList.first();
    
    // Bucle de recorrido secuencial
    while (it != myList.end()) {
        int* val = myList.get(it);
        if (val != nullptr) {
            finalSum += *val; // Acumulación del valor numérico
        }
        myList.next(it); // Transición al nodo sucesor
    }
    return finalSum;
}


int main() {
    std::cout << "\n\e[0;35m[========= E09-SUMAR-LISTA =========]\e[0m\n\n";

    int listSize;
    std::cout << "Ingrese el tamaño de la lista: ";
    if (!(std::cin >> listSize) || listSize <= 0) return 1;

    DrxList<int> intList;

    std::cout << "\nElementos de la lista: [ ";
    for (int i = 0; i < listSize; i++) {
        int val = nextRandom();
        intList.pushBack(val);
        std::cout << val << " ";
    }
    std::cout << "]\n";

    int finalSum = sumList(intList);
    printf("\nLa suma de todos los elementos de la lista es: \e[0;32m%d\e[0m\n\n", finalSum);

    return 0;
}
