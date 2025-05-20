#include <iostream> // Biblioteca para entrada y salida estándar
#include <string>   // Biblioteca para manipulación de strings
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares
#include "../S99-libraries/dxmatrix.hpp" // Biblioteca personalizada para operaciones con arreglos

// Función para generar un laberinto aleatorio
void generateMaze(int** mazeGrid, int mazeSize) {
	// Itera por cada celda del laberinto
	for (int row = 0; row < mazeSize; row++) {
		for (int col = 0; col < mazeSize; col++) {
			// Genera un obstáculo (1) con una probabilidad del 25%, de lo contrario, deja el espacio vacío (0)
			if ((rand() % 100) <= 25) mazeGrid[row][col] = 1;
			else mazeGrid[row][col] = 0;
		}
	}

	// Asegura que la celda inicial y la celda final estén libres de obstáculos
	mazeGrid[0][0] = 0;
	mazeGrid[mazeSize-1][mazeSize-1] = 0;
}

// Función para verificar si una celda es válida para moverse
bool isCellValid(int** mazeGrid, int mazeSize, int row, int col) {
	// Verifica si la celda está dentro de los límites del laberinto
	if (row < 0 || col < 0 || row >= mazeSize || col >= mazeSize) return false;

	// Verifica si la celda no es un obstáculo (1)
	if (mazeGrid[row][col]) return false;

	// La celda es válida si pasa las verificaciones anteriores
	return true;
}

// Función recursiva para encontrar un camino en el laberinto
bool findMazePath(int** mazeGrid, int mazeSize, int row = 0, int col = 0) {
	// Caso base: si se llega a la celda final, se encontró un camino
	if (row == mazeSize-1 && col == mazeSize-1) {
		mazeGrid[row][col] = 2; // Marca la celda como parte del camino
		printf("\n\e[1;32m[RESULTADO]\e[0m ¡Se encontró un camino en el laberinto!\n\n");
		printMatrix(mazeGrid, mazeSize); // Imprime el laberinto con el camino encontrado
		printf("\n");
		return true;
	}

	// Verifica si la celda actual es válida para moverse
	if (isCellValid(mazeGrid, mazeSize, row, col)) {
		printf("\e[1;33m[INFO]\e[0m Explorando celda (%d, %d)\n", row, col);
		mazeGrid[row][col] = 2; // Marca la celda como parte del camino

		// Intenta moverse en las cuatro direcciones posibles
		if (findMazePath(mazeGrid, mazeSize, row+1, col)) return true; // Abajo
		if (findMazePath(mazeGrid, mazeSize, row, col+1)) return true; // Derecha
		if (findMazePath(mazeGrid, mazeSize, row-1, col)) return true; // Arriba
		if (findMazePath(mazeGrid, mazeSize, row, col-1)) return true; // Izquierda

		// Si ninguna dirección es válida, retrocede y desmarca la celda
		mazeGrid[row][col] = 0;
	}

	// Mensaje de retroceso al no encontrar un camino desde la celda actual
	printf("\e[1;31m[INFO]\e[0m Retrocediendo desde la celda (%d, %d)\n", row, col);
	return false;
}

int main() {
	std::cout << "\n\e[1;35m[========= E12-CAMINO-DEL-LABERINTO =========]\e[0m\n\n";

	int mazeSize; // Tamaño del laberinto
	srand(time(NULL)); // Inicializa la semilla para la generación aleatoria

	// Solicita al usuario el tamaño del laberinto
	getcin("Ingresa el tamaño del laberinto: ", mazeSize);

	// Crea una matriz dinámica para representar el laberinto
	int** maze = new int*[mazeSize];
	for (int row = 0; row < mazeSize; row++) {
		maze[row] = new int[mazeSize];
	}

	// Genera el laberinto aleatorio
	generateMaze(maze, mazeSize);

	// Imprime el laberinto inicial
	printf("\nLaberinto inicial generado:\n\n");
	printMatrix(maze, mazeSize);
	printf("\n");

	// Intenta encontrar un camino en el laberinto
	if (!findMazePath(maze, mazeSize)) {
		// Mensaje si no se encuentra un camino
		printf("\n\e[1;31m[ERROR]\e[0m No existe un camino en el laberinto.\n\n");
	}

	// Libera la memoria asignada para el laberinto
	for (int row = 0; row < mazeSize; row++) {
		delete[] maze[row];
	}
	delete[] maze;

	return 0; // Fin del programa
}
