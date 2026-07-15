#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"
#include "../S99-implementaciones/drxqueue.hpp"

// Función que verifica si la secuencia de caracteres en la pila es palíndromo.
// Concepto Teórico (Dualidad LIFO/FIFO para detección de Palíndromos):
// Al desapilar la pila original 'temp', los caracteres salen en orden inverso (de final a inicio).
// - Al insertarlos en una Cola Q (FIFO), al recuperarlos saldrán en ese mismo orden inverso (ej. "n", "a", "n" de "nan").
// - Al insertarlos en otra Pila P_inv (LIFO), se invierte el orden por segunda vez, resultando en el orden directo.
// Finalmente, al comparar secuencialmente el frente de la cola (orden inverso) con el tope de la nueva pila 
// (orden directo), comprobamos si la palabra se lee igual en ambos sentidos.
bool isPalindrome(DrxStack<char> P) {
    DrxQueue<char> Q;      // Cola FIFO (mantiene el orden de desapilado)
    DrxStack<char> P_inv;  // Pila LIFO (invierte el orden de desapilado)

    DrxStack<char> temp = P;

    // Desapilar 'temp' y distribuir los caracteres
    while (!temp.isEmpty()) {
        char character = temp.top();
        temp.pop();

        Q.push(character);      // FIFO: el primer carácter insertado saldrá primero
        P_inv.push(character);  // LIFO: el último carácter insertado saldrá primero
    }

    // Comparar elemento por elemento
    // Si la palabra es un palíndromo, la cola (recorrido normal de atrás hacia adelante)
    // y la pila invertida (recorrido de adelante hacia atrás) deben coincidir exactamente.
    while (!Q.isEmpty() && !P_inv.isEmpty()) {
        char c1 = Q.front();
        Q.pop();

        char c2 = P_inv.top();
        P_inv.pop();

        // Poda temprana: Si hay un carácter que no coincide, la secuencia no es un palíndromo
        if (c1 != c2) {
            return false;
        }
    }

    return true; // Todos los caracteres coincidieron
}


int main() {
    std::cout << "\n\e[0;35m[========= E18-PALINDROMO-PILA =========]\e[0m\n\n";

    char word[100];
    std::cout << "Introduce una palabra para verificar: ";
    if (!(std::cin >> word)) return 1;

    DrxStack<char> letterStack;
    for (int i = 0; word[i] != '\0'; i++) {
        letterStack.push(word[i]);
    }

    if (isPalindrome(letterStack)) {
        printf("\n\e[1;32m[RESULTADO]\e[0m La secuencia en la pila \e[1;33m\"%s\"\e[0m es un palíndromo.\n\n", word);
    } else {
        printf("\n\e[1;31m[RESULTADO]\e[0m La secuencia en la pila \e[1;33m\"%s\"\e[0m NO es un palíndromo.\n\n", word);
    }

    return 0;
}
