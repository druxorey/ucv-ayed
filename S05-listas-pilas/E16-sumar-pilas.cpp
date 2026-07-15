#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"

// Realiza la suma de números grandes representados en pilas.
// Realiza la suma de números grandes representados en pilas.
// Concepto Teórico (Uso del comportamiento LIFO para Aritmética de Precisión Arbitraria):
// Los dígitos de los números grandes se leen de izquierda a derecha y se apilan en P1 y P2. 
// Debido al comportamiento LIFO (Last In, First Out) de las pilas, el dígito menos significativo 
// (las unidades, que ingresó de último) queda al tope de la pila. 
// Esto nos permite sumar los números de derecha a izquierda (unidades, decenas, centenas...) de forma 
// análoga a como lo hacemos a mano, acumulando el acarreo ('carry') y construyendo el resultado 
// en la pila P3 (donde el dígito más significativo quedará al tope y se podrá mostrar en orden correcto).
DrxStack<int> sumStacks(DrxStack<int> P1, DrxStack<int> P2) {
    DrxStack<int> P3;
    int carry = 0; // Almacena el valor acarreado (0 o 1 en base 10)

    // El proceso continúa mientras existan dígitos por procesar en alguna de las dos pilas 
    // o haya un acarreo pendiente por colocar al final de la suma.
    while (!P1.isEmpty() || !P2.isEmpty() || carry > 0) {
        int sum = carry; // Comenzar la suma con el acarreo previo

        // Sumar y desapilar el dígito de la primera pila
        if (!P1.isEmpty()) {
            sum += P1.top();
            P1.pop();
        }

        // Sumar y desapilar el dígito de la segunda pila
        if (!P2.isEmpty()) {
            sum += P2.top();
            P2.pop();
        }

        carry = sum / 10;          // Calcular el nuevo acarreo (división entera por 10)
        int resultDigit = sum % 10; // Extraer el dígito del resultado (residuo de 10)
        P3.push(resultDigit);      // Apilar el dígito en P3
    }

    return P3;
}


int main() {
    std::cout << "\n\e[0;35m[========= E16-SUMAR-PILAS =========]\e[0m\n\n";

    char numStr1[100];
    char numStr2[100];
    std::cout << "Introduce el primer número entero positivo: ";
    if (!(std::cin >> numStr1)) return 1;

    std::cout << "Introduce el segundo número entero positivo: ";
    if (!(std::cin >> numStr2)) return 1;

    DrxStack<int> P1, P2;

    for (int i = 0; numStr1[i] != '\0'; i++) {
        char c = numStr1[i];
        if (c >= '0' && c <= '9') {
            P1.push(c - '0');
        }
    }

    for (int i = 0; numStr2[i] != '\0'; i++) {
        char c = numStr2[i];
        if (c >= '0' && c <= '9') {
            P2.push(c - '0');
        }
    }

    DrxStack<int> P3 = sumStacks(P1, P2);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m La suma representada en la pila resultante es:\n";
    P3.print();
    std::cout << "\n";

    return 0;
}
