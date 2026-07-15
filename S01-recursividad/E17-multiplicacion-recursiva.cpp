#include <iostream>

// Función recursiva para realizar la multiplicación de dos números mediante sumas sucesivas.
// Concepto Teórico (Multiplicación Inductiva):
// La multiplicación a * b puede definirse recursivamente como sumar 'a' un número 'b' de veces:
// a * b = a + a * (b - 1) para b > 0.
int multiply(int a, int b) {
    // Caso base principal: Cualquier número multiplicado por 0 es 0. 
    // Detiene la recursión cuando el multiplicador b llega a cero.
    if (b == 0) return 0;

    // Manejo de signos (Álgebra de signos recursiva):
    // Si el multiplicador 'b' es negativo, aprovechamos la propiedad: a * b = -(a * -b).
    // Esto transforma a 'b' en un número positivo, permitiendo que la recursión converja hacia el caso base (cero).
    if (b < 0) return -multiply(a, -b);

    // Caso recursivo para b > 0:
    // Sumamos 'a' al resultado de calcular recursivamente la suma de 'a' multiplicada por 'b - 1'.
    // Esta es una recursión no de cola, pues la suma de 'a' queda pendiente por resolverse en la pila.
    return a + multiply(a, b - 1);
}


int main() {
    std::cout << "\n\e[0;35m[========= E17-MULTIPLICACION-RECURSIVA =========]\e[0m\n\n";

    int a = 0, b = 0;

    std::cout << "Ingrese el primer número: ";
    if (!(std::cin >> a)) return 1;

    std::cout << "Ingrese el segundo número: ";
    if (!(std::cin >> b)) return 1;

    printf("\e[1;32m[RESULTADO]\e[0m El resultado de %d * %d es: %d.\n\n", a, b, multiply(a, b));

    return 0;
}
