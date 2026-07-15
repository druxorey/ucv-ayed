#include <iostream>
#include "../S99-implementaciones/drxtree.hpp"

// Comprueba recursivamente si el árbol T1 es una imagen especular (espejo) de T2.
// Concepto Teórico (Reflexión / Imagen Especular en Árboles Binarios):
// Dos árboles T1 y T2 son imágenes espejo si:
// 1. Sus raíces contienen el mismo valor.
// 2. La rama IZQUIERDA de T1 es el reflejo de la rama DERECHA de T2 (evaluado de forma cruzada).
// 3. La rama DERECHA de T1 es el reflejo de la rama IZQUIERDA de T2 (evaluado de forma cruzada).
// Base de fallo: Si una rama es nula y la otra no, se rompe la simetría física.
bool areMirror(DrxArbinNode<int>* T1, DrxArbinNode<int>* T2) {
    if (T1 == nullptr && T2 == nullptr) return true; // Ambas vacías son simétricas
    if (T1 == nullptr || T2 == nullptr) return false; // Desbalance simétrico

    // El valor debe ser igual y los subárboles deben ser simétricos de forma cruzada (espejada)
    return (T1->value == T2->value) &&
           areMirror(T1->left, T2->right) &&
           areMirror(T1->right, T2->left);
}


// Determina si un árbol binario es simétrico respecto a su eje central.
// Concepto Teórico (Simetría Bilateral de Árboles):
// Un árbol completo es simétrico si, trazando una línea vertical por la raíz,
// el lado izquierdo es el reflejo especular del lado derecho.
// Por ende, la simetría de 'A' se reduce a verificar si el subárbol izquierdo de su raíz 
// es un espejo del subárbol derecho.
bool isSymmetric(DrxArbin<int>& A) {
    if (A.isEmpty()) return true; // Un árbol vacío es simétrico por definición
    return areMirror(A.root->left, A.root->right); // Comparar las dos mitades
}


int main() {
    std::cout << "\n\e[0;35m[========= E16-VERIFICAR-SIMETRIA =========]\e[0m\n\n";

    DrxArbinNode<int>* symmetricRoot = new DrxArbinNode<int>(1);
    symmetricRoot->left = new DrxArbinNode<int>(2);
    symmetricRoot->left->left = new DrxArbinNode<int>(3);
    symmetricRoot->right = new DrxArbinNode<int>(2);
    symmetricRoot->right->right = new DrxArbinNode<int>(3);
    DrxArbin<int> A1(symmetricRoot);

    DrxArbinNode<int>* asymmetricRoot = new DrxArbinNode<int>(1);
    asymmetricRoot->left = new DrxArbinNode<int>(2);
    asymmetricRoot->left->right = new DrxArbinNode<int>(3);
    asymmetricRoot->right = new DrxArbinNode<int>(2);
    asymmetricRoot->right->right = new DrxArbinNode<int>(3);
    DrxArbin<int> A2(asymmetricRoot);

    std::cout << "¿Es simétrico el Árbol 1?: " << (isSymmetric(A1) ? "Sí" : "No") << "\n";
    std::cout << "¿Es simétrico el Árbol 2?: " << (isSymmetric(A2) ? "Sí" : "No") << "\n\n";

    return 0;
}
