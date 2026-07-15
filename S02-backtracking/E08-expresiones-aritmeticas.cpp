#include <iostream>

int totalCombinations = 0;

// Imprime la combinación de operadores y números que produce el objetivo.
void printCombination(const int numbers[], int numbersSize, int targetNumber, const char operations[]) {
    totalCombinations++;

    printf(" ∘ Combinación %d: \e[0;34m[\e[0m", totalCombinations);
    if (numbers[0] > 0) printf(" ");
    for (int i = 0; i < numbersSize; i++) {
        printf("\e[0m%d", numbers[i]);
        if (i != numbersSize - 1) {
            printf("\e[0;33m %c ", operations[i]);
        }
    }
    printf("\e[0;34m ]\e[0m = %d\n", targetNumber);
}


// Búsqueda recursiva por backtracking para encontrar combinaciones de operadores.
// Concepto Teórico (Generación de Combinaciones en un Conjunto de Operadores):
// Para N números, hay N - 1 espacios intermedios para colocar operadores. Esta función recorre 
// cada espacio en la posición 'index' y evalúa sistemáticamente las 4 opciones de operador (+, -, *, /).
// Se modela como un árbol de decisión cuaternario con una profundidad máxima de N.
void findCombinations(int targetNumber, const int numbers[], int numbersSize, int index, char operations[]) {
    // Caso base: Hemos seleccionado un operador para cada una de las posiciones posibles (index == numbersSize).
    // Ahora procedemos a evaluar la expresión resultante de izquierda a derecha para verificar si cumple la meta.
    if (index == numbersSize) {
        int result = numbers[0];
        for (int i = 1; i < numbersSize; i++) {
            switch (operations[i - 1]) {
                case '+': result += numbers[i]; break;
                case '-': result -= numbers[i]; break;
                case '*': result *= numbers[i]; break;
                case '/': 
                    // Restricción matemática (Poda): La división por cero es indefinida.
                    // Si el divisor es cero, descartamos esta rama de ejecución de inmediato.
                    if (numbers[i] == 0) return; 
                    result /= numbers[i]; // Nota: Se realiza una división entera truncada en C++
                    break;
            }
        }
        // Si el resultado de la evaluación coincide con el número objetivo, encontramos una solución válida
        if (result == targetNumber) {
            printCombination(numbers, numbersSize, targetNumber, operations);
        }
        return;
    }

    // Bucle de decisiones (Implícito en secuencia de llamadas):
    // Probamos cada uno de los 4 operadores disponibles. Dado que sobrescribimos el valor 
    // en la celda 'operations[index - 1]', la restauración del estado (Backtracking) es implícita, 
    // ya que no necesitamos limpiar el arreglo: la siguiente rama simplemente reemplazará el valor anterior.
    
    // 1. Probar suma
    operations[index - 1] = '+';
    findCombinations(targetNumber, numbers, numbersSize, index + 1, operations);
    
    // 2. Probar resta
    operations[index - 1] = '-';
    findCombinations(targetNumber, numbers, numbersSize, index + 1, operations);
    
    // 3. Probar multiplicación
    operations[index - 1] = '*';
    findCombinations(targetNumber, numbers, numbersSize, index + 1, operations);
    
    // 4. Probar división
    operations[index - 1] = '/';
    findCombinations(targetNumber, numbers, numbersSize, index + 1, operations);
}


int main() {
    std::cout << "\n\e[0;35m[========= E08-EXPRESIONES-ARITMETICAS =========]\e[0m\n\n";

    int initialCount = 0, targetNumber = 0;

    std::cout << "Ingrese el número inicial: ";
    if (!(std::cin >> initialCount)) return 1;

    std::cout << "Ingrese el número objetivo: ";
    if (!(std::cin >> targetNumber)) return 1;

    if (initialCount < 1) {
        printf("\n\e[1;31m[ERROR]\e[0m El número inicial debe ser mayor a 0.\n");
        return 1;
    }

    int* numbers = new int[initialCount];
    for (int i = 0; i < initialCount; i++) {
        numbers[i] = i + 1;
    }
    char* operations = new char[initialCount];

    printf("\n");
    findCombinations(targetNumber, numbers, initialCount, 1, operations);
    numbers[0] *= -1; // Probar si el primer número es negativo
    findCombinations(targetNumber, numbers, initialCount, 1, operations);

    printf("\n\e[1;32m[RESULTADO]\e[0m Total de combinaciones: %d\n\n", totalCombinations);

    delete[] numbers;
    delete[] operations;
    return 0;
}
