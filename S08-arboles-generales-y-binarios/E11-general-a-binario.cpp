#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Estructura alternativa minimalista para ejemplificar la conversión jerárquica.
struct BinaryNode {
    int value;
    BinaryNode* left;  // Hijo Izquierdo (primer hijo del árbol general)
    BinaryNode* right; // Hermano Derecho (hermano adyacente del árbol general)

    BinaryNode(int val) : value(val), left(nullptr), right(nullptr) {}
    ~BinaryNode() {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }
};


// Convierte un árbol general a su representación binaria equivalente (LCRS).
// Concepto Teórico (Representación Hijo Izquierdo - Hermano Derecho / LCRS):
// La representación Left-Child Right-Sibling (LCRS) es una técnica para mapear un árbol general de grado N 
// en un árbol binario estructurado con solo dos enlaces por nodo (left y right):
// - El puntero 'left' (izquierdo) de un nodo apunta a su PRIMER HIJO en el árbol general.
// - El puntero 'right' (derecho) de un nodo apunta a su HERMANO DIRECTO ADYACENTE en el árbol general.
// Esto permite simular árboles con cualquier número de hijos usando la misma cantidad constante de punteros por nodo.
// El algoritmo realiza este mapeo recursivamente:
// 1. Creamos el nodo binario equivalente 'bNode'.
// 2. Si el nodo general tiene hijos, convertimos el primero recursivamente y lo asignamos a 'bNode->left'.
// 3. Iteramos por el resto de hermanos enlazándolos en cadena a través del puntero 'right' del nodo anterior.
BinaryNode* convertGeneralToBinary(DrxTreeNode<int>* gNode) {
    if (gNode == nullptr) return nullptr; // Caso base: Nodo nulo

    // Crear el nodo binario correspondiente para el valor actual
    BinaryNode* bNode = new BinaryNode(gNode->value);

    // Si el nodo general tiene hijos, mapeamos el primer hijo y sus hermanos
    if (gNode->childrenCount() > 0) {
        typename DrxList<DrxTreeNode<int>*>::Iterator it = gNode->children.first();
        DrxTreeNode<int>* firstChild = *gNode->children.get(it);
        
        // El primer hijo del árbol general se convierte en el hijo IZQUIERDO del nodo binario
        bNode->left = convertGeneralToBinary(firstChild);
        
        BinaryNode* currentBinary = bNode->left; // Cursor para encadenar los hermanos
        gNode->children.next(it);

        // Los hermanos del primer hijo se encadenan hacia la DERECHA recursivamente
        while (it != gNode->children.end()) {
            DrxTreeNode<int>* nextChild = *gNode->children.get(it);
            currentBinary->right = convertGeneralToBinary(nextChild); // Asignar al hermano derecho
            currentBinary = currentBinary->right; // Desplazar el cursor al hermano recién creado
            gNode->children.next(it);
        }
    }

    return bNode;
}


// Imprime el árbol binario en preorden para verificar la estructura.
void displayPreorderLCRS(BinaryNode* node) {
    if (node == nullptr) return;
    std::cout << node->value << " ";
    displayPreorderLCRS(node->left);
    displayPreorderLCRS(node->right);
}


int main() {
    std::cout << "\n\e[0;35m[========= E11-GENERAL-A-BINARIO =========]\e[0m\n\n";

    DrxTree<int> generalTree(10);
    DrxTreeNode<int>* gRoot = generalTree.root;

    generalTree.addChildren(20, gRoot);
    generalTree.addChildren(30, gRoot);
    generalTree.addChildren(40, gRoot);

    typename DrxList<DrxTreeNode<int>*>::Iterator it = gRoot->children.first();
    DrxTreeNode<int>* g20 = *gRoot->children.get(it);
    generalTree.addChildren(50, g20);

    std::cout << "Árbol General inicial cargado.\n";

    BinaryNode* bRoot = convertGeneralToBinary(gRoot);

    std::cout << "\e[1;32m[RESULTADO]\e[0m Árbol Binario Equivalente (Preorden LCRS): [ ";
    displayPreorderLCRS(bRoot);
    std::cout << "]\n\n";

    delete bRoot;
    return 0;
}
