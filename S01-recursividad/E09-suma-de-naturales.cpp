#include <iostream>

typedef unsigned long long int u64;

// Función recursiva para calcular la suma de los primeros n números naturales.
// Concepto Teórico (Recursión Lineal):
// La suma de los primeros n números naturales se define inductivamente como:
// S(n) = n + S(n-1) para n > 0, con S(0) = 0.
u64 sumNaturals(int size) {
    // Caso base: Si size <= 0, retornamos 0.
    // Teóricamente, el 0 es el elemento neutro de la suma. Además, esta condición 
    // establece el límite inferior del dominio de los números naturales del problema 
    // y detiene la propagación de llamadas recursivas en la pila.
    if (size <= 0) return 0;

    // Caso recursivo:
    // El problema de sumar 'size' elementos se reduce a tomar el valor actual 'size'
    // y sumarlo al resultado de calcular recursivamente la suma de los 'size - 1' elementos restantes.
    // Nota: Esta es una recursión no de cola (non-tail recursion), ya que la operación de suma 
    // queda pendiente en la pila de llamadas hasta que retorne sumNaturals(size - 1).
    return size + sumNaturals(size - 1);
}


int main() {
    std::cout << "\n\e[1;35m[========= E09-SUMA-DE-NATURALES =========]\e[0m\n\n";

    int size = 0;
    std::cout << "Ingrese la cantidad de números naturales a sumar: ";
    if (!(std::cin >> size)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    printf("\e[1;32m[RESULTADO]\e[0m La suma de todos los números naturales es: %llu.\n\n", sumNaturals(size));

    return 0;
}
