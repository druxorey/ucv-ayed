#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Función recursiva para verificar si una palabra es un palíndromo
// Parámetros:
// - input: arreglo de caracteres que contiene la palabra a verificar
// - size: tamaño del arreglo
// - index: índice actual para comparar caracteres (por defecto inicia en 0)
bool getPalindrome(char input[], int size, int index = 0) {
	if (size <= 0) return true; // Caso base: si el tamaño es 0 o negativo, es un palíndromo

	// Compara el carácter inicial con el final
	if (input[index] == input[size - 1]) {
		return getPalindrome(input, size - 1, index + 1); // Llama recursivamente reduciendo el tamaño
	}

	return false; // Si los caracteres no coinciden, no es un palíndromo
}

int main() {
	std::cout << "\n\e[0;35m[========= E08-PALABRA-CAPICUA =========]\e[0m\n\n";

	// Arreglo para almacenar la palabra ingresada por el usuario
	char input[48];
	// Se establece un tamaño máximo de 48 caracteres para la palabra

	// Solicita al usuario que ingrese una palabra
	getcin("Ingrese una palabra: ", input);
	// Calcula el tamaño del arreglo
	int size = sizeof(input) / sizeof(input[0]);

	// Verifica si la palabra ingresada es un palíndromo
	if (getPalindrome(input, size)) {
		printf("\e[1;32m[RESULTADO]\e[0m La palabra ingresada es un palíndromo.\n\n");
	} else {
		printf("\e[1;31m[RESULTADO]\e[0m La palabra ingresada no es un palíndromo.\n\n");
	}

	return 0; // Indica que el programa terminó correctamente
}
