#include <iostream> // Biblioteca para entrada y salida estándar
#include <string> // Biblioteca para manipulación de cadenas de texto
#include <cmath> // Biblioteca para funciones matemáticas
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Constantes globales
const int DIGITS_SIZE = 9; // Tamaño del arreglo de dígitos
const int DIGITS[DIGITS_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Dígitos disponibles para combinaciones

// Función que verifica si una combinación es válida
bool isValidCombination(int actualCombination) {
	int length = std::to_string(actualCombination).length(); // Calcula la longitud del número actual
	// std::to_string convierte el número a string para contar los dígitos
	// .length() obtiene la longitud de la string

	// Verifica si cada prefijo del número es divisible por su longitud
	for (int i = length; i > 1; i--) {
		if (actualCombination % i != 0) return false; // Si no es divisible, no es válido
		actualCombination /= 10; // Elimina el último dígito
	}

	return true; // Si pasa todas las verificaciones, es válido
}

// Función recursiva para generar combinaciones de números
void generateCombinations(int maxNumber, int &totalCombinations, int currentNumber = 0, int digitCount[DIGITS_SIZE] = nullptr) {
	// Si el número actual excede el máximo permitido
	if (currentNumber > maxNumber) {
		// Verifica si la combinación es válida
		if (isValidCombination(currentNumber)) {
			totalCombinations++; // Incrementa el contador de combinaciones válidas
			printf(" ∘ Combinación \e[0;33m%d\e[0m: %d\n", totalCombinations, currentNumber);
		}
		return; // Termina la recursión
	}

	// Inicializa el contador de dígitos si es la primera llamada
	if (digitCount == nullptr) {
		int initialDigitCount[10] = {0}; // Inicializa el contador de dígitos en 0
		digitCount = initialDigitCount; // Asigna el contador inicial
	}

	// Itera sobre los dígitos disponibles
	for (int i = 0; i < 9; i++) {
		int digit = DIGITS[i]; // Obtiene el dígito actual

		// Verifica si el dígito no ha sido usado
		if (digitCount[digit] == 0) {
			digitCount[digit]++; // Marca el dígito como usado
			generateCombinations(maxNumber, totalCombinations, currentNumber * 10 + digit, digitCount); // Llama recursivamente
			digitCount[digit]--; // Desmarca el dígito al regresar
		}
	}
}

// Función principal
int main() {
	std::cout << "\n\e[1;35m[========= E07-NÚMEROS-M-CIFRAS =========]\e[0m\n\n";

	int maxDigits, totalCombinations = 0; // Variables principales

	// Solicita al usuario el número máximo de dígitos
	getcin("Ingrese el número máximo de dígitos: ", maxDigits);

	// Calcula el número máximo basado en los dígitos
	int maxNumber = pow(10, maxDigits - 1);

	// Genera las combinaciones y cuenta las válidas
	printf("\n");
	generateCombinations(maxNumber, totalCombinations);

	// Muestra el total de combinaciones válidas
	printf("\n\e[1;32m[RESULTADO]\e[0m El total de combinaciones válidas es: %d\n\n", totalCombinations);

	return 0; // Finaliza el programa
}
