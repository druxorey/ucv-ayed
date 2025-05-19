#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares
#include "../S99-libraries/dxarray.hpp" // Biblioteca personalizada para operaciones con arreglos

// Función para realizar la búsqueda binaria en un arreglo
// Parámetros:
// - array: el arreglo donde se buscará el número, se pasará por referencia
// - number: el número que se desea buscar
// - top: índice superior del rango de búsqueda
// - bottom: índice inferior del rango de búsqueda (por defecto es 0)
int binarySearch(int array[], int number, int top, int bottom = 0) {
	// Calcular el índice medio del rango actual
	int middle = (top + bottom) / 2;

	// Si el número en la posición media es igual al número buscado, devolver el índice
	if (array[middle] == number) return middle;

	// Si el rango de búsqueda se ha agotado, devolver -1 (no encontrado)
	if (top <= bottom) return -1;

	// Si el número en la posición media es menor que el número buscado,
	// buscar en la mitad superior del rango
	if (array[middle] < number) return binarySearch(array, number, top, middle + 1);

	// Si el número en la posición media es mayor que el número buscado,
	// buscar en la mitad inferior del rango
	return binarySearch(array, number, middle - 1, bottom);
}


int main() {
	std::cout << "\n\e[1;35m[========= E14-BUSQUEDA-BINARIA =========]\e[0m\n\n";

	int size, number, position;

	getcin("Ingrese el tamaño del arreglo: ", size);
	getcin("Ingrese el número a buscar: ", number);

	int numbers[size];

	// Llenar el arreglo con valores
	fillArray(numbers, size);
	// Imprimir el contenido del arreglo
	printArray(numbers, size);

	// Realizar la búsqueda binaria
	position = binarySearch(numbers, number, size);

	// Verificar si el número fue encontrado o no
	if (position == -1)
		printf("\e[1;31m[RESULTADO]\e[0m El número no fue encontrado.\n\n");
	else
		printf("\e[1;32m[RESULTADO]\e[0m El número fue encontrado en la posición %d.\n\n", position);

	return 0;
}
