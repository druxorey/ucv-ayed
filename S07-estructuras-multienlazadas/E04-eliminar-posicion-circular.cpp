#include <iostream>

struct DoubleNode {
    int value;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};


// Elimina el nodo en la posición lógica P (1-indexed) y el nodo en la posición P + d en un anillo circular.
// Concepto Teórico (Desconexión de Nodos y Gestión de Punteros en Anillos Circulares):
// Al eliminar nodos en listas circulares dobles, debemos evitar romper el ciclo y manejar con cuidado
// el puntero de acceso 'head'.
// Lógica paso a paso:
// 1. Localización previa: Antes de borrar el nodo en P ('nodeP'), calculamos y resguardamos la dirección
//    del nodo en P + d ('nodePD') usando el puntero 'nextCurrent'. Esto evita perder la referencia si 'nodeP'
//    formaba parte de la ruta de salto.
// 2. Extracción de nodeP:
//    - Si 'nodeP' es la cabeza actual ('head'), actualizamos 'head' al nodo sucesor ('head->next') para no perder la referencia a la lista.
//    - Desviamos los enlaces: el sucesor apunta al predecesor ('nodeP->next->prev = nodeP->prev') y el predecesor
//      apunta al sucesor ('nodeP->prev->next = nodeP->next').
//    - Liberamos la memoria física.
// 3. Extracción de nodePD: Repetimos el desvío de punteros con el nodo resguardado 'nodePD'.
void removeRingNodes(DoubleNode*& head, int P, int d) {
    if (head == nullptr || P < 1 || d < 0) return;

    DoubleNode* current = head;

    // 1. Navegar hasta la posición lógica P (1-indexed)
    for (int i = 1; i < P; i++) {
        current = current->next;
    }

    DoubleNode* nodeP = current;
    std::cout << "Eliminando nodo en posición P (valor " << nodeP->value << ")\n";

    // Resguardar la posición P + d avanzando a partir del sucesor de nodeP.
    // Esto garantiza que localicemos el segundo nodo antes de alterar la estructura física del anillo.
    DoubleNode* nextCurrent = nodeP->next;
    for (int i = 0; i < d; i++) {
        nextCurrent = nextCurrent->next;
    }
    
    // Si eliminamos la cabeza, desplazamos el puntero 'head' al sucesor
    if (nodeP == head) {
        head = head->next;
    }
    // Desvío de punteros (bypass) de los nodos contiguos a nodeP
    nodeP->prev->next = nodeP->next;
    nodeP->next->prev = nodeP->prev;
    delete nodeP; // Liberar la memoria del primer nodo seleccionado

    // 2. Eliminar el nodo en la posición P + d (referenciado por nextCurrent)
    DoubleNode* nodePD = nextCurrent;
    std::cout << "Eliminando nodo en posición P + d (valor " << nodePD->value << ")\n";

    // Si este segundo nodo coincide con la cabeza, actualizamos 'head' nuevamente
    if (nodePD == head) {
        head = head->next;
    }
    // Desvío de punteros (bypass) de los nodos contiguos a nodePD
    nodePD->prev->next = nodePD->next;
    nodePD->next->prev = nodePD->prev;
    delete nodePD; // Liberar la memoria del segundo nodo seleccionado
}


void displayCircularList(DoubleNode* head, int limit) {
    if (head == nullptr) {
        std::cout << "[ vacía ]\n";
        return;
    }
    DoubleNode* current = head;
    std::cout << "[ ";
    for (int i = 0; i < limit; i++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "... ]\n";
}


int main() {
    std::cout << "\n\e[0;35m[========= E04-ELIMINAR-POSICION-CIRCULAR =========]\e[0m\n\n";

    // Crear lista circular doble de 5 elementos: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 10
    DoubleNode* n1 = new DoubleNode(10);
    DoubleNode* n2 = new DoubleNode(20);
    DoubleNode* n3 = new DoubleNode(30);
    DoubleNode* n4 = new DoubleNode(40);
    DoubleNode* n5 = new DoubleNode(50);

    n1->next = n2; n1->prev = n5;
    n2->next = n3; n2->prev = n1;
    n3->next = n4; n3->prev = n2;
    n4->next = n5; n4->prev = n3;
    n5->next = n1; n5->prev = n4;

    std::cout << "Lista circular inicial: ";
    displayCircularList(n1, 6);

    int posP = 2; 
    int desD = 2; 

    std::cout << "\nEliminando en posición P = " << posP << " y P + d = " << (posP + desD) << "...\n";
    removeRingNodes(n1, posP, desD);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Lista circular resultante: ";
    displayCircularList(n1, 4);
    std::cout << "\n";

    if (n1 != nullptr) {
        n1->prev->next = nullptr;
        while (n1 != nullptr) {
            DoubleNode* temp = n1->next;
            delete n1;
            n1 = temp;
        }
    }

    return 0;
}
