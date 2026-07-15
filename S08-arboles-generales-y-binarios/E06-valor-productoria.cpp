#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Función recursiva que calcula la productoria (multiplicación) de todos los nodos de un subárbol.
// Concepto Teórico (Reducción Multiplicativa en Árboles Binarios):
// La multiplicación acumulada de los nodos de un árbol binario se modela inductivamente:
// - Caso Base: Si el nodo es nulo, retornamos 1. Esto se debe a que 1 es el elemento neutro 
//   de la multiplicación (no afecta al producto acumulado).
// - Paso Recursivo: Retornamos el valor del nodo actual multiplicado por el producto de su subárbol
//   izquierdo y el de su subárbol derecho.
// Esta evaluación sigue un recorrido de post-orden (se resuelven primero los hijos antes de consolidar el padre).
int productSubtree(DrxArbinNode<int>* node) {
    if (node == nullptr) {
        return 1; // Elemento neutro multiplicativo
    }
    return node->value * productSubtree(node->left) * productSubtree(node->right);
}


// Función principal que retorna el Valor(A) = Productoria(Izq(A)) - Productoria(Der(A)).
// Concepto Teórico (Cálculo del Indicador de Balance de Subárboles):
// Esta función computa la diferencia neta entre los productos de los nodos de los dos subárboles 
// principales (izquierdo y derecho) de la raíz.
// - Si el árbol está vacío, retorna 0 (caso trivial).
// - De lo contrario, calcula por separado los productos recursivos de ambos lados y realiza la resta.
int calculateProductValue(DrxArbin<int>& A) {
    if (A.isEmpty()) return 0; // Caso base: árbol vacío

    int prodLeft = productSubtree(A.root->left);   // Producto del subárbol izquierdo
    int prodRight = productSubtree(A.root->right); // Producto del subárbol derecho

    std::cout << "  Productoria Subárbol Izquierdo: " << prodLeft << "\n";
    std::cout << "  Productoria Subárbol Derecho:   " << prodRight << "\n";

    return prodLeft - prodRight;
}


int main() {
    std::cout << "\n\e[0;35m[========= E06-VALOR-PRODUCTORIA =========]\e[0m\n\n";

    DrxArbinNode<int>* root = new DrxArbinNode<int>(5);
    root->left = new DrxArbinNode<int>(2);
    root->left->left = new DrxArbinNode<int>(3);
    
    root->right = new DrxArbinNode<int>(4);
    root->right->right = new DrxArbinNode<int>(1);

    DrxArbin<int> tree(root);

    std::cout << "Árbol Binario cargado.\n";
    
    int result = calculateProductValue(tree);

    printf("\n\e[1;32m[RESULTADO]\e[0m Valor del árbol (ProdIzq - ProdDer): %d\n\n", result);

    return 0;
}
