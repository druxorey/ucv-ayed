#include <iostream> // Biblioteca para entrada y salida estándar

const std::string HEX_DIGITS = "0123456789ABCDEF";

// Función recursiva para calcular la representación hexadecimal de un número
// Toma como entrada un número entero y devuelve su representación en hexadecimal como una cadena
std::string calculateHexadecimal(int number) {
	if (number == 0) return ""; // Caso base: si el número es 0, retorna una cadena vacía

	// Paso recursivo:
	// 1. Divide el número entre 16 para reducirlo y procesar el siguiente dígito más significativo.
	// 2. Obtiene el dígito correspondiente al residuo de la división entre 16.
	// 3. Concatena el resultado de la llamada recursiva con el dígito actual.
	// Por ejemplo, si el número es 255:
	// - Primera llamada: 255 % 16 = 15 ('F'), 255 / 16 = 15
	// - Segunda llamada: 15 % 16 = 15 ('F'), 15 / 16 = 0
	// Resultado: "FF"
	return calculateHexadecimal(number / 16) + HEX_DIGITS[(number % 16)];
}

// Función recursiva para calcular la representación binaria de un número
// Toma como entrada un número entero y devuelve su representación en binario como un entero
int calculateBinary(int number) {
	if (number == 0) return 0; // Caso base: si el número es 0, retorna 0

	// Paso recursivo:
	// 1. Divide el número entre 2 para reducirlo y procesar el siguiente dígito más significativo.
	// 2. Obtiene el residuo de la división entre 2, que representa el bit menos significativo.
	// 3. Multiplica el resultado de la llamada recursiva por 10 y suma el residuo actual.
	// Por ejemplo, si el número es 5:
	// - Primera llamada: 5 % 2 = 1, 5 / 2 = 2
	// - Segunda llamada: 2 % 2 = 0, 2 / 2 = 1
	// - Tercera llamada: 1 % 2 = 1, 1 / 2 = 0
	// Resultado: 101
	return (number % 2) + 10 * calculateBinary(number / 2);
}


int main() {
	std::cout << "\n\e[0;35m[========= E07-CONVERSION-A-BINARIO =========]\e[0m\n\n";

	// Declaración de variables para almacenar el número inicial y las conversiones
	int initialNumber = 0;

	// Solicita al usuario ingresar un número decimal
	printf("Ingrese el valor decimal inicial: ");
	std::cin >> initialNumber;

	// Calcula y muestra la conversión a binario
	printf("\n\e[1;32m[RESULTADO]\e[0m El número en binario es: %d", calculateBinary(initialNumber));
	// Calcula y muestra la conversión a hexadecimal
	printf("\n\e[1;32m[RESULTADO]\e[0m El número en hexadecimal es: %s\n\n", calculateHexadecimal(initialNumber).c_str());

	// Finaliza el programa
	return 0;
}
