#include <iostream>

// Función recursiva para calcular el Máximo Común Divisor (MCD) utilizando el método de restas de Euclides.
// Concepto Teórico (Algoritmo de Euclides):
// Se basa en el teorema que establece que si un número entero divide a 'a' y a 'b', 
// también divide a su diferencia (a - b). Por lo tanto, el MCD no cambia si se resta el número menor al mayor.
// Concepto Teórico (Recursión de Cola / Tail Recursion):
// Esta función es un ejemplo de recursión de cola, ya que la llamada recursiva es la última instrucción
// que se ejecuta en la función y no deja operaciones aritméticas pendientes por realizar tras su retorno.
int getGcd(int a, int b) {
    // Caso base: Si ambos números son iguales, el divisor común más grande posible es el mismo número.
    // Detiene la recursión retornando cualquiera de los dos.
    if (a == b) return a;

    // Caso recursivo 1: Si 'a' es mayor que 'b', el MCD de (a, b) es equivalente al MCD de (a - b, b).
    // Reducimos el primer parámetro restándole el segundo.
    if (a > b) return getGcd(a - b, b);

    // Caso recursivo 2: Si 'b' es mayor que 'a', el MCD de (a, b) es equivalente al MCD de (a, b - a).
    // Reducimos el segundo parámetro restándole el primero.
    return getGcd(a, b - a);
}


int main() {
    std::cout << "\n\e[0;35m[========= E10-MAXIMO-COMUN-DIVISOR =========]\e[0m\n\n";

    int a = 0, b = 0;

    std::cout << "Ingrese el primer número: ";
    if (!(std::cin >> a)) return 1;

    std::cout << "Ingrese el segundo número: ";
    if (!(std::cin >> b)) return 1;

    if (a <= 0 || b <= 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Los números deben ser mayores que cero.\n\n";
        return 1;
    }

    printf("\e[1;32m[RESULTADO]\e[0m El MCD de %d y %d es: %d.\n\n", a, b, getGcd(a, b));

    return 0;
}
