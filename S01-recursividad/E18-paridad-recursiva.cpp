#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Declaración de las funciones isOdd e isEven
// Esto es necesario porque el compilador necesita conocer la existencia de estas funciones antes de que sean utilizadas.
// La declaración permite que el compilador valide las llamadas a estas funciones antes de que se definan completamente.
bool isOdd(int n); // Función que determina si un número es impar
bool isEven(int n); // Función que determina si un número es par

// Definición de la función isOdd
// Esta función utiliza recursión para determinar si un número es impar.
// Si el número es 0, retorna false porque 0 no es impar.
// En caso contrario, llama a la función isEven con el número reducido en 1.
bool isOdd(int n) {
	if (n == 0) return false; // Caso base: 0 no es impar
	return isEven(n - 1); // Llamada recursiva: verifica si el número anterior es par
}

// Definición de la función isEven
// Esta función utiliza recursión para determinar si un número es par.
// Si el número es 0, retorna true porque 0 es par.
// En caso contrario, llama a la función isOdd con el número reducido en 1.
bool isEven(int n) {
	if (n == 0) return true; // Caso base: 0 es par
	return isOdd(n - 1); // Llamada recursiva: verifica si el número anterior es impar
}


int main() {
	std::cout << "\n\e[0;35m[========= E18-PARIDAD-RECURSIVA =========]\e[0m\n\n";

	int a = 0; // Variable para almacenar el número ingresado por el usuario

	// Solicita al usuario que ingrese un número
	getcin("Ingrese el primer número: ", a);

	// Determina si el número ingresado es par o impar y muestra el resultado
	printf("\e[1;32m[RESULTADO]\e[0m El número %d es %s.\n\n", a, isEven(a) ? "par" : "impar");

	return 0; // Fin del programa
}
