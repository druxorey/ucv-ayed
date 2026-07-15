#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Verifica si un árbol binario es estrictamente completo (lleno).
// Concepto Teórico (Árbol Binario Estrictamente Completo / Full Binary Tree):
// Un árbol binario es estrictamente completo si todos sus nodos tienen exactamente 0 hijos (nodos hoja) 
// o exactamente 2 hijos (nodos internos). Ningún nodo en el árbol puede tener un único hijo (grado de salida = 1).
// Para validarlo recursivamente:
// 1. Caso Base 1: Un árbol vacío (nullptr) es completo.
// 2. Caso Base 2: Un nodo hoja (ambos hijos nulos) es completo (posee 0 hijos).
// 3. Paso Inductivo: Si el nodo tiene tanto hijo izquierdo como derecho (2 hijos), el árbol es completo 
//    si y solo si ambos subárboles (izquierdo y derecho) también son estrictamente completos.
// 4. Si el nodo no cae en ninguno de los casos anteriores (tiene un solo hijo), viola la regla y retorna 'false'.
bool isStrictlyComplete(DrxArbinNode<int>* node) {
    if (node == nullptr) return true; // Caso base 1: Nodo vacío

    // Caso base 2: Nodo hoja (tiene 0 hijos, es válido)
    if (node->left == nullptr && node->right == nullptr) return true;

    // Caso inductivo: Nodo con 2 hijos. Evaluamos la completitud de ambos lados
    if (node->left != nullptr && node->right != nullptr) {
        return isStrictlyComplete(node->left) && isStrictlyComplete(node->right);
    }

    // Si tiene exactamente 1 hijo (izquierdo o derecho), no es estrictamente completo
    return false;
}


int main() {
    std::cout << "\n\e[0;35m[========= E14-ARBOL-BINARIO-COMPLETO =========]\e[0m\n\n";

    DrxArbinNode<int>* completeRoot = new DrxArbinNode<int>(10);
    completeRoot->left = new DrxArbinNode<int>(5);
    completeRoot->right = new DrxArbinNode<int>(15);

    DrxArbinNode<int>* incompleteRoot = new DrxArbinNode<int>(10);
    incompleteRoot->left = new DrxArbinNode<int>(5);

    std::cout << "¿Es completo el Árbol 1?: " << (isStrictlyComplete(completeRoot) ? "Sí" : "No") << "\n";
    std::cout << "¿Es completo el Árbol 2?: " << (isStrictlyComplete(incompleteRoot) ? "Sí" : "No") << "\n\n";

    delete completeRoot;
    delete incompleteRoot;
    return 0;
}
