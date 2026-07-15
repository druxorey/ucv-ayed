#include <iostream>
#include "../S99-implementations/drxqueue.hpp"

struct HeapNode {
    int value;
    HeapNode* left;
    HeapNode* right;
    HeapNode* parent;

    HeapNode(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class PointerHeap {
private:
    HeapNode* root;

    void swap(HeapNode* a, HeapNode* b) {
        int temp = a->value;
        a->value = b->value;
        b->value = temp;
    }

    void floatUp(HeapNode* node) {
        while (node->parent != nullptr && node->parent->value < node->value) {
            swap(node, node->parent);
            node = node->parent;
        }
    }

    void sinkDown(HeapNode* node) {
        if (node == nullptr) return;

        HeapNode* maxNode = node;
        if (node->left != nullptr && node->left->value > maxNode->value) {
            maxNode = node->left;
        }
        if (node->right != nullptr && node->right->value > maxNode->value) {
            maxNode = node->right;
        }

        if (maxNode != node) {
            swap(node, maxNode);
            sinkDown(maxNode);
        }
    }

    // Encuentra el primer nodo en orden de niveles (BFS) que tenga al menos un hijo libre.
    // Concepto Teórico (Búsqueda del Punto de Inserción Completo en Estructuras Enlazadas):
    // Para conservar la propiedad de forma de un árbol binario completo (relleno por niveles de izquierda a derecha),
    // debemos insertar el nuevo elemento como hijo del primer nodo disponible en un recorrido BFS (Breadth-First Search).
    // - En un arreglo, esto se calcula en O(1) usando el índice 'count'.
    // - Con apuntadores, debemos ejecutar un recorrido por niveles usando una Cola. El primer nodo extraído de la cola 
    //   que tenga 'left == nullptr' o 'right == nullptr' es la posición correcta para insertar.
    // Complejidad temporal: O(N) en el peor caso ya que puede visitar todos los nodos.
    HeapNode* findInsertionNode() {
        if (root == nullptr) return nullptr;

        DrxQueue<HeapNode*> Q;
        Q.push(root);

        // Recorrido por niveles (BFS)
        while (!Q.empty()) {
            HeapNode* current = Q.front();
            Q.pop();

            // Retornamos el primer nodo que tenga espacio para un hijo
            if (current->left == nullptr || current->right == nullptr) {
                return current;
            }

            Q.push(current->left);
            Q.push(current->right);
        }
        return nullptr;
    }

    // Encuentra el último nodo del árbol en orden de niveles (BFS).
    // Concepto Teórico (Búsqueda del Último Nodo para Reemplazo de Raíz):
    // Al remover la raíz, debemos sustituirla por el último elemento del árbol completo (el más profundo a la derecha).
    // - Con apuntadores, hacemos un recorrido BFS completo y registramos el último nodo desencolado.
    // Complejidad temporal: O(N) porque requiere recorrer todo el árbol.
    HeapNode* findLastNode() {
        if (root == nullptr) return nullptr;

        DrxQueue<HeapNode*> Q;
        Q.push(root);
        HeapNode* lastNode = nullptr;

        // BFS exhaustivo
        while (!Q.empty()) {
            lastNode = Q.front(); // El último asignado al salir del ciclo será el último nodo de la estructura
            Q.pop();

            if (lastNode->left != nullptr) Q.push(lastNode->left);
            if (lastNode->right != nullptr) Q.push(lastNode->right);
        }
        return lastNode;
    }

public:
    PointerHeap() : root(nullptr) {}

    ~PointerHeap() {
        freeMem(root);
    }

    void freeMem(HeapNode* node) {
        if (node == nullptr) return;
        freeMem(node->left);
        freeMem(node->right);
        delete node;
    }

    // Inserta un valor en el montículo por apuntadores.
    // Concepto Teórico (Inserción con Apuntadores):
    // 1. Si el árbol está vacío, el nuevo nodo es la raíz.
    // 2. Si no, usamos 'findInsertionNode()' (O(N)) para ubicar el nodo padre disponible.
    // 3. Enlazamos el nuevo nodo como hijo izquierdo (si está libre) o derecho de ese padre.
    // 4. Mantenemos el enlace al padre 'parent = padre' para poder subir en el árbol.
    // 5. Flotamos recursivamente ('floatUp') hacia arriba (O(log N)).
    void insert(int val) {
        HeapNode* newNode = new HeapNode(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        // Buscar el padre candidato en tiempo O(N)
        HeapNode* parent = findInsertionNode();
        newNode->parent = parent;

        // Enlazar al primer slot libre (izquierdo primero, luego derecho)
        if (parent->left == nullptr) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        floatUp(newNode); // Flotar el nodo recién insertado en O(log N)
    }

    // Remueve y retorna el elemento máximo (la raíz).
    // Concepto Teórico (Remoción con Apuntadores):
    // 1. Extraemos el valor del nodo raíz.
    // 2. Buscamos el último nodo en el árbol mediante 'findLastNode()' (O(N)).
    // 3. Si la raíz es el único nodo, la eliminamos.
    // 4. Si no, copiamos el valor del último nodo en la raíz, rompemos los enlaces del padre al último nodo, 
    //    y liberamos su memoria.
    // 5. Hundimos el nuevo valor de la raíz ('sinkDown') para restaurar la propiedad de max-heap (O(log N)).
    int remove() {
        if (root == nullptr) {
            throw std::runtime_error("Montículo vacío");
        }

        int maxVal = root->value;
        HeapNode* lastNode = findLastNode(); // Localizar el último nodo en O(N)

        // Si solo quedaba la raíz en el montículo
        if (lastNode == root) {
            delete root;
            root = nullptr;
            return maxVal;
        }

        root->value = lastNode->value; // Sustituir el valor de la raíz por el del último nodo

        // Desvincular el último nodo del árbol poniendo en nulo el enlace del padre
        HeapNode* parentLast = lastNode->parent;
        if (parentLast->left == lastNode) {
            parentLast->left = nullptr;
        } else {
            parentLast->right = nullptr;
        }

        delete lastNode; // Liberar memoria física del último nodo

        sinkDown(root); // Hundir la raíz para re-establecer el orden en O(log N)

        return maxVal;
    }

    bool empty() const { return root == nullptr; }
};

int main() {
    std::cout << "\n\e[0;35m[========= E04-MONTICULO-APUNTADORES =========]\e[0m\n\n";

    PointerHeap heap;
    std::cout << "Insertando elementos: 50, 30, 80, 20...\n";
    heap.insert(50);
    heap.insert(30);
    heap.insert(80);
    heap.insert(20);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Extrayendo el máximo (esperado: 80): " << heap.remove() << "\n";
    std::cout << "\e[1;32m[RESULTADO]\e[0m Extrayendo el siguiente (esperado: 50): " << heap.remove() << "\n\n";

    std::cout << "\e[1;33m[COMPARATIVA DE COMPLEJIDAD]\e[0m\n";
    std::cout << "1. Complejidad Temporal:\n";
    std::cout << "   - Arreglo: Insertar y Remover toman O(log N) estricto. La posición de inserción es O(1).\n";
    std::cout << "   - Apuntadores: Insertar y Remover toman O(N) en el peor caso, porque encontrar la posición\n";
    std::cout << "     del último nodo o del primer espacio libre requiere un recorrido BFS de tamaño lineal.\n";
    std::cout << "2. Complejidad Espacial:\n";
    std::cout << "   - Arreglo: Cero sobrecarga de punteros. Sin embargo, puede desperdiciar memoria si se dimensiona\n";
    std::cout << "     con un tamaño físico muy grande no utilizado.\n";
    std::cout << "   - Apuntadores: Memoria exacta por nodo en el Heap. No obstante, añade una sobrecarga de\n";
    std::cout << "     3 punteros por nodo (left, right, parent), consumiendo 12/24 bytes extras por celda.\n\n";

    return 0;
}
