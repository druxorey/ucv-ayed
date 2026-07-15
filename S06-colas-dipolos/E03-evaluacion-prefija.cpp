#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"
#include "../S99-implementaciones/drxstack.hpp"

struct Token {
    bool isOp;
    char op;
    double val;
};


// Parsea una cadena en una lista de tokens.
void parseExpression(const char* expr, DrxList<Token>& tokenList) {
    int i = 0;
    while (expr[i] != '\0') {
        // Ignorar espacios en blanco
        while (expr[i] == ' ' || expr[i] == '\t' || expr[i] == '\r' || expr[i] == '\n') {
            i++;
        }
        if (expr[i] == '\0') break;

        // Leer token
        int start = i;
        while (expr[i] != '\0' && expr[i] != ' ' && expr[i] != '\t' && expr[i] != '\r' && expr[i] != '\n') {
            i++;
        }
        int len = i - start;

        // Evaluar token
        Token t;
        if (len == 1 && (expr[start] == '+' || expr[start] == '-' || expr[start] == '*' || expr[start] == '/')) {
            t.isOp = true;
            t.op = expr[start];
            t.val = 0.0;
        } else {
            t.isOp = false;
            t.op = '\0';
            
            // Convertir token a double manualmente
            double value = 0.0;
            double fraction = 0.0;
            double divisor = 10.0;
            bool negative = false;
            int idx = start;
            if (expr[idx] == '-') {
                negative = true;
                idx++;
            } else if (expr[idx] == '+') {
                idx++;
            }
            while (idx < i && expr[idx] >= '0' && expr[idx] <= '9') {
                value = value * 10.0 + (expr[idx] - '0');
                idx++;
            }
            if (idx < i && expr[idx] == '.') {
                idx++;
                while (idx < i && expr[idx] >= '0' && expr[idx] <= '9') {
                    fraction += (expr[idx] - '0') / divisor;
                    divisor *= 10.0;
                    idx++;
                }
            }
            t.val = negative ? -(value + fraction) : (value + fraction);
        }
        tokenList.pushBack(t);
    }
}


// Evalúa una expresión aritmética en notación prefija recorriendo de derecha a izquierda.
// Concepto Teórico (Evaluación de Notación Polaca/Prefija de Derecha a Izquierda):
// Para evaluar una expresión en formato prefijo (ej. "+ A B"):
// 1. Recorremos los tokens en orden inverso (de derecha a izquierda, empezando por el final).
// 2. Si el token es un operando numérico, se apila en la pila 'operands'.
// 3. Si el token es un operador, desapilamos los dos operandos superiores. El primer elemento desapilado
//    corresponde al operando izquierdo (op1) y el segundo al operando derecho (op2) de la operación binaria.
//    Se realiza la operación y el resultado se apila de vuelta.
// Al finalizar el recorrido, la pila de operandos debe contener exactamente un único elemento (el resultado final).
double evaluatePrefix(const DrxList<Token>& tokenList) {
    DrxStack<double> operands;
    typename DrxList<Token>::Iterator it = tokenList.last(); // Empezar por el final de la lista
    
    // Recorrido de derecha a izquierda
    while (it != tokenList.end()) {
        Token* t = tokenList.get(it);
        if (t != nullptr) {
            // Caso 1: Es un operador aritmético (+, -, *, /)
            if (t->isOp) {
                // Validación sintáctica: Deben existir al menos 2 operandos en la pila
                if (operands.size() < 2) {
                    throw "Expresión prefija inválida (operandos insuficientes)";
                }
                double op1 = operands.top(); operands.pop(); // Primer operando (izquierdo)
                double op2 = operands.top(); operands.pop(); // Segundo operando (derecho)
                double result = 0.0;
 
                // Aplicar operación correspondiente
                if (t->op == '+') result = op1 + op2;
                else if (t->op == '-') result = op1 - op2;
                else if (t->op == '*') result = op1 * op2;
                else if (t->op == '/') {
                    if (op2 == 0.0) throw "División por cero"; // Validación aritmética
                    result = op1 / op2;
                }
                operands.push(result); // Apilar el resultado
            } 
            // Caso 2: Es un operando numérico (constante flotante)
            else {
                operands.push(t->val); // Apilar el valor numérico
            }
        }
        tokenList.prev(it); // Mover el iterador hacia la izquierda
    }
 
    // Validación final: Solo debe quedar el resultado único de la expresión
    if (operands.size() != 1) {
        throw "Expresión prefija inválida (quedan operandos sin evaluar)";
    }
    return operands.top();
}


int main() {
    std::cout << "\n\e[0;35m[========= E03-EVALUACION-PREFIJA =========]\e[0m\n\n";
    std::cout << "Ingrese la expresión en notación prefija (tokens separados por espacios):\n";
    std::cout << "Ejemplo: * + 10 2 5\n\n> ";

    char expression[200];
    if (!std::cin.getline(expression, 200)) return 1;

    DrxList<Token> tokenList;
    parseExpression(expression, tokenList);

    try {
        double result = evaluatePrefix(tokenList);
        std::cout << "\n\e[1;32m[RESULTADO]\e[0m El resultado de la evaluación es: " << result << "\n\n";
    } catch (const char* e) {
        std::cout << "\n\e[1;31m[ERROR]\e[0m " << e << "\n\n";
    }

    return 0;
}
