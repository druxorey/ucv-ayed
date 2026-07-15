#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"
#include "../S99-implementaciones/drxstack.hpp"

// Recorrido Inorden (Simétrico) no recursivo (iterativo) utilizando una pila auxiliar.
// Concepto Teórico (Simulación de la Pila de Llamadas para Recorridos Iterativos):
// Todo algoritmo recursivo puede ser transformado en iterativo simulando manualmente la pila del sistema.
// En el recorrido Inorden (Izquierda -> Raíz -> Derecha), debemos posponer la visita de los ancestros 
// hasta haber procesado completamente sus subárboles izquierdos.
// Algoritmo:
// 1. Exploración a la izquierda: Avanzamos hacia el extremo izquierdo ('current = current->left'), 
//    apilando cada nodo intermedio para recordar el camino de retorno.
// 2. Procesamiento de Raíz: Cuando topamos con un puntero nulo, desapilamos el nodo superior (el más 
//    izquierdo pendiente), lo visitamos/imprimimos.
// 3. Transición a la Derecha: Redirigimos la exploración hacia el subárbol derecho de ese nodo ('current = current->right'),
//    repitiendo el ciclo.
// Complejidad temporal: O(N) y de espacio: O(H), donde H es la altura del árbol.
void inorderIterative(DrxArbinNode<int>* root) {
    if (root == nullptr) return;

    DrxStack<DrxArbinNode<int>*> stack; // Pila de control explícita
    DrxArbinNode<int>* current = root;  // Cursor de exploración

    // El ciclo continúa mientras queden subárboles por explorar o nodos por desapilar
    while (current != nullptr || !stack.isEmpty()) {
        // 1. Fase de Profundización Izquierda: Apilar ancestros y descender a la izquierda
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // 2. Fase de Retorno y Visita: Desapilar el último ancestro alcanzado
        current = stack.top();
        stack.pop();

        std::cout << current->value << " "; // Visitar nodo (Raíz)

        // 3. Fase de Transición: Desplazarse al subárbol derecho
        current = current->right;
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E12-INORDEN-NO-RECURSIVO =========]\e[0m\n\n";

    DrxArbinNode<int>* root = new DrxArbinNode<int>(10);
    root->left = new DrxArbinNode<int>(5);
    root->left->left = new DrxArbinNode<int>(2);
    root->left->right = new DrxArbinNode<int>(7);
    root->right = new DrxArbinNode<int>(15);

    DrxArbin<int> tree(root);

    std::cout << "Estructura del árbol binario creada.\n";
    std::cout << "\e[1;32m[RESULTADO]\e[0m Recorrido Inorden Iterativo (Simétrico): [ ";
    inorderIterative(root);
    std::cout << "]\n\n";

    return 0;
}
