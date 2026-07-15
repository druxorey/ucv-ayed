#include <iostream>

// Función recursiva para invertir los dígitos de un número.
// Concepto Teórico (Acumulador y Recursión de Cola):
// Para invertir un número, extraemos progresivamente su último dígito (usando número % 10) 
// y lo insertamos al final del número invertido acumulado. 
// El parámetro 'inverted' actúa como un acumulador que guarda el estado parcial del resultado.
// Al pasar el acumulador en la firma y retornar la llamada recursiva directamente sin operaciones pendientes,
// este algoritmo tiene la forma de recursión de cola (tail recursion), permitiendo optimización de espacio O(1).
int invertNumber(int number, int inverted = 0) {
    // Caso base: Cuando el número original queda reducido a 0 tras sucesivas divisiones, 
    // significa que todos sus dígitos han sido procesados. Se retorna el acumulador 'inverted'.
    if (number == 0) return inverted;

    // Caso recursivo:
    // 1. 'number / 10' reduce el número original eliminando su dígito de las unidades (menos significativo).
    // 2. '(inverted * 10) + (number % 10)' desplaza a la izquierda (decenas, centenas...) el resultado
    //    acumulado hasta el momento para abrirle espacio al dígito actual (number % 10) en las unidades.
    return invertNumber(number / 10, (inverted * 10) + (number % 10));
}


int main() {
    std::cout << "\n\e[0;35m[========= E16-INVERTIR-DIGITOS-RECURSIVO =========]\e[0m\n\n";

    int number;
    std::cout << "Ingrese un número: ";
    if (!(std::cin >> number)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    printf("\e[1;32m[RESULTADO]\e[0m El número invertido es: %d.\n\n", invertNumber(number));

    return 0;
}
