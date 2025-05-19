#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares
#include "../S99-libraries/dxarray.hpp" // Biblioteca personalizada para operaciones con arreglos

// Función para obtener el valor máximo de un arreglo
int getMaxValue(int numbers[], int size) {
	if (size <= 0) return 0; // Caso base: si el tamaño es 0 o negativo, retorna 0
	if (size == 1) return numbers[0]; // Caso base: si hay un solo elemento, retorna ese elemento

	// Llamada recursiva para obtener el máximo del resto del arreglo
	int residualMax = getMaxValue(numbers, size - 1);

	// Compara el último elemento con el máximo residual y retorna el mayor
	return numbers[size - 1] > residualMax ? numbers[size - 1] : residualMax;
}

// Función para calcular el valor promedio del arreglo
double getMidValue(int numbers[], int size) {
	if (size == 1) return numbers[0]; // Caso base: si hay un solo elemento, retorna ese elemento

    // Calcula el promedio acumulado recursivamente
    // Paso 1: Obtiene el último elemento del arreglo actual (numbers[size - 1]).
    // Paso 2: Llama recursivamente a la función para calcular el promedio acumulado de los primeros (size - 1) elementos.
    // Paso 3: Multiplica el promedio acumulado de los primeros (size - 1) elementos por la cantidad de elementos (size - 1),
    //         lo que convierte el promedio acumulado en la suma total de esos elementos.
    // Paso 4: Suma el último elemento del arreglo a la suma total de los primeros (size - 1) elementos.
    // Paso 5: Divide la suma total de los primeros (size) elementos entre el tamaño total del arreglo (size),
    //         obteniendo así el promedio de los elementos.
	return (numbers[size - 1] + (size - 1) * getMidValue(numbers, size - 1)) / size;
}

// Función para sumar todos los valores del arreglo
int sumValues(int numbers[], int size) {
	if (size <= 0) return 0; // Caso base: si el tamaño es 0 o negativo, retorna 0

	// Suma el último elemento con la suma del resto del arreglo
	return numbers[size - 1] + sumValues(numbers, size - 1);
}

// Función para verificar si el arreglo está ordenado de forma ascendente
bool isSorted(int numbers[], int size) {
	if (size <= 1) return true; // Caso base: un arreglo de tamaño 1 o vacío siempre está ordenado
	
	// Si un elemento es menor que el anterior, no está ordenado
	if (numbers[size - 1] < numbers[size - 2]) return false;

	// Llamada recursiva para verificar el resto del arreglo
	return isSorted(numbers, size - 1);
}

int main() {
	std::cout << "\n\e[1;35m[========= E13-ARREGLO-OPERACIONES =========]\e[0m\n\n";

	int size;

	getcin("Ingrese el tamaño del arreglo: ", size);

	int numbers[size]; // Declara el arreglo con el tamaño especificado por el usuario

	// Llena el arreglo con valores proporcionados por el usuario
	fillArray(numbers, size);
	// Imprime el contenido del arreglo
	printArray(numbers, size);

	// Calcula y muestra el valor máximo del arreglo
	printf("\e[1;33m[RESULTADO]\e[0m El valor máximo es: %d\n", getMaxValue(numbers, size));

	// Calcula y muestra la suma de los valores del arreglo
	printf("\e[1;33m[RESULTADO]\e[0m La suma de los valores es: %d\n", sumValues(numbers, size));

	// Calcula y muestra el valor promedio del arreglo
	printf("\e[1;33m[RESULTADO]\e[0m El valor promedio es: %f\n", getMidValue(numbers, size));

	// Verifica si el arreglo está ordenado y muestra el resultado
	if (isSorted(numbers, size))
		printf("\e[1;32m[RESULTADO]\e[0m El arreglo está ordenado\n");
	else
		printf("\e[1;31m[RESULTADO]\e[0m El arreglo no está ordenado\n");

	return 0; // Finaliza el programa
}
