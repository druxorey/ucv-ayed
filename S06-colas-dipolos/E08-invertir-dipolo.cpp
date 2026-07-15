#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Abstracción de un Dipolo (Bicola o Deque) de bajo nivel.
template <typename T>
class Deque {
private:
    DrxList<T> list;

public:
    void pushFront(const T& val) {
        list.pushFront(val);
    }


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


// Invierte el contenido del dipolo original D1 en un nuevo dipolo D2.
// Concepto Teórico (Inversión mediante Operaciones de Extremo Doble - Deque):
// Un Dipolo (Bicola o Deque) permite insertar y eliminar por ambos extremos (frente y dorso) en O(1).
// Para invertir D1 en D2:
// - Extraemos repetidamente el elemento del dorso de D1 (back) y lo eliminamos (popBack).
// - Insertamos dicho elemento en el dorso de D2 (pushBack).
// De este modo, los elementos ingresan en D2 en el orden inverso respecto a D1.
// Complejidad temporal: O(N) y complejidad espacial: O(N) para la nueva bicola.
Deque<char> reverseWord(Deque<char>& D1) {
    Deque<char> D2;
    // Vaciar D1 desde el dorso y rellenar D2 por el dorso
    while (!D1.isEmpty()) {
        D2.pushBack(D1.back()); // Obtener el último carácter actual
        D1.popBack();           // Descartarlo de D1
    }
    return D2; // Retornar el dipolo con los caracteres invertidos
}


int main() {
    std::cout << "\n\e[0;35m[========= E08-INVERTIR-DIPOLO =========]\e[0m\n\n";

    const char* word = "Estructuras";
    std::cout << "Palabra original: " << word << "\n";

    Deque<char> D1;
    for (int i = 0; word[i] != '\0'; i++) {
        D1.pushBack(word[i]);
    }

    Deque<char> D2 = reverseWord(D1);

    std::cout << "\e[1;32m[RESULTADO]\e[0m Palabra invertida en el nuevo dipolo: ";
    while (!D2.isEmpty()) {
        std::cout << D2.front();
        D2.popFront();
    }
    std::cout << "\n\n";

    return 0;
}
