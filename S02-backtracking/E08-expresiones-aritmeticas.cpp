#include <iostream> // Biblioteca estándar para entrada y salida
#include <vector> // Biblioteca estándar para el uso de vectores
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Variable global para contar el total de combinaciones encontradas
int totalCombinations = 0;

// Función para imprimir una combinación que cumple con el número objetivo
void printCombination(int numbers[], int size, int targetNumber, std::vector<char> operations) {
	// Incrementa el contador de combinaciones
	totalCombinations++;

	// Imprime la combinación en formato legible
	printf(" ∘ Combinación %d: \e[0;34m[\e[0m", totalCombinations);
	if (numbers[0] > 0) printf(" ");
	for (int i = 0; i < size; i++) {
		printf("\e[0m%d", numbers[i]);
		if (i != size - 1) {
			printf("\e[0;33m %c ", operations[i]);
		}
	}
	printf("\e[0;34m ]\e[0m = %d\n", targetNumber);
}

// Función recursiva para encontrar todas las combinaciones posibles de operaciones
void findCombinations(int number, int targetNumber, int array[], int size, int index = 1, std::vector<char> operations = {}) {
	// Caso base: si se han asignado todas las operaciones
	if (index == size) {
		// Calcula el resultado de la combinación actual
		int result = array[0];
		for (int i = 1; i < size; i++) {
			switch (operations[i - 1]) {
				case '+': result += array[i]; break;
				case '-': result -= array[i]; break;
				case '*': result *= array[i]; break;
				case '/': result /= array[i]; break;
			}
		}
		// Si el resultado coincide con el número objetivo, imprime la combinación
		if (result == targetNumber) {
			printCombination(array, size, targetNumber, operations);
		}
		return;
	}

	// Prueba todas las operaciones posibles en la posición actual
	operations.push_back('+');
	findCombinations(number, targetNumber, array, size, index + 1, operations);
	operations.back() = '-';
	findCombinations(number, targetNumber, array, size, index + 1, operations);
	operations.back() = '*';
	findCombinations(number, targetNumber, array, size, index + 1, operations);
	operations.back() = '/';
	findCombinations(number, targetNumber, array, size, index + 1, operations);
}


int main() {
	std::cout << "\n\e[1;35m[========= E08-EXPRESIONES-ARITMETICAS =========]\e[0m\n\n";

	int initialCount = 0, targetNumber = 0;

	getcin("Ingrese el número inicial: ", initialCount);
	getcin("Ingrese el número objetivo: ", targetNumber);

	// Verifica que el número inicial sea válido
	if (initialCount < 1) {
		printf("\n\e[1;31m[ERROR]\e[0m El número inicial debe ser mayor a 0.\n");
		return 1;
	}

	// Crea un arreglo con los números del 1 al número inicial
	int numbers[initialCount];
	for (int i = 0; i < initialCount; i++) {
		numbers[i] = i + 1;
	}

	// Encuentra combinaciones con el primer número positivo
	printf("\n");
	findCombinations(numbers[0], targetNumber, numbers, initialCount);
	numbers[0] *= -1; // Encuentra combinaciones con el primer número negativo
	findCombinations(numbers[0], targetNumber, numbers, initialCount);

	// Imprime el total de combinaciones encontradas
	printf("\n\e[1;32m[RESULTADO]\e[0m Total de combinaciones: %d\n\n", totalCombinations);

	return 0;
}
