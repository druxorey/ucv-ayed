#include <iostream>

bool isOdd(int n);
bool isEven(int n);

// Verifica recursivamente si un número es impar.
// Concepto Teórico (Recursión Mutua / Cruzada):
// Dos o más funciones se llaman mutuamente para resolver un problema de forma coordinada.
// Inducción matemática de paridad:
// - 0 no es impar (retorna false).
// - Un número n es impar si y solo si n - 1 (o n + 1 si es negativo) es par.
bool isOdd(int n) {
    // Caso base: 0 es par por definición, por tanto no es impar. Retorna false.
    if (n == 0) return false;

    // Llamada recursiva mutua: Delegamos el problema a isEven reduciendo el valor absoluto en 1
    // (restando 1 si es positivo, sumando 1 si es negativo) para converger hacia el caso base 0.
    return isEven(n > 0 ? n - 1 : n + 1);
}

// Verifica recursivamente si un número es par.
// Concepto Teórico (Recursión Mutua / Cruzada):
// - 0 es par por definición (retorna true).
// - Un número n es par si y solo si n - 1 (o n + 1 si es negativo) es impar.
bool isEven(int n) {
    // Caso base: 0 es par por definición. Retorna true.
    if (n == 0) return true;

    // Llamada recursiva mutua: Delegamos el problema a isOdd reduciendo el valor absoluto en 1
    // para converger hacia el caso base 0.
    return isOdd(n > 0 ? n - 1 : n + 1);
}


int main() {
    std::cout << "\n\e[0;35m[========= E18-PARIDAD-RECURSIVA =========]\e[0m\n\n";

    int a = 0;
    std::cout << "Ingrese un número: ";
    if (!(std::cin >> a)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    printf("\e[1;32m[RESULTADO]\e[0m El número %d es %s.\n\n", a, isEven(a) ? "par" : "impar");

    return 0;
}
