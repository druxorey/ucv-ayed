#include <iostream>

const int DIGITS_SIZE = 9;
const int DIGITS[DIGITS_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// Verifica si el número formado cumple con la regla de divisibilidad secuencial.
// Concepto Teórico (Restricción de Divisibilidad Gradual):
// Un número de M cifras cumple con la propiedad si el número formado por sus primeras 'i' cifras 
// es divisible por 'i', para todo 1 <= i <= M.
// Evaluamos de derecha a izquierda: dividimos sucesivamente el número entre 10 para comprobar
// cada prefijo de tamaño 'i' frente a su divisibilidad por 'i'.
bool isValidCombination(int actualCombination) {
    int temp = actualCombination;
    int length = 0;
    
    // Obtener la cantidad de cifras del número (longitud)
    while (temp > 0) {
        length++;
        temp /= 10;
    }

    // Comprobamos la divisibilidad de cada prefijo
    // Por ejemplo, para 123 (longitud 3): comprobamos 123 % 3 == 0, luego 12 % 2 == 0.
    for (int i = length; i > 1; i--) {
        if (actualCombination % i != 0) return false; // Poda temprana si no cumple la regla para algún prefijo
        actualCombination /= 10; // Elimina el último dígito para comprobar el prefijo anterior
    }

    return true; // Si pasó todas las pruebas, la combinación completa es válida
}

// Genera combinaciones recursivas de dígitos únicos usando Backtracking.
// Concepto Teórico (Espacio de Búsqueda Con Restricciones):
// Construimos el número dígito a dígito de izquierda a derecha. Usamos un arreglo de frecuencia
// 'digitCount' como estructura auxiliar para implementar la restricción de unicidad (no repetir dígitos).
void generateCombinations(int maxNumber, int &totalCombinations, int currentNumber, int digitCount[]) {
    // Caso base: Si 'currentNumber' supera a 'maxNumber' (que es 10^(maxDigits-1)), significa que 
    // ya hemos construido un número con la cantidad de dígitos requerida.
    // Verificamos si este número es válido según la regla de divisibilidad secuencial.
    if (currentNumber > maxNumber) {
        if (isValidCombination(currentNumber)) {
            totalCombinations++;
            printf(" ∘ Combinación \e[0;33m%d\e[0m: %d\n", totalCombinations, currentNumber);
        }
        return;
    }

    // Bucle de decisiones: Probar cada dígito del 1 al 9 para la posición actual
    for (int i = 0; i < DIGITS_SIZE; i++) {
        int digit = DIGITS[i];

        // Restricción: Solo podemos usar el dígito si no ha sido usado en niveles anteriores del árbol de decisión
        if (digitCount[digit] == 0) {
            // 1. Tomar decisión: Marcar el dígito como usado y agregarlo al extremo derecho de nuestro número.
            digitCount[digit]++;
            
            // 2. Explorar recursivamente: Intentar colocar el siguiente dígito en la siguiente posición
            generateCombinations(maxNumber, totalCombinations, currentNumber * 10 + digit, digitCount);
            
            // 3. Deshacer decisión (Backtracking): Desmarcar el dígito para que pueda ser utilizado
            //    en otras ramas del árbol de búsqueda.
            digitCount[digit]--; 
        }
    }
}

int main() {
    std::cout << "\n\e[0;35m[========= E07-NUMEROS-M-CIFRAS =========]\e[0m\n\n";

    int maxDigits;
    int totalCombinations = 0;

    std::cout << "Ingrese el número máximo de dígitos: ";
    if (!(std::cin >> maxDigits)) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Entrada inválida.\n\n";
        return 1;
    }

    if (maxDigits <= 0 || maxDigits > 9) {
        std::cerr << "\e[1;31m[ERROR]\e[0m El número de dígitos debe estar en el rango [1, 9].\n\n";
        return 1;
    }

    // Calcular potencia de 10 de forma manual
    int maxNumber = 1;
    for (int i = 0; i < maxDigits - 1; i++) {
        maxNumber *= 10;
    }

    std::cout << "\n";
    int digitCount[10] = {0};
    generateCombinations(maxNumber, totalCombinations, 0, digitCount);

    printf("\n\e[1;32m[RESULTADO]\e[0m El total de combinaciones válidas es: %d\n\n", totalCombinations);

    return 0;
}
