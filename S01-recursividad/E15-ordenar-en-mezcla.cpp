#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares
#include "../S99-libraries/dxarray.hpp" // Biblioteca personalizada para operaciones con arreglos

// Función para realizar el algoritmo de ordenamiento por mezcla (merge sort)
void mergeSort(int array[], int size) {
	// Caso base: si el tamaño del arreglo es menor a 2, no se necesita ordenar
	if (size < 2) return;

	// Dividir el arreglo en dos mitades
	int middle = size / 2; // Índice del medio
	int left[middle], right[size - middle]; // Arreglos temporales para las mitades

	// Copiar los elementos de la primera mitad al arreglo 'left'
	for (int i = 0; i < middle; i++) left[i] = array[i];

	// Copiar los elementos de la segunda mitad al arreglo 'right'
	for (int i = middle; i < size; i++) right[i - middle] = array[i];

	// Llamadas recursivas para ordenar cada mitad
	mergeSort(left, middle); // Ordenar la mitad izquierda
	mergeSort(right, size - middle); // Ordenar la mitad derecha

	// Mezclar las dos mitades ordenadas en el arreglo original
	int i = 0, j = 0, k = 0; // Índices para recorrer 'left', 'right' y 'array'

	// Comparar y combinar elementos de 'left' y 'right' en 'array'
	while (i < middle && j < size - middle) {
		if (left[i] < right[j]) array[k++] = left[i++]; // Si el elemento de 'left' es menor, se copia
		else array[k++] = right[j++]; // Si no, se copia el elemento de 'right'
	}

	// Copiar los elementos restantes de 'left', si los hay
	while (i < middle) array[k++] = left[i++];

	// Copiar los elementos restantes de 'right', si los hay
	while (j < size - middle) array[k++] = right[j++];
}


int main() {
	std::cout << "\n\e[1;35m[========= E15-ORDENAR-EN-MEZCLA =========]\e[0m\n\n";

	int size, position; // Variables para el tamaño del arreglo y posición

	getcin("\e[1;33m[ENTRADA]\e[0m Ingrese el tamaño del arreglo: ", size);

	int numbers[size]; // Declarar el arreglo con el tamaño ingresado

	// Generar un arreglo aleatorio
	randArray(numbers, size);
	printf("\n\e[1;33m[GENERADO]\e[0m Arreglo generado:\n");
	printArray(numbers, size); // Imprimir el arreglo generado

	// Ordenar el arreglo usando el algoritmo de ordenamiento por mezcla
	mergeSort(numbers, size);
	printf("\n\e[1;32m[RESULTADO]\e[0m Arreglo ordenado:\n");
	printArray(numbers, size); // Imprimir el arreglo ordenado

	return 0; // Indicar que el programa terminó correctamente
}
