#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"
#include "../S99-implementaciones/drxstack.hpp"

// Nodo de Árbol General local (GeneralNode).
struct GeneralNode {
    char value;
    DrxList<GeneralNode*> children;

    GeneralNode(char val) : value(val) {}
    ~GeneralNode() {
        typename DrxList<GeneralNode*>::Iterator it = children.first();
        while (it != children.end()) {
            delete *children.get(it);
            children.next(it);
        }
    }
};


// Reconstruye el árbol general usando una pila de nodos y el arreglo de postorden.
// Concepto Teórico (Reconstrucción de Árboles N-arios a partir de Postorden y Grados):
// En un recorrido Postorden (Hijos primero, Padre al final), los hijos de cualquier nodo 'X'
// son procesados inmediatamente antes que 'X' en la secuencia.
// Al escanear la secuencia de izquierda a derecha usando una Pila:
// 1. Cada nodo se apila en 'stack'.
// 2. Si un nodo tiene grado 'g' > 0, significa que sus 'g' hijos ya están en la pila (al tope).
// 3. Al desapilar los 'g' nodos, salen de derecha a izquierda (debido a la naturaleza LIFO).
// 4. Para restaurar el orden original izquierda-derecha, los desapilamos a una pila temporal 
//    'sortedChildren' antes de encolarlos en la lista de hijos del nodo padre.
// 5. El último elemento restante en la pila es la raíz del árbol reconstruido.
GeneralNode* reconstructFromPostorder(char postorder[], int grades[], int n) {
    DrxStack<GeneralNode*> stack;

    for (int i = 0; i < n; i++) {
        char val = postorder[i];
        int grade = grades[i];

        GeneralNode* newNode = new GeneralNode(val);

        // Si el nodo actual es un nodo interno (tiene hijos)
        if (grade > 0) {
            DrxStack<GeneralNode*> sortedChildren; // Pila temporal para restaurar el orden izquierda-derecha
            
            // 1. Extraer los 'grade' hijos de la pila de trabajo (salen en orden invertido)
            for (int k = 0; k < grade; k++) {
                if (stack.isEmpty()) {
                    throw "Estructura de postorden/grados inválida";
                }
                sortedChildren.push(stack.top());
                stack.pop();
            }
            // 2. Apilar en la lista de hijos del nuevo nodo en el orden correcto (izquierda a derecha)
            while (!sortedChildren.isEmpty()) {
                newNode->children.pushBack(sortedChildren.top());
                sortedChildren.pop();
            }
        }
        stack.push(newNode); // Apilar el subárbol construido
    }
    return stack.top(); // La raíz del árbol completo queda al tope de la pila
}


// Recorrido Preorden General.
void preorderGeneral(GeneralNode* node) {
    if (node == nullptr) return;
    std::cout << node->value << " ";
    typename DrxList<GeneralNode*>::Iterator it = node->children.first();
    while (it != node->children.end()) {
        preorderGeneral(*node->children.get(it));
        node->children.next(it);
    }
}


// Recorrido Inorden (Simétrico) Generalizado para Árboles N-arios.
// Concepto Teórico (Inorden en Árboles de Grado N):
// En un árbol binario, el inorden procesa: Subárbol Izquierdo -> Raíz -> Subárbol Derecho.
// Para generalizarlo a árboles N-arios (donde un nodo puede tener N hijos):
// 1. Procesamos el primer hijo (el más a la izquierda) de manera recursiva.
// 2. Procesamos (visitamos/imprimimos) el nodo raíz actual.
// 3. Procesamos recursivamente los restantes N - 1 hijos de izquierda a derecha.
// Si el nodo es una hoja (grado 0), simplemente se imprime el valor.
void inorderGeneral(GeneralNode* node) {
    if (node == nullptr) return;
    
    typename DrxList<GeneralNode*>::Iterator it = node->children.first();
    
    // 1. Procesar recursivamente únicamente el primer hijo (hijo izquierdo)
    if (it != node->children.end()) {
        inorderGeneral(*node->children.get(it));
        node->children.next(it);
    }

    // 2. Visitar el nodo actual (Raíz)
    std::cout << node->value << " ";

    // 3. Procesar recursivamente los hijos restantes (de segundo a último)
    while (it != node->children.end()) {
        inorderGeneral(*node->children.get(it));
        node->children.next(it);
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E03-INORDEN-PREORDEN-DESDE-POSTORDEN =========]\e[0m\n\n";

    char postorder[] = {'D', 'E', 'B', 'C', 'A'};
    int grades[] = {0, 0, 2, 0, 2};
    int n = 5;

    std::cout << "Postorden de entrada: [ D E B C A ]\n";
    std::cout << "Grados de entrada:    [ 0 0 2 0 2 ]\n\n";

    try {
        GeneralNode* root = reconstructFromPostorder(postorder, grades, n);

        std::cout << "\e[1;32m[RESULTADO]\e[0m Recorrido Preorden Reconstruido: [ ";
        preorderGeneral(root);
        std::cout << "]\n";

        std::cout << "\e[1;32m[RESULTADO]\e[0m Recorrido Inorden Reconstruido:  [ ";
        inorderGeneral(root);
        std::cout << "]\n\n";

        delete root;
    } catch (const char* e) {
        std::cout << "\n\e[1;31m[ERROR]\e[0m " << e << "\n\n";
    }

    return 0;
}
