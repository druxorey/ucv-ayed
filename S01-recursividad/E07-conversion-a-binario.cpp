#include <iostream>

// Función recursiva auxiliar para imprimir la representación hexadecimal de un número.
// Concepto Teórico (Pila de llamadas y Orden de Impresión):
// Los residuos sucesivos obtenidos mediante modulo (%) calculan los dígitos hexadecimales 
// de derecha a izquierda (desde el menos significativo al más significativo). Sin embargo, 
// para mostrarlos correctamente, deben imprimirse de izquierda a derecha.
// Usamos recursividad de cabeza (head recursion): la llamada recursiva ocurre antes de la 
// impresión de la cifra actual. Así, la pila de ejecución de C++ almacena los dígitos temporalmente 
// y los imprime en orden inverso al que se calcularon cuando las llamadas recursivas retornan (desapilado).
void printHexadecimal(int number) {
    // Caso base: Detiene la recursión cuando el cociente sucesivo es cero.
    if (number == 0) return;

    // Llamada recursiva con el cociente de la división por 16. Reduce el problema
    // eliminando el dígito menos significativo actual en base 16.
    printHexadecimal(number / 16);
    
    // Al desapilar (de regreso del caso base), se imprime el residuo correspondiente.
    // Esto asegura que el dígito más significativo se imprima primero.
    const char hexDigits[] = "0123456789ABCDEF";
    std::cout << hexDigits[number % 16];
}


// Función recursiva para calcular la representación binaria de un número.
// Devuelve la representación binaria empaquetada dentro de un entero decimal (ej. 5 -> 101).
int calculateBinary(int number) {
    // Caso base: El número 0 tiene representación binaria 0. Detiene la recursión.
    if (number == 0) return 0;

    // Paso recursivo y Reconstrucción Matemática:
    // 1. (number % 2) obtiene el bit actual (0 o 1), que es el residuo de dividir por la base (2).
    // 2. calculateBinary(number / 2) calcula recursivamente el valor binario del resto del número (cociente).
    // 3. Multiplicar por 10 desplaza los dígitos binarios ya calculados un lugar decimal a la izquierda
    //    (ej. de 10 a 100), dejando espacio en las unidades para colocar el bit actual (number % 2).
    return (number % 2) + 10 * calculateBinary(number / 2);
}


int main() {
    std::cout << "\n\e[0;35m[========= E07-CONVERSION-A-BINARIO =========]\e[0m\n\n";

    // Declaración de variables para almacenar el número inicial
    int initialNumber = 0;

    // Solicita al usuario ingresar un número decimal
    std::cout << "Ingrese el valor decimal inicial: ";
    std::cin >> initialNumber;

    // Calcula y muestra la conversión a binario
    std::cout << "\n\e[1;32m[RESULTADO]\e[0m El número en binario es: " << calculateBinary(initialNumber);

    // Calcula y muestra la conversión a hexadecimal
    std::cout << "\n\e[1;32m[RESULTADO]\e[0m El número en hexadecimal es: ";
    if (initialNumber == 0) {
        std::cout << "0";
    } else {
        printHexadecimal(initialNumber);
    }
    std::cout << "\n\n";

    // Finaliza el programa
    return 0;
}
