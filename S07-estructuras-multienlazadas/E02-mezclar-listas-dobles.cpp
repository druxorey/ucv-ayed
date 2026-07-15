#include <iostream>

struct DoubleNode {
    int value;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};


// Mezcla in-place de dos listas dobles ordenadas (mergeLists).
// Concepto Teórico (Mezcla Lineal e In-Place de Listas Dobles / Merge):
// Consiste en fusionar dos secuencias ya ordenadas L1 y L2 en una única secuencia ordenada,
// reutilizando los nodos existentes y modificando sus punteros 'next' y 'prev' para evitar
// la asignación de nueva memoria (O(1) de espacio auxiliar).
// - Comparamos los valores al frente de L1 y L2, enlazando el menor a la cola de la lista mezclada.
// - Puesto que es una lista doble, al establecer 'next' de 'current' a un nodo 'X', debemos
//   asegurar que el puntero anterior 'prev' de 'X' apunte a 'current' (enlace bidireccional).
// - Cuando una lista se vacía, la sublista restante de la otra se concatena directamente.
DoubleNode* mergeLists(DoubleNode* L1, DoubleNode* L2) {
    // Casos base: si una de las dos listas es nula, el resultado es la otra lista
    if (L1 == nullptr) return L2;
    if (L2 == nullptr) return L1;

    DoubleNode* head = nullptr;    // Cabeza de la lista mezclada final
    DoubleNode* current = nullptr; // Cursor para construir la secuencia

    // 1. Inicialización de la cabeza (fijar el elemento menor inicial)
    if (L1->value <= L2->value) {
        head = L1;
        L1 = L1->next;
    } else {
        head = L2;
        L2 = L2->next;
    }
    current = head;
    current->prev = nullptr; // El primer nodo de la lista doble no tiene predecesor

    // 2. Mezcla de elementos (recorrido alterno en tiempo lineal O(N + M))
    while (L1 != nullptr && L2 != nullptr) {
        if (L1->value <= L2->value) {
            current->next = L1; // Re-enlazar adelante
            L1->prev = current; // Re-enlazar atrás (enlace doble)
            L1 = L1->next;      // Avanzar en la lista L1
        } else {
            current->next = L2; // Re-enlazar adelante
            L2->prev = current; // Re-enlazar atrás (enlace doble)
            L2 = L2->next;      // Avanzar en la lista L2
        }
        current = current->next; // Mover el cursor de inserción
    }

    // 3. Conexión del remanente:
    // Si una lista terminó antes, adjuntamos toda la cola restante de la otra lista,
    // que por definición ya está ordenada.
    if (L1 != nullptr) {
        current->next = L1;
        L1->prev = current;
    } else if (L2 != nullptr) {
        current->next = L2;
        L2->prev = current;
    }

    return head;
}


void displayList(DoubleNode* head) {
    std::cout << "[ ";
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << "]\n";
}


int main() {
    std::cout << "\n\e[0;35m[========= E02-MEZCLAR-LISTAS-DOBLES =========]\e[0m\n\n";

    // L1: 10 <-> 30 <-> 50
    DoubleNode* L1 = new DoubleNode(10);
    L1->next = new DoubleNode(30);
    L1->next->prev = L1;
    L1->next->next = new DoubleNode(50);
    L1->next->next->prev = L1->next;

    // L2: 20 <-> 40 <-> 60
    DoubleNode* L2 = new DoubleNode(20);
    L2->next = new DoubleNode(40);
    L2->next->prev = L2;
    L2->next->next = new DoubleNode(60);
    L2->next->next->prev = L2->next;

    std::cout << "Lista 1: "; displayList(L1);
    std::cout << "Lista 2: "; displayList(L2);

    DoubleNode* result = mergeLists(L1, L2);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Lista mezclada ordenada: ";
    displayList(result);
    std::cout << "\n";

    // Liberar memoria
    while (result != nullptr) {
        DoubleNode* temp = result->next;
        delete result;
        result = temp;
    }

    return 0;
}
