#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// a) Retorna verdadero si X es un nodo hoja (no tiene hijos).
// Concepto Teórico (Nodo Hoja en Árboles Binarios):
// Un nodo hoja es un nodo terminal, lo que significa que carece de descendientes.
// En términos de implementación, evaluamos si tanto el puntero izquierdo (left) 
// como el puntero derecho (right) son nulos (nullptr).
// Complejidad temporal: O(1).
bool isLeafNode(DrxArbinNode<int>* node) {
    if (node == nullptr) return false; // Un nodo nulo no puede ser una hoja
    return node->left == nullptr && node->right == nullptr;
}


// b) Retorna verdadero si el nodo x es padre directo del nodo y.
// Concepto Teórico (Relación Padre-Hijo en Árboles Binarios):
// En un árbol binario estándar con punteros descendentes, para verificar si 'x' es padre de 'y',
// evaluamos si 'y' es el hijo izquierdo o derecho de 'x'.
// Complejidad temporal: O(1), ya que es un acceso directo a los enlaces inmediatos del nodo 'x'.
// Nota de Diseño: Para verificar la relación de paternidad a la inversa (saber si y es hijo de x) en tiempo
// constante sin tener la referencia de 'x', cada nodo debería almacenar un puntero a su ancestro ('parent').
// En ese caso, la evaluación sería directa: 'y->parent == x'.
bool isParentOf(DrxArbinNode<int>* x, DrxArbinNode<int>* y) {
    if (x == nullptr || y == nullptr) return false;
    return x->left == y || x->right == y;
}


int main() {
    std::cout << "\n\e[0;35m[========= E13-OPERACIONES-ARBIN =========]\e[0m\n\n";

    DrxArbinNode<int>* root = new DrxArbinNode<int>(10);
    root->left = new DrxArbinNode<int>(5);
    root->right = new DrxArbinNode<int>(15);

    DrxArbinNode<int>* nodo5 = root->left;
    DrxArbinNode<int>* nodo15 = root->right;

    std::cout << "¿EsHoja(15)?: " << (isLeafNode(nodo15) ? "Sí" : "No") << "\n";
    std::cout << "¿EsHoja(10)?: " << (isLeafNode(root) ? "Sí" : "No") << "\n";
    std::cout << "¿EsPadre(10, 5)?: " << (isParentOf(root, nodo5) ? "Sí" : "No") << "\n";
    std::cout << "¿EsPadre(15, 5)?: " << (isParentOf(nodo15, nodo5) ? "Sí" : "No") << "\n\n";

    std::cout << "\e[1;32m[DISEÑO OPTIMIZADO O(1)]\e[0m\n";
    std::cout << "Para lograr que EsPadre sea O(1), se debe agregar un puntero al padre ('parent')\n";
    std::cout << "en cada nodo de la estructura. Así, la verificación se reduce a evaluar:\n";
    std::cout << "  \"y->parent == x\"\n";
    std::cout << "Lo cual toma tiempo constante O(1) directo sin búsquedas jerárquicas.\n\n";

    delete root;
    return 0;
}
