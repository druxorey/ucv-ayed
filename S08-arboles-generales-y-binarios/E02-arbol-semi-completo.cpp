#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Verifica recursivamente si el árbol general es semi-completo.
// Concepto Teórico (Árboles Generales Semi-Completos e Homogeneidad de Grado):
// Un árbol general se clasifica como semi-completo si todos sus nodos internos (nodos que no son hojas) 
// poseen exactamente el mismo número de hijos (mismo grado de bifurcación). Las hojas están exentas de esta regla.
// Para verificarlo recursivamente:
// 1. Caso Base: Si el nodo es una hoja (isLeaf()), retorna 'true' de manera trivial.
// 2. Establecimiento del Grado Esperado: La variable de referencia 'expectedGrade' actúa como un acumulador global
//    iniciado en -1. El primer nodo interno que encontremos fijará el grado de referencia.
// 3. Validación de Consistencia: Cada nodo interno posterior compara su cantidad de hijos ('currentGrade') con
//    el grado de referencia 'expectedGrade'. Si hay discrepancia, se retorna 'false' abortando la recursión.
// 4. Propagación Recursiva: Se exploran todos los hijos de forma recursiva; si algún subárbol reporta que
//    no es semi-completo, el error se propaga hacia arriba retornando 'false'.
bool checkSemiComplete(DrxTreeNode<int>* node, int& expectedGrade) {
    if (node == nullptr) return true; // Caso base: Nodo nulo es semi-completo

    // Las hojas no definen ni violan el grado de los nodos internos, se ignoran en la validación
    if (node->isLeaf()) return true;

    int currentGrade = node->childrenCount(); // Grado (número de hijos) del nodo actual

    // Si es el primer nodo interno encontrado, definimos el grado esperado del árbol
    if (expectedGrade == -1) {
        expectedGrade = currentGrade;
    } 
    // Si ya existe un grado esperado y el nodo actual difiere, el árbol no es semi-completo
    else if (currentGrade != expectedGrade) {
        return false;
    }

    // Recorrer recursivamente todos los hijos
    typename DrxList<DrxTreeNode<int>*>::Iterator it = node->children.first();
    while (it != node->children.end()) {
        DrxTreeNode<int>* child = *node->children.get(it);
        if (!checkSemiComplete(child, expectedGrade)) {
            return false; // Propagación de fallo
        }
        node->children.next(it);
    }

    return true; // Todos los nodos internos en este subárbol tienen grado consistente
}


int main() {
    std::cout << "\n\e[0;35m[========= E02-ARBOL-SEMI-COMPLETO =========]\e[0m\n\n";

    DrxTree<int> tree(1);
    DrxTreeNode<int>* root = tree.root;

    tree.addChildren(2, root);
    tree.addChildren(3, root);

    typename DrxList<DrxTreeNode<int>*>::Iterator it = root->children.first();
    DrxTreeNode<int>* nodo2 = *root->children.get(it);
    root->children.next(it);
    DrxTreeNode<int>* nodo3 = *root->children.get(it);

    tree.addChildren(4, nodo2);
    tree.addChildren(5, nodo2);
    tree.addChildren(6, nodo3);
    tree.addChildren(7, nodo3);

    int grade = -1;
    bool isSemiComplete = checkSemiComplete(root, grade);

    if (isSemiComplete) {
        printf("\e[1;32m[RESULTADO]\e[0m El árbol es semi-completo (Grado común de nodos internos: %d)\n\n", grade);
    } else {
        printf("\e[1;31m[RESULTADO]\e[0m El árbol NO es semi-completo.\n\n");
    }

    return 0;
}
