#include <iostream>

// Alias de tipo para enteros grandes sin signo
typedef unsigned long long int u64;

// Solución recursiva para calcular el coeficiente binomial C(n, k).
// Este cálculo modela matemáticamente el número de formas de elegir k elementos
// de un conjunto de n elementos sin importar el orden.
u64 getCombinatorics(int n, int k) {
    // Casos base:
    // 1. C(n, 0) = 1: Solo hay 1 forma de elegir 0 elementos (no elegir ninguno).
    // 2. C(n, n) = 1: Solo hay 1 forma de elegir todos los n elementos (elegir el conjunto completo).
    // Ambos casos representan las hojas del árbol de llamadas recursivas y detienen la recursión.
    if (k == 0 || k == n) return 1;

    // Relación de recurrencia (Identidad de Pascal):
    // C(n, k) = C(n-1, k-1) + C(n-1, k)
    // Concepto teórico: Para un elemento particular, podemos:
    // a) Incluirlo: nos queda elegir k-1 elementos de los n-1 restantes -> C(n-1, k-1).
    // b) Excluirlo: nos queda elegir k elementos de los n-1 restantes -> C(n-1, k).
    // La suma de estas dos decisiones disjuntas cubre todas las posibilidades.
    return getCombinatorics(n - 1, k - 1) + getCombinatorics(n - 1, k);
}


int main() {
    std::cout << "\n\e[0;35m[========= E05-COMBINATORIA =========]\e[0m\n\n";

    int n, k;

    std::cout << "Introduce el valor de n: ";
    if (!(std::cin >> n)) return 1;

    std::cout << "Introduce el valor de k: ";
    if (!(std::cin >> k)) return 1;

    if (k > n || n < 0 || k < 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Parámetros inválidos para combinatoria.\n\n";
        return 1;
    }

    u64 combinatorics = getCombinatorics(n, k);

    printf("\n\e[1;32m[RESULTADO]\e[0m La combinatoria de %d y %d es: %llu.\n\n", n, k, combinatorics);

    return 0;
}
