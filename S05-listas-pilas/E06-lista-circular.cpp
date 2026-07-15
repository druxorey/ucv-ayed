#include <iostream>
#include "../S99-implementaciones/drxring.hpp"

// Generador congruencial lineal simple para obtener letras pseudoaleatorias sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 99999;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 26;
}


// Imprime m valores a partir de la posición inicial 'start' (1-indexed) de forma circular.
// Concepto Teórico (Estructuras Circulares y Aritmética Modular):
// Una lista circular (anillo) no posee un nodo con puntero nulo a fin de lista; en su lugar,
// el último nodo enlaza con el primero. Por lo tanto, el recorrido secuencial puede ser infinito.
// Para relacionar el número de avance continuo con los índices lógicos, se utiliza aritmética modular 
// con respecto al tamaño de la lista: index_logico = (desplazamiento) % tamaño.
void printCircularList(DrxRing<char>& list, int start, int count, int listSize) {
    // Avanzar el puntero interno del anillo hasta la casilla inicial especificada por el usuario.
    // Al ser 1-indexed, avanzamos 'start - 1' veces.
    for (int i = 0; i < start - 1; i++) {
        list.next();
    }

    // Imprimir 'count' elementos de manera consecutiva.
    // Gracias a la naturaleza circular de la estructura, si 'count' supera el tamaño de la lista,
    // el método 'list.next()' continuará recorriendo los mismos elementos repetidamente sin desbordar.
    for (int i = 0; i < count; i++) {
        char val = list.next(); // Avanzar un nodo en el anillo y obtener su valor
        
        // Mapeo del índice lógico en el rango [0, listSize-1] para fines informativos del usuario
        int targetIndex = (start - 1 + i) % listSize;
        std::cout << "Paso " << (i + 1) << " (Posición " << (targetIndex + 1) << "): [" << val << "]\n";
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E06-LISTA-CIRCULAR =========]\e[0m\n\n";

    int listSize, start, count;

    std::cout << "Ingrese el tamaño de la lista circular: ";
    if (!(std::cin >> listSize) || listSize <= 0) return 1;

    std::cout << "Ingrese la posición inicial (1 a N): ";
    if (!(std::cin >> start) || start < 1 || start > listSize) return 1;

    std::cout << "Ingrese la cantidad de caracteres a imprimir: ";
    if (!(std::cin >> count) || count < 0) return 1;

    DrxRing<char> circularList;

    std::cout << "\nLista circular generada: [ ";
    for (int i = 0; i < listSize; i++) {
        char ch = 'a' + nextRandom();
        circularList.add(ch);
        std::cout << ch << " ";
    }
    std::cout << "]\n";

    std::cout << "\n\e[0;33mImprimiendo " << count << " elementos a partir de la posición " << start << "\e[0m:\n";
    printCircularList(circularList, start, count, listSize);
    std::cout << "\n";

    return 0;
}
