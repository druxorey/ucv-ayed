#include <iostream>
#include "../S99-implementations/drxtree.hpp"

// Cuenta el número de nodos del árbol binario
int countNodes(DrxArbinNode<int>* node) {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Verifica si el árbol binario es completo mapeando índices lógicos (0-indexed).
// Concepto Teórico (Validación de Completitud mediante Índices Lógicos):
// Para comprobar si un árbol es completo (relleno de izquierda a derecha en todos sus niveles):
// 1. Asignamos un índice lógico a cada nodo: la raíz tiene índice 0.
// 2. Si un nodo tiene índice 'index', su hijo izquierdo se ubicará en '2 * index + 1'
//    y su hijo derecho en '2 * index + 2'.
// 3. Contamos la cantidad total de nodos en el árbol ('numNodes').
// 4. Si el índice lógico asignado a cualquier nodo es mayor o igual que 'numNodes', 
//    significa que hay un vacío a su izquierda en los niveles del árbol. Por lo tanto, el árbol NO es completo.
// Complejidad temporal: O(N) y de espacio: O(H).
bool isCompleteTree(DrxArbinNode<int>* node, int index, int numNodes) {
    if (node == nullptr) return true; // Caso base: árbol vacío es completo

    // Si el índice del nodo excede o iguala el número total de nodos, viola la completitud
    if (index >= numNodes) return false;

    // Verificar recursivamente para los hijos izquierdo y derecho recalculando sus índices lógicos
    return isCompleteTree(node->left, 2 * index + 1, numNodes) &&
           isCompleteTree(node->right, 2 * index + 2, numNodes);
}

// Comprueba recursivamente la propiedad de orden de Max-Heap (padre >= hijos).
// Concepto Teórico (Propiedad de Orden de Max-Heap):
// Para que un árbol mantenga la propiedad de Max-Heap, el valor de todo nodo padre debe ser 
// mayor o igual que el valor de sus hijos directos.
// - Evaluamos si el hijo izquierdo existe y si su valor supera al del padre (violación).
// - Evaluamos si el hijo derecho existe y si su valor supera al del padre (violación).
// - Si el nodo actual es válido, validamos recursivamente sus subárboles.
bool isMaxHeapOrder(DrxArbinNode<int>* node) {
    if (node == nullptr) return true; // Caso base: Nodo nulo mantiene la propiedad

    // Comprobación con el hijo izquierdo
    if (node->left != nullptr && node->left->value > node->value) {
        return false;
    }
    // Comprobación con el hijo derecho
    if (node->right != nullptr && node->right->value > node->value) {
        return false;
    }

    // El orden debe cumplirse en todo el subárbol
    return isMaxHeapOrder(node->left) && isMaxHeapOrder(node->right);
}

// Determina si un árbol binario dado es un Montículo Máximo (Max-Heap) válido.
// Concepto Teórico (Condiciones de Validez de un Montículo):
// Un árbol binario es un montículo máximo válido si y solo si cumple simultáneamente:
// 1. Propiedad de Forma: Es un árbol binario completo ('isCompleteTree').
// 2. Propiedad de Orden: Satisface la prioridad máxima del padre sobre sus hijos ('isMaxHeapOrder').
bool isMaxHeap(DrxArbinNode<int>* root) {
    if (root == nullptr) return true;

    int totalNodes = countNodes(root); // Contar el total de nodos del árbol (N)
    
    // El árbol debe ser completo y cumplir con el orden descendente de prioridad
    return isCompleteTree(root, 0, totalNodes) && isMaxHeapOrder(root);
}

int main() {
    std::cout << "\n\e[0;35m[========= E05-PROPIEDAD-MONTICULO =========]\e[0m\n\n";

    DrxArbinNode<int>* validHeap = new DrxArbinNode<int>(100);
    validHeap->left = new DrxArbinNode<int>(19);
    validHeap->left->left = new DrxArbinNode<int>(17);
    validHeap->left->right = new DrxArbinNode<int>(3);
    validHeap->right = new DrxArbinNode<int>(36);

    DrxArbinNode<int>* invalidHeapComplete = new DrxArbinNode<int>(100);
    invalidHeapComplete->left = new DrxArbinNode<int>(19);
    invalidHeapComplete->left->left = new DrxArbinNode<int>(17);
    invalidHeapComplete->right = new DrxArbinNode<int>(36);
    invalidHeapComplete->right->left = new DrxArbinNode<int>(25);

    DrxArbinNode<int>* invalidHeapOrder = new DrxArbinNode<int>(10);
    invalidHeapOrder->left = new DrxArbinNode<int>(50);
    invalidHeapOrder->right = new DrxArbinNode<int>(15);

    std::cout << "¿Es Montículo Máximo el Árbol 1?: " << (isMaxHeap(validHeap) ? "Sí" : "No") << "\n";
    std::cout << "¿Es Montículo Máximo el Árbol 2?: " << (isMaxHeap(invalidHeapComplete) ? "Sí" : "No") << "\n";
    std::cout << "¿Es Montículo Máximo el Árbol 3?: " << (isMaxHeap(invalidHeapOrder) ? "Sí" : "No") << "\n\n";

    delete validHeap;
    delete invalidHeapComplete;
    delete invalidHeapOrder;
    return 0;
}
