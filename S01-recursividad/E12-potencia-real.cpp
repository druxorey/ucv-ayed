#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Define un alias para simplificar el uso de un tipo de dato de punto flotante de 80 bits
typedef long double f80;

// Función recursiva para calcular la potencia de un número
f80 getPower(f80 base, int exponent) {
	// Caso base: cualquier número elevado a la potencia 0 es 1
	if (exponent == 0) return 1;

	// Caso recursivo: si el exponente es positivo e impar
	if (exponent > 0 && exponent % 2 == 1) {
		// Multiplica la base por sí misma y llama a la función recursivamente
		// Esto se debe a que la potencia de un número impar se puede descomponer en base * base^(exponente-1)
		return base * getPower(base, exponent - 1);
	}

	// Caso recursivo: si el exponente es positivo y par
	// Multiplica la base por sí misma y llama a la función recursivamente
	// Esto se debe a que la potencia de un número par se puede descomponer en base^2 * base^(exponente/2)
	return getPower(base * base, exponent / 2);
}

int main() {
	std::cout << "\n\e[0;35m[========= E12-POTENCIA-REAL =========]\e[0m\n\n";

	// Declaración de variables para la base y el exponente
	f80 base = 0.0; // Base de la potencia
	unsigned int exponent = 0; // Exponente de la potencia

	getcin("Ingrese la base: ", base);
	getcin("Ingrese el exponente: ", exponent);

	// Calcula la potencia y muestra el resultado en pantalla
	printf("\e[1;32m[RESULTADO]\e[0m %.2Lf elevado a la potencia de %d es: %.8Lf.\n\n", base, exponent, getPower(base, exponent));
	// Para el tipo de dato long double, se utiliza %Lf en lugar de %f
	// Se utiliza %.2Lf para mostrar la base con 2 decimales y %.8Lf para mostrar el resultado con 8 decimales

	// Finaliza el programa
	return 0;
}
