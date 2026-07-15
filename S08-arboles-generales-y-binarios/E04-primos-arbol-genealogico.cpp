#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Compara si dos cadenas de caracteres son iguales.
bool stringsEqual(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}


// Busca recursivamente el padre de un nodo con el valor buscado.
// Concepto Teórico (Búsqueda de Antecesor Inmediato en Árboles N-arios):
// En un árbol con punteros únicamente hacia los hijos, encontrar el padre de un nodo requiere 
// un recorrido descendente (DFS) en el cual evaluamos la lista de hijos de cada nodo.
// - Si un nodo 'current' tiene a 'nameToSearch' en su lista de hijos directos, entonces 'current' es el padre.
// - Si no, delegamos recursivamente la búsqueda a cada uno de sus hijos.
// - Retorna nullptr si la persona no existe en el subárbol.
DrxTreeNode<const char*>* findParent(DrxTreeNode<const char*>* current, const char* nameToSearch) {
    if (current == nullptr) return nullptr;

    typename DrxList<DrxTreeNode<const char*>*>::Iterator it = current->children.first();
    // Explorar los hijos del nodo actual
    while (it != current->children.end()) {
        DrxTreeNode<const char*>* child = *current->children.get(it);
        
        // Si el hijo directo tiene el nombre buscado, 'current' es el padre inmediato
        if (stringsEqual(child->value, nameToSearch)) {
            return current;
        }
        
        // De lo contrario, buscar recursivamente en el subárbol del hijo
        DrxTreeNode<const char*>* parentFound = findParent(child, nameToSearch);
        if (parentFound != nullptr) {
            return parentFound; // Si lo encontró abajo, propagar el puntero
        }
        current->children.next(it);
    }
    return nullptr;
}


// Imprime todos los primos de la persona (hijos de los hermanos de su padre).
// Concepto Teórico (Navegación de Relaciones Horizontales de Segundo Grado):
// Los primos hermanos de un nodo se definen en la estructura del árbol como:
//   "Los hijos de los hermanos del padre de dicho nodo".
// Para localizarlos de manera eficiente:
// 1. Encontrar el nodo padre 'parent' usando 'findParent'.
// 2. Encontrar el nodo abuelo 'grandparent' aplicando 'findParent' sobre el padre.
// 3. Los hermanos del padre (tíos) son los hijos del abuelo distintos a 'parent'.
// 4. Iteramos por cada tío y mostramos a todos sus hijos directos (que son los primos de la persona).
void printCousins(DrxTreeNode<const char*>* root, const char* person) {
    DrxTreeNode<const char*>* parent = findParent(root, person);
    if (parent == nullptr) {
        std::cout << person << " no tiene padre en este árbol.\n";
        return;
    }

    DrxTreeNode<const char*>* grandparent = findParent(root, parent->value);
    if (grandparent == nullptr) {
        std::cout << person << " no tiene abuelo (su padre " << parent->value << " es cabeza de familia). No tiene primos.\n";
        return;
    }

    std::cout << "Primos de " << person << " (Padre: " << parent->value << ", Abuelo: " << grandparent->value << "):\n";
    bool hasCousins = false;

    // Iterar sobre todos los hijos del abuelo (Tíos + Padre)
    typename DrxList<DrxTreeNode<const char*>*>::Iterator uncleIt = grandparent->children.first();
    while (uncleIt != grandparent->children.end()) {
        DrxTreeNode<const char*>* uncle = *grandparent->children.get(uncleIt);
        
        // Filtrar para procesar únicamente a los tíos (excluyendo al padre biológico)
        if (uncle != parent) {
            // Iterar sobre los hijos de cada tío (los primos)
            typename DrxList<DrxTreeNode<const char*>*>::Iterator cousinIt = uncle->children.first();
            while (cousinIt != uncle->children.end()) {
                DrxTreeNode<const char*>* cousin = *uncle->children.get(cousinIt);
                std::cout << "  - " << cousin->value << " (hijo de " << uncle->value << ")\n";
                hasCousins = true;
                uncle->children.next(cousinIt);
            }
        }
        grandparent->children.next(uncleIt);
    }

    if (!hasCousins) {
        std::cout << "  (Ninguno)\n";
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E04-PRIMOS-ARBOL-GENEALOGICO =========]\e[0m\n\n";

    DrxTree<const char*> tree("Pedro");
    DrxTreeNode<const char*>* root = tree.root;

    tree.addChildren("Jose", root);
    tree.addChildren("Luis", root);

    typename DrxList<DrxTreeNode<const char*>*>::Iterator it = root->children.first();
    DrxTreeNode<const char*>* Jose = *root->children.get(it);
    root->children.next(it);
    DrxTreeNode<const char*>* Luis = *root->children.get(it);

    tree.addChildren("Juan", Jose);
    tree.addChildren("Ana", Jose);
    tree.addChildren("Santiago", Luis);

    std::cout << "Árbol Genealógico cargado.\n";
    std::cout << "Persona a buscar: Santiago\n\n";

    std::cout << "\e[1;32m[RESULTADO]\e[0m ";
    printCousins(root, "Santiago");
    std::cout << "\n";

    return 0;
}
