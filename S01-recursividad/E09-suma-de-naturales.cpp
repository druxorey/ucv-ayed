#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// El typedef se utiliza para definir un nuevo nombre para un tipo de dato existente.
// En este caso, se define 'u64' como un alias para 'unsigned long long int'.
typedef unsigned long long int u64;

// Función recursiva para calcular la suma de los primeros números naturales
// Parámetro: size - número de naturales a sumar
// Retorna: la suma de los números naturales desde 1 hasta size
u64 sumNaturals(int size) {
	if (size <= 0) return 0; // Caso base: si el número es menor o igual a 0, retorna 0

	// Llamada recursiva sumando el número actual (size) con la suma de los números anteriores
	return size + sumNaturals(size - 1);
}

int main() {
	std::cout << "\n\e[1;35m[========= E09-SUMA-DE-NATURALES =========]\e[0m\n\n";

	int size = 0;

	// Solicita al usuario ingresar el número de naturales a sumar
	getcin("Ingrese la cantidad de números naturales a sumar: ", size);

	// Calcula la suma de los números naturales y muestra el resultado
	printf("\e[1;32m[RESULTADO]\e[0m La suma de todos los números naturales es: %llu.\n\n", sumNaturals(size));

	return 0; // Indica que el programa terminó correctamente
}
