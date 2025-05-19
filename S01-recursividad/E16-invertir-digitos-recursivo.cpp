#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares

// Función recursiva para invertir un número
// number: número original que se desea invertir
// inverted: número invertido acumulado (inicia en 0 por defecto)
int invertNumber(int number, int inverted = 0) {
	// Caso base: si el número es 0, se retorna el número invertido acumulado
	if (number == 0) return inverted;

	// Llamada recursiva: se divide el número entre 10 (quitando el último dígito)
	// y se acumula el dígito extraído en la posición correcta del número invertido
	return invertNumber(number / 10, (inverted * 10) + (number % 10));
}

int main() {
	std::cout << "\n\e[0;35m[========= E16-INVERTIR-DIGITOS-RECURSIVO =========]\e[0m\n\n";

	int number; // Variable para almacenar el número ingresado por el usuario

	// Solicitar al usuario que ingrese un número
	getcin("Ingrese un número: ", number);

	// Mostrar el resultado del número invertido con formato decorado
	printf("\e[1;32m[RESULTADO]\e[0m El número invertido es: %d.\n\n", invertNumber(number));

	return 0; // Indicar que el programa finalizó correctamente
}
