#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Suma recursiva de los nodos que se encuentran entre los niveles A y B (inclusive).
// Concepto Teórico (Recorrido DFS con Poda por Profundidad en Árboles Generales):
// En un árbol general, un nodo puede tener un número variable de hijos almacenados en una lista.
// Para buscar y procesar elementos por niveles de profundidad usando DFS (Búsqueda en Profundidad):
// 1. Llevamos el registro del nivel actual ('currentLevel'), comenzando desde 0 en la raíz.
// 2. Evaluamos la pertenencia del nivel al intervalo de interés [A, B]: 'currentLevel >= A && currentLevel <= B'.
// 3. Poda por Profundidad (Optimization): Si alcanzamos el límite superior 'B' ('currentLevel >= B'),
//    detenemos la exploración vertical retornando inmediatamente, ya que los descendientes 
//    estarán a niveles mayores que B (fuera de rango).
// 4. Si no se ha podado, iteramos sobre la lista de hijos ('node->children') y llamamos recursivamente
//    incrementando el nivel actual en 1 ('currentLevel + 1').
void sumNodesBetweenLevels(DrxTreeNode<int>* node, int currentLevel, int A, int B, int& sum) {
    if (node == nullptr) return; // Caso base: Nodo nulo

    // Acumular si el nodo está dentro del rango de niveles [A, B]
    if (currentLevel >= A && currentLevel <= B) {
        sum += node->value;
    }

    // Poda por profundidad: No explorar subárboles más allá del nivel máximo B
    if (currentLevel >= B) return;

    // Recorrido de los hijos del nodo general utilizando el iterador de la lista
    typename DrxList<DrxTreeNode<int>*>::Iterator it = node->children.first();
    while (it != node->children.end()) {
        DrxTreeNode<int>* child = *node->children.get(it);
        sumNodesBetweenLevels(child, currentLevel + 1, A, B, sum); // Llamada recursiva
        node->children.next(it); // Pasar al siguiente hermano
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E01-SUMA-ENTRE-NIVELES =========]\e[0m\n\n";

    // Crear árbol general: raíz 10 (Nivel 0)
    // Hijos de 10: 20, 30 (Nivel 1)
    // Hijos de 20: 40, 50 (Nivel 2)
    // Hijo de 30: 60 (Nivel 2)
    DrxTree<int> tree(10);
    DrxTreeNode<int>* root = tree.root;
    
    tree.addChildren(20, root);
    tree.addChildren(30, root);

    typename DrxList<DrxTreeNode<int>*>::Iterator it = root->children.first();
    DrxTreeNode<int>* nodo20 = *root->children.get(it);
    root->children.next(it);
    DrxTreeNode<int>* nodo30 = *root->children.get(it);

    tree.addChildren(40, nodo20);
    tree.addChildren(50, nodo20);
    tree.addChildren(60, nodo30);

    int levelA = 1;
    int levelB = 2;
    int sum = 0;

    std::cout << "Árbol General Inicial:\n";
    std::cout << "  Nivel 0: [10]\n";
    std::cout << "  Nivel 1: [20, 30]\n";
    std::cout << "  Nivel 2: [40, 50, 60]\n\n";

    sumNodesBetweenLevels(root, 0, levelA, levelB, sum);

    printf("\e[1;32m[RESULTADO]\e[0m Suma de los enteros entre los niveles %d y %d: %d\n\n", levelA, levelB, sum);

    return 0;
}
