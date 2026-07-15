#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Invierte de forma iterativa y en sitio (in-place) una lista enlazada simple.
// Concepto Teórico (Inversión por Desplazamiento de Nodos de Atrás hacia Adelante):
// Este algoritmo realiza la inversión in-place sin requerir estructuras auxiliares externas.
// Su funcionamiento se basa en la extracción repetida del último elemento de la sublista no invertida
// (el elemento en la posición size - 1 - i) y su posterior reinserción al final de la lista (pushBack).
// - En cada paso, el elemento seleccionado se traslada al final, y luego se destruye su nodo original.
// - Conforme 'i' aumenta, la "frontera" de elementos originales sin invertir retrocede hacia el inicio.
// Complejidad temporal: O(n^2) debido al doble recorrido iterativo (para llegar a la posición deseada en cada paso).
// Complejidad espacial: O(1) ya que las modificaciones se realizan directamente sobre los nodos existentes.
void iterativeInverse(DrxList<int>& list) {
    int size = list.size();
    for (int i = 0; i < size; i++) {
        typename DrxList<int>::Iterator it = list.first();
        
        // Desplazarse hasta el último elemento de la sublista no invertida actual (size - 1 - i)
        for (int j = 1; j < size - i; j++) {
            list.next(it);
        }
        
        int* val = list.get(it);
        if (val != nullptr) {
            list.pushBack(*val); // Clonar el valor al final de la lista (creando el nuevo orden invertido)
            list.deleteNode(it); // Eliminar el nodo de su posición original antigua
        }
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E15-INVERTIR-LISTA =========]\e[0m\n\n";

    int listSize;
    std::cout << "Ingrese el tamaño de la lista: ";
    if (!(std::cin >> listSize) || listSize <= 0) return 1;

    DrxList<int> myList;
    for (int i = 1; i <= listSize; i++) {
        myList.pushBack(i);
    }

    std::cout << "\n\e[0;33mLista Normal\e[0m:  [ ";
    typename DrxList<int>::Iterator it = myList.first();
    while (it != myList.end()) {
        int* val = myList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        myList.next(it);
    }
    std::cout << "]\n";

    iterativeInverse(myList);

    std::cout << "\e[0;33mLista Invertida\e[0m: [ ";
    it = myList.first();
    while (it != myList.end()) {
        int* val = myList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        myList.next(it);
    }
    std::cout << "]\n\n";

    return 0;
}
