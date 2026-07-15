#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Función genérica que imprime los elementos de la lista.
// Concepto Teórico (Patrón Iterador en Colecciones Enlazadas):
// El patrón Iterador abstrae el recorrido secuencial de los elementos de una colección (como una lista enlazada)
// sin exponer los detalles de su estructura física interna (ej. punteros 'next' y nodos internos).
// - L.first() devuelve el iterador apuntando al primer nodo.
// - L.end() devuelve un iterador centinela que representa el final de la colección (fuera de límites).
// - L.next(it) actualiza el iterador para apuntar al nodo sucesor.
// - L.get(it) devuelve un puntero al dato almacenado en el nodo actual.
template <typename T>
void printList(const DrxList<T>& L) {
    std::cout << "Contenido de la lista: \e[1;34m[\e[0m";
    
    typename DrxList<T>::Iterator it = L.first();
    
    // Recorrido secuencial de complejidad temporal O(n)
    while (it != L.end()) {
        T* value = L.get(it);
        if (value != nullptr) {
            std::cout << *value;
        }
        
        L.next(it); // Avanzar el iterador
        
        // Estética: Agregar coma para separar elementos si no es el último nodo de la lista
        if (it != L.end()) {
            std::cout << ", ";
        }
    }
    
    std::cout << "\e[1;34m]\e[0m\n";
}

int main() {
    std::cout << "\n\e[0;35m[========= E08-IMPRIMIR-LISTA =========]\e[0m\n\n";

    DrxList<int> myList;

    std::cout << "Insertando elementos: 10, 20, 30, 40, 50...\n";
    myList.pushBack(10);
    myList.pushBack(20);
    myList.pushBack(30);
    myList.pushBack(40);
    myList.pushBack(50);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m ";
    printList(myList);
    std::cout << "\n";

    return 0;
}
