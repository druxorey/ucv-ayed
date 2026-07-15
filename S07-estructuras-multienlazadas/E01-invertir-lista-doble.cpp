#include <iostream>

// Estructura de Nodo Doble local didáctico
struct DoubleNode {
    int value;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};


// Invierte los punteros de una lista doble en una sola pasada en O(N).
// Concepto Teórico (Inversión in-place de Enlaces Dobles):
// En una lista doblemente enlazada, cada nodo tiene dos punteros: 'next' (hacia el sucesor) y 'prev' (hacia el predecesor).
// Para invertir la lista físicamente sin alterar los valores de información de los nodos:
// 1. Recorremos la lista intercambiando para cada nodo sus punteros 'next' y 'prev'.
// 2. Al intercambiar, el que era sucesor se vuelve predecesor y viceversa.
// 3. Para avanzar en la lista, usamos 'current = current->prev' (ya que el puntero 'prev' ahora apunta al siguiente nodo original).
// 4. Al finalizar el bucle, re-asignamos la cabeza ('head') al nodo que era el último de la lista original.
void reverseDoubleList(DoubleNode*& head) {
    if (head == nullptr) return; // Caso base: Lista vacía

    DoubleNode* current = head;
    DoubleNode* temp = nullptr; // Puntero temporal para el intercambio de enlaces

    // Bucle de intercambio de enlaces para todos los nodos
    while (current != nullptr) {
        temp = current->prev; // Guardar el predecesor antiguo
        
        // Intercambiar punteros
        current->prev = current->next;
        current->next = temp;
        
        // Avanzar al siguiente nodo original (que ahora está referenciado por 'prev')
        current = current->prev;
    }

    // Actualización de la cabeza:
    // Al terminar, 'temp' apunta al penúltimo elemento original. 
    // Por lo tanto, 'temp->prev' apunta al último elemento original, que pasa a ser la nueva cabeza.
    if (temp != nullptr) {
        head = temp->prev;
    }
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
    std::cout << "\n\e[0;35m[========= E01-INVERTIR-LISTA-DOBLE =========]\e[0m\n\n";

    // Crear lista: 10 <-> 20 <-> 30 <-> 40
    DoubleNode* head = new DoubleNode(10);
    head->next = new DoubleNode(20);
    head->next->prev = head;
    head->next->next = new DoubleNode(30);
    head->next->next->prev = head->next;
    head->next->next->next = new DoubleNode(40);
    head->next->next->next->prev = head->next->next;

    std::cout << "Lista inicial: ";
    displayList(head);

    // Invertir enlaces físicamente
    reverseDoubleList(head);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Lista invertida: ";
    displayList(head);
    std::cout << "\n";

    // Liberar memoria
    while (head != nullptr) {
        DoubleNode* temp = head->next;
        delete head;
        head = temp;
    }

    return 0;
}
