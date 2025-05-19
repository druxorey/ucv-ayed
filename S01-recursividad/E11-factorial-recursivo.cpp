#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Define un alias para simplificar el uso de un tipo de dato entero sin signo de 64 bits
typedef unsigned long long int u64;

// Función recursiva para calcular el factorial de un número
// Parámetro: n (número del cual se desea calcular el factorial)
// Retorna: el factorial de n
u64 getFactorial(u64 n) {
	if (n == 0) return 1; // Caso base: el factorial de 0 es 1
	
	// Llamada recursiva: n * factorial de (n-1)
	// Esto se debe a que el factorial de n (n!) es igual a n * (n-1)!
	return n * getFactorial(n - 1);
}

int main(int argc, char *argv[]) {
	std::cout << "\n\e[0;35m[========= E11-FACTORIAL-RECURSIVO =========]\e[0m\n\n";

	short int number;
	getcin("Ingrese un número: ", number);

	// Verifica si el número es negativo
	if (number < 0) {
		printf("\e[1;31m[ERROR]\e[0m El factorial de %d no está definido.\n\n", number);
		return 1; // Termina el programa con un código de error
	}

	// Verifica si el número es demasiado grande para calcular su factorial
	if (number >= 21) {
		printf("\e[1;33m[ADVERTENCIA]\e[0m El factorial de %d es demasiado grande para calcularse.\n\n", number);
		return 0; // Termina el programa sin errores
	}

	// Calcula el factorial del número ingresado
	u64 factorial = getFactorial(number);

	// Imprime el resultado del factorial con un formato decorativo
	printf("\e[1;32m[RESULTADO]\e[0m El factorial de %d es: %llu.\n\n", number, factorial);

	return 0; // Termina el programa exitosamente
}
