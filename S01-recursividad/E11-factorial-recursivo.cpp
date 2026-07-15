#include <iostream>

typedef unsigned long long int u64;

// Función recursiva para calcular el factorial de un número entero n.
// Concepto Teórico (Crecimiento y Pila de Recursión):
// El factorial se define inductivamente como: n! = n * (n - 1)! para n > 0, y 0! = 1.
// Al no ser una recursión de cola (non-tail recursion), cada llamada recursiva deja una multiplicación
// pendiente en la pila de ejecución de C++. Esto requiere O(n) espacio en memoria para almacenar
// las tramas de activación asociadas a los valores de 'n' correspondientes a cada nivel.
u64 getFactorial(u64 n) {
    // Caso base: El factorial de 0 se define por convención matemática como 1.
    // Representa el caso de parada más simple del problema.
    if (n == 0) return 1;

    // Caso recursivo:
    // El cálculo del factorial de 'n' se suspende temporalmente hasta resolver recursivamente
    // el factorial de 'n - 1'. Una vez obtenido este resultado, se multiplica por 'n' actual
    // conforme se desapilan las llamadas de la pila de ejecución.
    return n * getFactorial(n - 1);
}


int main() {
    std::cout << "\n\e[0;35m[========= E11-FACTORIAL-RECURSIVO =========]\e[0m\n\n";

    short int number;
    std::cout << "Ingrese un número: ";
    if (!(std::cin >> number)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    if (number < 0) {
        printf("\e[1;31m[ERROR]\e[0m El factorial de %d no está definido.\n\n", number);
        return 1;
    }

    if (number >= 21) {
        printf("\e[1;33m[ADVERTENCIA]\e[0m El factorial de %d es demasiado grande para calcularse.\n\n", number);
        return 0;
    }

    u64 factorial = getFactorial(number);

    printf("\e[1;32m[RESULTADO]\e[0m El factorial de %d es: %llu.\n\n", number, factorial);

    return 0;
}
