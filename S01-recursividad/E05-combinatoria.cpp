#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// El typedef se utiliza para definir un nuevo nombre para un tipo de dato existente.
// En este caso, se define 'u64' como un alias para 'unsigned long long int'.
typedef unsigned long long int u64;

// Solución iterativa mejorada:
// Esta función calcula la combinatoria (n sobre k) de manera iterativa.
// Utiliza la propiedad de simetría dla combinatoria para reducir el número de multiplicaciones.
// La fórmula utilizada es: C(n, k) = n! / (k! * (n-k)!)

/*
u64 getCombinatorics(int n, int k) {
	if (k > n) return -1; // Si k es mayor que n, no es posible calcular la combinatoria.
	if (k == 0 || k == n) return 1; // Caso base: C(n, 0) = C(n, n) = 1.

	u64 result = 1;
	if (k > n - k) k = n - k; // Utiliza la simetría: C(n, k) = C(n, n-k).

	for (int i = 0; i < k; ++i) {
		result *= (n - i); // Multiplica por (n - i).
		result /= (i + 1); // Divide por (i + 1).
	}

	return result; // Devuelve el resultado final.
}
*/

// Solución recursiva:
u64 getCombinatorics(int n, int k) {
	// Esta función calcula la combinatoria C(n, k) utilizando una relación de recurrencia.
	// La combinatoria representa el número de formas de elegir k elementos de un conjunto de n elementos.
	// La relación de recurrencia utilizada es:
	// C(n, k) = C(n-1, k-1) + C(n-1, k)
	// Esto significa que para calcular C(n, k), sumamos:
	// - El número de formas de elegir (k-1) elementos de (n-1) elementos.
	// - El número de formas de elegir k elementos de (n-1) elementos.

	// Caso base: Si k es 0 o k es igual a n, el resultado es 1.
	// Esto se debe a que:
	// - C(n, 0) = 1 (solo hay una forma de no elegir ningún elemento).
	// - C(n, n) = 1 (solo hay una forma de elegir todos los elementos).
	if (k == 0 || k == n) return 1;

	// Llamada recursiva: Calcula la combinatoria sumando los dos casos anteriores.
	return getCombinatorics(n - 1, k - 1) + getCombinatorics(n - 1, k);
}


int main() {
	std::cout << "\n\e[0;35m[========= E05-COMBINATORIA =========]\e[0m\n\n";

	int n, k;

	// Solicita al usuario los valores de n y k.
	getcin("Introduce el valor de n: ", n);
	getcin("Introduce el valor de k: ", k);

	// Calcula la combinatoria.
	u64 combinatorics = getCombinatorics(n, k);

	// Muestra el resultado formateado.
	printf("\e[1;32m[RESULTADO]\e[0m la combinatoria de %d y %d es: %llu.\n\n", n, k, combinatorics);

	return 0;
}
