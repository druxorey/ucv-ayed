#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"
#include "../S99-implementaciones/drxstack.hpp"

// Función que define la precedencia de los operadores.
int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


// Verifica si un carácter es un operador.
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


// Algoritmo para transformar expresión infija (en lista) a prefija (en pila).
// Algoritmo para transformar expresión infija (en lista) a prefija (en pila).
// Concepto Teórico (Algoritmo Shunting-Yard Inverso para Notación Prefija):
// Para convertir infijo a prefijo de manera iterativa sin revertir cadenas al final:
// 1. Recorremos la expresión infija de derecha a izquierda.
// 2. Los operandos se añaden directamente al frente del resultado (prefixList).
// 3. Los paréntesis se tratan al revés: el paréntesis de cierre ')' se apila directamente, 
//    y el de apertura '(' vacía la pila de operadores hasta encontrar su correspondiente ')'.
// 4. Los operadores desapilan de la pila de operadores a la lista de salida mientras tengan
//    mayor precedencia estricta que el operador actual.
// 5. El resultado acumulado en 'prefixList' se copia en una pila para su posterior evaluación.
DrxStack<char> infixToPolish(const DrxList<char>& infixList) {
    DrxStack<char> operatorStack;
    DrxList<char> prefixList;

    // Recorremos la lista infija de derecha a izquierda (reversa)
    typename DrxList<char>::Iterator it = infixList.last();
    while (it != infixList.end()) {
        char* valPtr = infixList.get(it);
        if (valPtr != nullptr) {
            char c = *valPtr;

            // Operando: Insertar al principio de la lista de salida
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                prefixList.pushFront(c);
            } 
            // Paréntesis de cierre: Apilar en la pila de operadores
            else if (c == ')') {
                operatorStack.push(c);
            } 
            // Paréntesis de apertura: Desapilar operadores hasta el paréntesis de cierre simétrico
            else if (c == '(') {
                while (!operatorStack.isEmpty() && operatorStack.top() != ')') {
                    prefixList.pushFront(operatorStack.top());
                    operatorStack.pop();
                }
                if (!operatorStack.isEmpty()) operatorStack.pop(); // Desapilar y descartar el ')'
            } 
            // Operador aritmético
            else if (isOperator(c)) {
                // Desapilar operadores con precedencia estrictamente mayor
                while (!operatorStack.isEmpty() && getPrecedence(operatorStack.top()) > getPrecedence(c)) {
                    prefixList.pushFront(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.push(c); // Apilar el operador actual
            }
        }
        infixList.prev(it); // Avanzar hacia la izquierda de la lista
    }

    // Vaciar los operadores restantes al frente de la salida
    while (!operatorStack.isEmpty()) {
        prefixList.pushFront(operatorStack.top());
        operatorStack.pop();
    }

    // Empaquetar la lista resultante de caracteres en una pila para que el primer carácter
    // de la notación prefija quede en el tope de la pila.
    DrxStack<char> polishStack;
    typename DrxList<char>::Iterator pit = prefixList.last();
    while (pit != prefixList.end()) {
        char* valPtr = prefixList.get(pit);
        if (valPtr != nullptr) {
            polishStack.push(*valPtr);
        }
        prefixList.prev(pit);
    }

    return polishStack;
}


// Algoritmo para evaluar una expresión en notación polaca (prefija) almacenada en una pila.
// Concepto Teórico (Evaluación de Expresiones Prefijas de Derecha a Izquierda):
// Para evaluar una expresión prefija, la recorremos de derecha a izquierda (de final a inicio).
// 1. Si encontramos un operando, lo apilamos en la pila de operandos.
// 2. Si encontramos un operador, desapilamos los dos operandos superiores, aplicamos el operador,
//    y apilamos el resultado de vuelta. 
//    Nota: En notación prefija leída de derecha a izquierda, el primer elemento desapilado es el operando izquierdo (op1)
//    y el segundo es el operando derecho (op2).
//    Para lograr el recorrido de derecha a izquierda, primero invertimos la pila original 'P' en 'P_reverse'.
int evaluatePolish(DrxStack<char> P) {
    DrxStack<int> operands;
    
    // Invertir la pila original para simular el recorrido de derecha a izquierda
    DrxStack<char> P_reverse;
    while (!P.isEmpty()) {
        P_reverse.push(P.top());
        P.pop();
    }

    // Procesar la expresión de derecha a izquierda
    while (!P_reverse.isEmpty()) {
        char token = P_reverse.top();
        P_reverse.pop();

        // Si es operando numérico, convertir de char a entero y apilar
        if (token >= '0' && token <= '9') {
            operands.push(token - '0');
        } 
        // Si es operador, realizar la operación correspondiente con los dos operandos tope
        else if (isOperator(token)) {
            if (operands.size() < 2) {
                return 0; // Error de sintaxis en la expresión
            }
            int op1 = operands.top(); operands.pop(); // Operando izquierdo
            int op2 = operands.top(); operands.pop(); // Operando derecho

            int result = 0;
            switch (token) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0) return 0; // Evitar división por cero
                    result = op1 / op2; 
                    break;
            }
            operands.push(result); // Apilar el resultado del cálculo
        }
    }

    return operands.top(); // El resultado final queda al tope de la pila de operandos
}


int main() {
    std::cout << "\n\e[0;35m[========= E20-NOTACION-POLACA =========]\e[0m\n\n";

    const char* infixExpr = "(5+3)*2";
    DrxList<char> infixList;
    for (int i = 0; infixExpr[i] != '\0'; i++) {
        infixList.pushBack(infixExpr[i]);
    }

    std::cout << "Expresión infija inicial en la lista: " << infixExpr << "\n";

    DrxStack<char> polishStack = infixToPolish(infixList);

    std::cout << "\nExpresión en notación polaca (prefija) generada en la pila:\n";
    polishStack.print();

    int result = evaluatePolish(polishStack);
    printf("\n\e[1;32m[RESULTADO]\e[0m La evaluación de la expresión prefija es: %d\n\n", result);

    return 0;
}
