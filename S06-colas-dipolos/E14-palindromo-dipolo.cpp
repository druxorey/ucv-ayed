#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Abstracción básica de Dipolo usando lista doblemente enlazada (Deque).
template <typename T>
class Deque {
private:
    DrxList<T> list;

public:
    void pushBack(const T& val) {
        list.pushBack(val);
    }


    void popFront() {
        if (!isEmpty()) list.deleteNode(list.first());
    }


    void popBack() {
        if (!isEmpty()) list.deleteNode(list.last());
    }


    T& front() {
        return *list.get(list.first());
    }


    T& back() {
        return *list.get(list.last());
    }


    bool isEmpty() const {
        return list.isEmpty();
    }


    int size() const {
        return list.size();
    }
};


// Verifica si la secuencia almacenada en el dipolo es un palíndromo de forma iterativa y destructiva.
// Concepto Teórico (Detección de Palíndromos mediante Extracción de Extremos en Deques):
// En un Dipolo (Deque), podemos acceder y remover elementos de ambos extremos (frente y dorso) en O(1) tiempo.
// El algoritmo compara el primer carácter (front()) con el último (back()):
// - Si son iguales, removemos ambos extremos (popFront() y popBack()) y repetimos la comparación con los nuevos extremos.
// - Si difieren, abortamos inmediatamente retornando false.
// Este proceso se repite mientras el tamaño del dipolo sea mayor a 1.
// Si el tamaño llega a 1 (impar) o 0 (par) y todas las comparaciones previas fueron exitosas, es un palíndromo.
// Complejidad temporal: O(N) y complejidad espacial: O(1) auxiliar (aunque consume el dipolo de entrada).
bool checkPalindrome(Deque<char>& D) {
    while (D.size() > 1) {
        char firstVal = D.front(); // Obtener el carácter de la izquierda
        char lastVal = D.back();   // Obtener el carácter de la derecha
 
        // Poda temprana: si hay asimetría, no es palíndromo
        if (firstVal != lastVal) {
            return false; 
        }
 
        // Descartar extremos procesados para reducir el dipolo
        D.popFront();
        D.popBack();
    }
    return true; // Se comprobaron todos los pares simétricos
}


int main() {
    std::cout << "\n\e[0;35m[========= E14-PALINDROMO-DIPOLO =========]\e[0m\n\n";

    const char* word = "reconocer";
    std::cout << "Verificando palabra: \"" << word << "\"\n";

    Deque<char> D;
    for (int i = 0; word[i] != '\0'; i++) {
        D.pushBack(word[i]);
    }

    if (checkPalindrome(D)) {
        std::cout << "\n\e[1;32m[RESULTADO]\e[0m La palabra es un palíndromo.\n\n";
    } else {
        std::cout << "\n\e[1;31m[RESULTADO]\e[0m La palabra NO es un palíndromo.\n\n";
    }

    return 0;
}
