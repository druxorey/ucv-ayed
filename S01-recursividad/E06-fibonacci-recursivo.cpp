#include <iostream> // Biblioteca para entrada y salida estándar
#include <unordered_map> // Biblioteca para usar mapas hash
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Define un alias para simplificar el uso de un tipo de dato entero sin signo de 64 bits
typedef unsigned long long int ulli;

ulli getFibonnacci(ulli n, std::unordered_map<ulli, ulli>& memo) {
	// Caso base: si n es 0 o 1, devuelve n directamente
	// Esto se debe a que los primeros dos números de la serie de Fibonacci son 0 y 1.
	if (n <= 1) return n;

	// Verifica si el resultado ya está almacenado en el mapa de memoización.
	// El mapa "memo" actúa como una caché para evitar cálculos repetidos.
	// Si el valor de Fibonacci para "n" ya fue calculado, se devuelve directamente.
	if (memo.find(n) != memo.end()) return memo[n];

	// Si el resultado no está en el mapa, calcula el Fibonacci de forma recursiva.
	// Llama a la función para calcular los valores de Fibonacci de "n-1" y "n-2".
	// Luego, almacena el resultado en el mapa para futuras consultas.
	// Esto optimiza el cálculo al evitar recalcular valores ya conocidos.
	return memo[n] = getFibonnacci(n - 1, memo) + getFibonnacci(n - 2, memo);
}

int main() {
	std::cout << "\n\e[0;35m[========= E06-FIBONACCI-RECURSIVO =========]\e[0m\n\n";

	// Declara las variables necesarias: número de entrada y el mapa para memoización
	ulli number, fibonacci;
	std::unordered_map<ulli, ulli> memo;

	getcin("Ingrese un número: ", number);

	// Verifica si el número es demasiado grande para calcular su Fibonacci
	// Puesto que por el tipo de dato utilizado (unsigned long long int), el límite es 18446744073709551615
	if (number > 199) {
		printf("\e[1;31m[ERROR]\e[0m El Fibonacci de %lld es demasiado grande para calcularse.\n\n", number);
		return 1; // Termina el programa con un código de error
	}

	// Calcula el Fibonacci del número ingresado y lo imprime con formato
	printf("\e[1;32m[RESULTADO]\e[0m El Fibonacci de %lld es: %lld.\n\n", number, getFibonnacci(number, memo));

	return 0; // Indica que el programa terminó correctamente
}
