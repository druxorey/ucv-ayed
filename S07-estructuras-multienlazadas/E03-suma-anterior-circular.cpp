#include <iostream>

struct DoubleNode {
    int value;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};


// Suma el valor de los n elementos anteriores secuencialmente al nodo dado.
// Concepto Teórico (Navegación Circular Inversa en Listas Dobles):
// En una lista doblemente enlazada circular, la estructura no posee principio ni fin lógicos 
// (no hay punteros nullptr). El predecesor de la cabeza es la cola de la lista.
// Para sumar los n elementos anteriores a un nodo dado:
// - Iniciamos el recorrido en 'node->prev' (el predecesor inmediato).
// - Avanzamos hacia atrás usando 'predecessor = predecessor->prev' exactamente 'n' veces.
// - Al ser circular, si 'n' supera el tamaño de la lista, el algoritmo dará vueltas alrededor del 
//   anillo repitiendo elementos de forma natural, lo cual es correcto bajo la aritmética del anillo.
// Complejidad temporal: O(n) y complejidad de espacio: O(1).
void sumPredecessorsCircular(DoubleNode* node, int n) {
    if (node == nullptr || n <= 0) return;

    DoubleNode* predecessor = node->prev; // Apuntar al primer predecesor inmediato
    int accumulatedSum = 0;

    // Bucle para retroceder n pasos a través de los enlaces 'prev'
    for (int i = 0; i < n; i++) {
        accumulatedSum += predecessor->value; // Acumular el valor del nodo
        predecessor = predecessor->prev;     // Retroceder secuencialmente en el anillo
    }

    std::cout << "Sumando los " << n << " anteriores. Total acumulado a sumar: " << accumulatedSum << "\n";
    node->value += accumulatedSum; // Sumar el total acumulado al valor del nodo original
}


void displayCircularList(DoubleNode* head, int limit) {
    if (head == nullptr) return;
    DoubleNode* current = head;
    std::cout << "[ ";
    for (int i = 0; i < limit; i++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "... (circular) ]\n";
}


int main() {
    std::cout << "\n\e[0;35m[========= E03-SUMA-ANTERIOR-CIRCULAR =========]\e[0m\n\n";

    // Crear lista circular doble de 4 elementos: 5 <-> 10 <-> 15 <-> 20 <-> 5
    DoubleNode* n1 = new DoubleNode(5);
    DoubleNode* n2 = new DoubleNode(10);
    DoubleNode* n3 = new DoubleNode(15);
    DoubleNode* n4 = new DoubleNode(20);

    n1->next = n2; n1->prev = n4;
    n2->next = n3; n2->prev = n1;
    n3->next = n4; n3->prev = n2;
    n4->next = n1; n4->prev = n3;

    std::cout << "Lista circular doble inicial: ";
    displayCircularList(n1, 6);

    int n = 2;
    std::cout << "\nAplicando suma circular sobre el nodo con valor " << n3->value << "...\n";
    sumPredecessorsCircular(n3, n);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Lista después de la suma (esperado en n3: 30): ";
    displayCircularList(n1, 6);
    std::cout << "\n";

    // Romper enlaces circulares para liberar memoria de forma segura
    n4->next = nullptr;
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}
