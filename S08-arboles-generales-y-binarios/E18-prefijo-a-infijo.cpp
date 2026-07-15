#include <iostream>
#include <string>
#include "../S99-implementations/drxtree.hpp"

// Convierte recursivamente un árbol de expresión en su representación infija parentizada.
// Concepto Teórico (Árboles de Expresión e Inorden Parentizado):
// Un Árbol de Expresión es una estructura jerárquica donde:
// - Los nodos internos representan operadores aritméticos (+, -, *, etc.).
// - Las hojas representan operandos (variables o constantes numéricas).
// El recorrido Inorden (Izquierda -> Raíz -> Derecha) de este árbol produce la expresión en formato infijo.
// Sin embargo, para mantener el orden estricto de precedencia impuesto por la topología del árbol 
// (evitando ambigüedades sin recurrir a reglas externas de precedencia), se añaden paréntesis alrededor 
// de cada operación binaria:
//   "( Izquierda Operador Derecha )".
// El algoritmo recurre recursivamente hasta las hojas (operandos), las cuales se retornan sin paréntesis.
std::string convertToInfix(DrxArbinNode<std::string>* node) {
    if (node == nullptr) return ""; // Caso base 1: Nodo vacío

    // Caso base 2: Nodo hoja (operando). Retorna el operando tal cual, sin paréntesis.
    if (node->left == nullptr && node->right == nullptr) {
        return node->value;
    }

    // Paso recursivo (Para operadores / nodos internos):
    // 1. Obtener la representación infija del operando/expresión izquierda
    std::string leftVal = convertToInfix(node->left);
    // 2. Obtener la representación infija del operando/expresión derecha
    std::string rightVal = convertToInfix(node->right);

    // 3. Concatenar la operación binaria actual entre paréntesis obligatorios
    return "(" + leftVal + " " + node->value + " " + rightVal + ")";
}

int main() {
    std::cout << "\n\e[0;35m[========= E18-PREFIJO-A-INFIJO =========]\e[0m\n\n";

    DrxArbinNode<std::string>* root = new DrxArbinNode<std::string>("*");
    root->left = new DrxArbinNode<std::string>("+");
    root->left->left = new DrxArbinNode<std::string>("A");
    root->left->right = new DrxArbinNode<std::string>("B");
    root->right = new DrxArbinNode<std::string>("C");

    std::cout << "Árbol de expresión cargado (Prefijo: * + A B C).\n";
    
    std::string infix = convertToInfix(root);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Expresión en notación infija parentizada: \e[1;33m" << infix << "\e[0m\n\n";

    delete root;
    return 0;
}
