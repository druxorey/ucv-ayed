#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Comprueba si dos árboles binarios son idénticos en estructura y valores.
// Concepto Teórico (Isomorfismo e Igualdad en Árboles Binarios):
// Dos árboles binarios son idénticos si y solo si:
// 1. Tienen la misma topología estructural (la misma distribución de ramas).
// 2. Los nodos correspondientes almacenan el mismo valor.
// Para evaluarlo recursivamente:
// - Si ambos son nulos, son trivialmente idénticos (base de éxito).
// - Si solo uno de los dos es nulo, no son idénticos (base de fallo estructural).
// - Evaluamos la igualdad del valor actual y llamamos recursivamente a los subárboles izquierdos y derechos.
bool areIdentical(DrxArbinNode<int>* A, DrxArbinNode<int>* B) {
    if (A == nullptr && B == nullptr) return true; // Ambos vacíos
    if (A == nullptr || B == nullptr) return false; // Uno vacío y el otro no (desbalance de estructura)

    // El valor actual debe coincidir y ambos subárboles deben ser isomorfos
    return (A->value == B->value) &&
           areIdentical(A->left, B->left) &&
           areIdentical(A->right, B->right);
}


// Retorna la dirección del subárbol de T que es idéntico a S, o nullptr si no está incluido.
// Concepto Teórico (Búsqueda de Patrones de Subárboles):
// Buscamos si la estructura de un árbol pequeño 'S' está contenida en un árbol mayor 'T'.
// Para cada nodo visitado de 'T' (recorrido pre-orden):
// 1. Probamos si el subárbol enraizado en 'T' es idéntico a 'S' llamando a 'areIdentical(T, S)'.
// 2. Si coincide, retornamos 'T' como la dirección raíz del patrón encontrado.
// 3. Si no coincide, buscamos recursivamente en el hijo izquierdo de 'T' y, si falla, en el derecho.
// Complejidad temporal: O(|T| * |S|) en el peor caso, donde |T| y |S| son el número de nodos de cada árbol.
DrxArbinNode<int>* findSubtree(DrxArbinNode<int>* T, DrxArbinNode<int>* S) {
    if (S == nullptr) return nullptr; // Un patrón nulo no se puede buscar
    if (T == nullptr) return nullptr; // Si el árbol contenedor es nulo, no hay coincidencia posible

    // Comparar si el subárbol actual de T coincide exactamente con S
    if (areIdentical(T, S)) {
        return T; // Coincidencia encontrada en este nodo raíz
    }

    // Si no coincide, buscar recursivamente en el subárbol izquierdo
    DrxArbinNode<int>* foundLeft = findSubtree(T->left, S);
    if (foundLeft != nullptr) {
        return foundLeft; // Propagar resultado si fue hallado en la izquierda
    }

    // Si no, buscar en el subárbol derecho
    return findSubtree(T->right, S);
}


int main() {
    std::cout << "\n\e[0;35m[========= E15-VERIFICAR-SUBARBOL =========]\e[0m\n\n";

    DrxArbinNode<int>* T = new DrxArbinNode<int>(10);
    T->left = new DrxArbinNode<int>(5);
    T->left->left = new DrxArbinNode<int>(2);
    T->left->right = new DrxArbinNode<int>(7);
    T->right = new DrxArbinNode<int>(15);

    DrxArbinNode<int>* S = new DrxArbinNode<int>(5);
    S->left = new DrxArbinNode<int>(2);
    S->right = new DrxArbinNode<int>(7);

    std::cout << "Buscando subárbol S en T...\n";
    DrxArbinNode<int>* result = findSubtree(T, S);

    if (result != nullptr) {
        printf("\n\e[1;32m[RESULTADO]\e[0m Subárbol encontrado en la dirección física: \e[1;33m%p\e[0m (Valor raíz: %d)\n\n", (void*)result, result->value);
    } else {
        std::cout << "\n\e[1;31m[RESULTADO]\e[0m El subárbol S no está incluido en T.\n\n";
    }

    delete T;
    delete S;
    return 0;
}
