#include <iostream>

typedef long double f80;

// Función recursiva para calcular la potencia de un número utilizando la Exponenciación Binaria (o por cuadrados).
// Concepto Teórico (Optimización Logarítmica O(log n)):
// En lugar del enfoque ingenuo de multiplicar la base n veces (complejidad O(n)), la exponenciación binaria
// reduce el exponente a la mitad en cada paso cuando este es par. Esto reduce la complejidad temporal a O(log n).
f80 getPower(f80 base, int exponent) {
    // Caso base: Cualquier número base diferente de cero elevado a la potencia de 0 es igual a 1 (x^0 = 1).
    // Esto finaliza las llamadas recursivas.
    if (exponent == 0) return 1;

    // Caso recursivo para exponente impar:
    // Si el exponente actual es impar, separamos un factor de la base para convertir el exponente
    // restante en par: x^n = x * x^(n-1).
    if (exponent > 0 && exponent % 2 == 1) {
        return base * getPower(base, exponent - 1);
    }

    // Caso recursivo para exponente par (implícito debido a la instrucción anterior):
    // Si el exponente actual es par, podemos reagrupar la base: x^n = (x^2)^(n/2).
    // Esto duplica la base y divide el exponente a la mitad, logrando la reducción logarítmica.
    return getPower(base * base, exponent / 2);
}


int main() {
    std::cout << "\n\e[0;35m[========= E12-POTENCIA-REAL =========]\e[0m\n\n";

    f80 base = 0.0;
    unsigned int exponent = 0;

    std::cout << "Ingrese la base: ";
    if (!(std::cin >> base)) return 1;

    std::cout << "Ingrese el exponente: ";
    if (!(std::cin >> exponent)) return 1;

    printf("\e[1;32m[RESULTADO]\e[0m %.2Lf elevado a la potencia de %d es: %.8Lf.\n\n", base, exponent, getPower(base, exponent));

    return 0;
}
