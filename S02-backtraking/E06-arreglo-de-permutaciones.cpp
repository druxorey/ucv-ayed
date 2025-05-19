#include <iostream> // Biblioteca para entrada y salida estándar
#include <string>   // Biblioteca para manipulación de strings
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares
#include "../S99-libraries/dxarray.hpp" // Biblioteca personalizada para operaciones con arreglos

// Función para intercambiar dos caracteres
void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

// Función recursiva para generar todas las permutaciones posibles de un arreglo
// Parámetros:
// - array[]: El arreglo de caracteres sobre el que se generarán las permutaciones.
// - size: El tamaño del arreglo.
// - validPermutationsCount: Referencia a un entero que lleva la cuenta del número total de permutaciones válidas generadas.
// - currentIndex: Índice actual desde donde se generarán las permutaciones (por defecto, comienza en 0).
void generatePermutations(char array[], int size, int &validPermutationsCount, int currentIndex = 0) {
	// Caso base: si el índice actual es igual al tamaño del arreglo
	// Significa que se ha generado una permutación completa del arreglo.
	if (currentIndex == size) {
		validPermutationsCount++; // Incrementar el contador de permutaciones válidas
		printArray(array, size, " ∘ Permutación " + std::to_string(validPermutationsCount) + ": \e[1;34m[\e[0m");
		// Terminar la ejecución de esta rama recursiva.
		return;
	}

	// Generar permutaciones intercambiando elementos.
	// Este bucle recorre los elementos desde el índice actual hasta el final del arreglo.
	for (int i = currentIndex; i < size; i++) {
		// Intercambiar el elemento en la posición 'currentIndex' con el elemento en la posición 'i'.
		swap(array[currentIndex], array[i]);

		// Llamada recursiva para generar permutaciones del resto del arreglo (a partir de index + 1).
		generatePermutations(array, size, validPermutationsCount, currentIndex + 1);

		// Revertir el intercambio para restaurar el estado original del arreglo.
		swap(array[currentIndex], array[i]);
	}
}


int main() {
	std::cout << "\n\e[1;35m[========= E06-ARREGLO-DE-PERMUTACIONES =========]\e[0m\n\n";

	int arraySize, validPermutations = 0; // Declaración de variables

	// Solicitar al usuario el tamaño del arreglo
	getcin("Ingresa el tamaño del arreglo: ", arraySize);

	char letters[arraySize]; // Declarar el arreglo de caracteres

	// Llenar el arreglo con letras de la 'A' a la 'Z'
	fillArray(letters, arraySize);

	// Generar todas las permutaciones del arreglo
	printf("\n");
	generatePermutations(letters, arraySize, validPermutations);

	// Imprimir el total de permutaciones generadas
	printf("\n\e[1;32m[RESULTADO]\e[0m Total de permutaciones: %d.\n\n", validPermutations);

	return 0; // Indicar que el programa terminó correctamente
}
