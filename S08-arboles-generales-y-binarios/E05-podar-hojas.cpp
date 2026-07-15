#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Elimina recursivamente todas las hojas del árbol general (pruneLeaves).
// Concepto Teórico (Poda de Hojas en Estructuras Arbóreas y Resguardo de Iteradores):
// Podar las hojas implica recorrer el árbol y eliminar físicamente aquellos nodos que no tienen hijos (hojas),
// desvinculándolos de la lista de hijos de sus respectivos padres para no dejar punteros sueltos (dangling pointers).
// Desafío de Modificación en Recorrido:
// - Al recorrer la lista de hijos 'node->children' con un iterador 'it', si borramos un nodo de la lista,
//   el iterador 'it' se invalida.
// - Para evitar esto: antes de borrar el nodo en la lista, guardamos el iterador actual en 'target',
//   avanzamos 'it' al siguiente elemento hermano ('node->children.next(it)'), y luego eliminamos 
//   seguramente el nodo usando el iterador resguardado 'target'.
// - Si el hijo es un nodo interno (no es hoja), descendemos recursivamente ('pruneLeaves(child)') para
//   limpiar sus propios descendientes, y avanzamos el iterador de forma regular.
void pruneLeaves(DrxTreeNode<int>* node) {
    if (node == nullptr) return; // Caso base: Nodo nulo

    typename DrxList<DrxTreeNode<int>*>::Iterator it = node->children.first();
    
    // Iterar sobre todos los hijos del nodo actual
    while (it != node->children.end()) {
        DrxTreeNode<int>* child = *node->children.get(it);

        // Caso 1: El hijo es una hoja (no tiene descendientes)
        if (child != nullptr && child->isLeaf()) {
            std::cout << "  Podando hoja: " << child->value << "\n";
            delete child; // Liberar memoria dinámica del objeto nodo en el Heap
            
            // Resguardo de Iterador: copiar, avanzar iterador de exploración, y borrar nodo de la lista
            typename DrxList<DrxTreeNode<int>*>::Iterator target = it;
            node->children.next(it);
            node->children.deleteNode(target); // Remover el puntero del contenedor del padre
        } 
        // Caso 2: El hijo es un nodo interno (se limpia su subárbol primero)
        else {
            pruneLeaves(child); // Llamada recursiva para podar las hojas del hijo
            node->children.next(it); // Avanzar iterador normalmente
        }
    }
}


// Imprime los valores del árbol en preorden.
void printPreorder(DrxTreeNode<int>* node) {
    if (node == nullptr) return;
    std::cout << node->value << " ";
    typename DrxList<DrxTreeNode<int>*>::Iterator it = node->children.first();
    while (it != node->children.end()) {
        printPreorder(*node->children.get(it));
        node->children.next(it);
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E05-PODAR-HOJAS =========]\e[0m\n\n";

    // Crear árbol: raíz 10 (interno)
    // Hijos de 10: 20 (interno), 30 (hoja)
    // Hijos de 20: 40 (hoja), 50 (hoja)
    DrxTree<int> tree(10);
    DrxTreeNode<int>* root = tree.root;

    tree.addChildren(20, root);
    tree.addChildren(30, root);

    typename DrxList<DrxTreeNode<int>*>::Iterator it = root->children.first();
    DrxTreeNode<int>* nodo20 = *root->children.get(it);

    tree.addChildren(40, nodo20);
    tree.addChildren(50, nodo20);

    std::cout << "Árbol original (Preorden): [ ";
    printPreorder(root);
    std::cout << "]\n\n";

    pruneLeaves(root);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Árbol después de la poda (esperado: [ 10 20 ]): [ ";
    printPreorder(root);
    std::cout << "]\n\n";

    return 0;
}
