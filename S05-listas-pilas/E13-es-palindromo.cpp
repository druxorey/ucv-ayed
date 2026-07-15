#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Verifica si la lista es un palíndromo comparando desde los extremos.
// Concepto Teórico (Recorrido Bidireccional en Listas Doblemente Enlazadas):
// En lugar de copiar la lista o usar una estructura auxiliar, aprovechamos que la lista es doblemente enlazada 
// para recorrerla desde ambos extremos simultáneamente: 'start' avanza con 'next' y 'end' retrocede con 'prev'.
// Esto nos da una complejidad temporal de O(n) y una de espacio de O(1).
bool isPalindrome(const DrxList<char>& dataList) {
    typename DrxList<char>::Iterator start = dataList.first();
    typename DrxList<char>::Iterator end = dataList.last();
    
    // Caso base: Una lista vacía es trivialmente un palíndromo.
    if (start == dataList.end()) return true;
    
    // El bucle continúa mientras los iteradores no se encuentren en la misma casilla
    while (start != end) {
        char* startVal = dataList.get(start);
        char* endVal = dataList.get(end);
        
        // Poda temprana: Si en algún momento los valores en extremos simétricos difieren,
        // no es un palíndromo. Retornamos false inmediatamente.
        if (startVal != nullptr && endVal != nullptr && *startVal != *endVal) {
            return false;
        }
        
        dataList.next(start); // Avanzar extremo izquierdo hacia el centro
        
        // Control de cruce para listas de longitud par:
        // Si al avanzar 'start' se alcanza 'end', significa que se han cruzado todos los pares
        // simétricos sin conflicto. Terminamos el bucle.
        if (start == end) break;
        
        dataList.prev(end); // Retroceder extremo derecho hacia el centro
    }
    return true;
}


int main() {
    std::cout << "\n\e[0;35m[========= E13-ES-PALINDROMO =========]\e[0m\n\n";

    char word[100];
    std::cout << "Ingrese una palabra: ";
    if (!(std::cin >> word)) return 1;

    DrxList<char> dataList;
    for (int i = 0; word[i] != '\0'; i++) {
        dataList.pushBack(word[i]);
    }

    std::cout << "Lista de caracteres: [ ";
    typename DrxList<char>::Iterator it = dataList.first();
    while (it != dataList.end()) {
        char* c = dataList.get(it);
        if (c != nullptr) std::cout << *c << " ";
        dataList.next(it);
    }
    std::cout << "]\n";

    if (isPalindrome(dataList)) {
        std::cout << "\n\e[0;32m[RESULTADO] La lista es un palíndromo.\e[0m\n\n";
    } else {
        std::cout << "\n\e[0;31m[RESULTADO] La lista NO es un palíndromo.\e[0m\n\n";
    }

    return 0;
}
