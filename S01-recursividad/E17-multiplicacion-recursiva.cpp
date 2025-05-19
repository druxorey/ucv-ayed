#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Función recursiva para realizar la multiplicación de dos números
int multiply(int a, int b) {
	// Caso base: Si el segundo número es 0, el resultado es 0
	if (b == 0) return 0;

	// Caso recursivo: Suma 'a' y llama a la función con 'b - 1'
	return a + multiply(a, b - 1);
}

int main() {
	std::cout << "\n\e[0;35m[========= E17-MULTIPLICACION-RECURSIVA =========]\e[0m\n\n";

	// Declaración de variables para almacenar los números ingresados por el usuario
	int a = 0, b = 0;

	getcin("Ingrese el primer número: ", a);
	getcin("Ingrese el segundo número: ", b);

	// Mostrar el resultado de la multiplicación utilizando la función recursiva
	printf("\e[1;32m[RESULTADO]\e[0m El resultado de %d * %d es: %d.\n\n", a, b, multiply(a, b));

	// Finalizar el programa
	return 0;
}
