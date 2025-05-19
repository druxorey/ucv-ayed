#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Función recursiva para calcular el Máximo Común Divisor (MCD) de dos números
int getGcd(int a, int b) {
    // Caso base: si ambos números son iguales, el MCD es ese número
    if (a == b) return a;
    // Si el primer número es mayor, se resta el segundo número del primero
    if (a > b) return getGcd(a - b, b);
    // Si el segundo número es mayor, se resta el primer número del segundo
    return getGcd(a, b - a);
}

int main() {
    std::cout << "\n\e[0;35m[========= E10-MAXIMO-COMUN-DIVISOR =========]\e[0m\n\n";

    int a = 0, b = 0;

    getcin("Ingrese el primer número: ", a);
    getcin("Ingrese el segundo número: ", b);

    // Calcular y mostrar el MCD de los dos números ingresados
    printf("\e[1;32m[RESULTADO]\e[0m El MCD de %d y %d es: %d.\n\n", a, b, getGcd(a, b));

    // Finalizar el programa con un código de retorno 0 (indica que todo salió bien)
    return 0;
}
