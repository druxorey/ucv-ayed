#include <iostream>

// Función recursiva para verificar si una cadena es un palíndromo (capicúa).
// Concepto Teórico (Estrategia de dos punteros/índices en recursión):
// Para verificar si una cadena es capicúa, comparamos los caracteres simétricos desde 
// los extremos hacia el centro. Si todos los pares extremos coinciden, la palabra es un palíndromo.
bool isPalindrome(const char input[], int start, int end) {
    // Casos base:
    // 1. start == end: Llegamos al carácter central en una palabra de longitud impar (ej. "oso", 's' en pos 1).
    // 2. start > end: Los índices se cruzaron en una palabra de longitud par (ej. "dada", todos los pares coincidieron).
    // En ambos casos, se verificó exitosamente la simetría de toda la cadena, por lo que retorna true.
    if (start >= end) return true;

    printf("\e[1;33m[INFO]\e[0m Comparando '%c' con '%c'...\n", input[start], input[end]);

    // Caso recursivo:
    // Si los caracteres en los extremos actuales coinciden, reducimos el tamaño del problema:
    // avanzamos el índice 'start' hacia la derecha (start + 1) y retrocedemos 'end' hacia la izquierda (end - 1)
    // para verificar el siguiente par interno de caracteres.
    if (input[start] == input[end]) {
        return isPalindrome(input, start + 1, end - 1);
    }

    // Poda temprana: Si algún par de caracteres no coincide, la palabra no puede ser capicúa, 
    // por lo que detenemos las llamadas recursivas inmediatamente retornando false.
    return false;
}


int main() {
    std::cout << "\n\e[0;35m[========= E08-PALABRA-CAPICUA =========]\e[0m\n\n";

    char input[256];
    std::cout << "Ingrese una palabra: ";
    if (!(std::cin >> input)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    printf("\n\e[1;34mVerificando si la palabra es capicúa...\e[0m\n\n");

    // Calcular longitud de forma manual para evitar dependencias
    int length = 0;
    while (input[length] != '\0') {
        length++;
    }

    if (isPalindrome(input, 0, length - 1)) {
        printf("\n\e[1;32m[RESULTADO]\e[0m La palabra ingresada es capicúa.\n\n");
    } else {
        printf("\n\e[1;31m[RESULTADO]\e[0m La palabra ingresada no es capicúa.\n\n");
    }

    return 0;
}
