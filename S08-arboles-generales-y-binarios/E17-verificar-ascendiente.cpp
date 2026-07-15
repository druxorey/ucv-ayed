#include <iostream>
#include "../S99-implementations/drxtree.hpp"

// Busca si el nodo 'target' existe en la descendencia de 'subRoot' (búsqueda recursiva).
// Concepto Teórico (Descendencia en Árboles):
// Un nodo Y es descendiente de un nodo X si y solo si Y se encuentra en el subárbol enraizado en X.
// Para verificarlo recursivamente:
// - Si la raíz local 'subRoot' es nula, retornamos 'false'.
// - Si 'subRoot' apunta al mismo objeto que 'target', hemos localizado al descendiente, retornamos 'true'.
// - Si no, buscamos recursivamente en el subárbol izquierdo o en el subárbol derecho (búsqueda OR inclusiva).
bool isDescendant(DrxArbinNode<int>* subRoot, DrxArbinNode<int>* target) {
    if (subRoot == nullptr || target == nullptr) return false;

    if (subRoot == target) return true; // Coincidencia encontrada

    // Buscar en profundidad en alguna de las dos ramas
    return isDescendant(subRoot->left, target) ||
           isDescendant(subRoot->right, target);
}


// Determina si el nodo X es ascendiente del nodo Y.
// Concepto Teórico (Relación Ancestral Estricta):
// Un nodo X es ascendiente de Y si y solo si Y es descendiente de alguno de los hijos de X.
// - Un nodo no puede ser su propio ascendiente (antirreflexividad), por lo que si X == Y retornamos 'false'.
// - Si alguno de los punteros es nulo, la relación es inválida.
// - Si las validaciones pasan, verificamos si Y es descendiente del hijo izquierdo de X o de su hijo derecho.
bool isAncestor(DrxArbinNode<int>* X, DrxArbinNode<int>* Y) {
    if (X == nullptr || Y == nullptr || X == Y) return false; // Validaciones de contorno y no-autorreferencia
    
    // Y debe estar en la descendencia de alguno de los hijos de X
    return isDescendant(X->left, Y) || isDescendant(X->right, Y);
}

int main() {
    std::cout << "\n\e[0;35m[========= E17-VERIFICAR-ASCENDIENTE =========]\e[0m\n\n";

    DrxArbinNode<int>* root = new DrxArbinNode<int>(10);
    root->left = new DrxArbinNode<int>(5);
    root->left->left = new DrxArbinNode<int>(2);
    root->right = new DrxArbinNode<int>(15);

    DrxArbinNode<int>* nodo5 = root->left;
    DrxArbinNode<int>* nodo2 = root->left->left;
    DrxArbinNode<int>* nodo15 = root->right;

    std::cout << "¿Es el nodo 10 (raíz) ascendiente de 2?: " << (isAncestor(root, nodo2) ? "Sí" : "No") << "\n";
    std::cout << "¿Es el nodo 5 ascendiente de 2?:        " << (isAncestor(nodo5, nodo2) ? "Sí" : "No") << "\n";
    std::cout << "¿Es el nodo 15 ascendiente de 2?:       " << (isAncestor(nodo15, nodo2) ? "Sí" : "No") << "\n\n";

    delete root;
    return 0;
}
