#include <iostream>

typedef unsigned long long int u64;

// Función recursiva con memoización para obtener el n-ésimo número de Fibonacci.
// La recursión simple para Fibonacci tiene una complejidad de tiempo exponencial O(2^n) 
// debido a la redundancia en el cálculo de los mismos subproblemas múltiples veces.
// Mediante la técnica de Memoización (enfoque Top-Down de Programación Dinámica), 
// guardamos los resultados ya computados en un arreglo auxiliar. Esto reduce la 
// complejidad de tiempo a O(n) al calcular cada número de Fibonacci exactamente una vez.
u64 getFibonacci(u64 n, u64 memo[]) {
    // Caso base: F(0) = 0 y F(1) = 1. Estos valores no requieren cálculo
    // y definen la condición de parada de la recursión.
    if (n <= 1) return n;

    // Búsqueda en caché: Si el valor de F(n) ya fue calculado previamente 
    // (es decir, el elemento en el arreglo es diferente de 0), retornamos
    // directamente el resultado en tiempo constante O(1), evitando llamadas recursivas adicionales.
    if (memo[n] != 0) return memo[n];

    // Caso recursivo con almacenamiento: Si F(n) no ha sido calculado, 
    // resolvemos recursivamente para (n-1) y (n-2), y guardamos la suma en 'memo[n]' 
    // antes de retornarlo para que esté disponible para futuras subconsultas.
    memo[n] = getFibonacci(n - 1, memo) + getFibonacci(n - 2, memo);
    return memo[n];
}


int main() {
    std::cout << "\n\e[0;35m[========= E06-FIBONACCI-RECURSIVO =========]\e[0m\n\n";

    u64 number;
    u64 memo[200] = {0}; // Arreglo de memoización inicializado en 0

    std::cout << "Ingrese un número: ";
    if (!(std::cin >> number)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    if (number > 199) {
        printf("\e[1;31m[ERROR]\e[0m El Fibonacci de %lld es demasiado grande para calcularse.\n\n", number);
        return 1;
    }

    printf("\e[1;32m[RESULTADO]\e[0m El Fibonacci de %lld es: %lld.\n\n", number, getFibonacci(number, memo));

    return 0;
}
