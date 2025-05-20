#include <iostream> // Biblioteca para entrada y salida estándar
#include "../S99-libraries/dxstd.hpp" // Biblioteca personalizada para funciones auxiliares
#include "../S99-libraries/dxmatrix.hpp" // Biblioteca personalizada para operaciones con arreglos

// Función para verificar si una posición en el tablero es segura para colocar una reina
bool isPositionSafe(bool** board, int boardSize, int row, int col) {
	// Verificar si hay otra reina en la misma columna
	for (int i = 0; i < row; i++)
		if (board[i][col])
			return false;

	// Verificar la diagonal superior izquierda
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// Verificar la diagonal superior derecha
	for (int i = row, j = col; i >= 0 && j < boardSize; i--, j++)
		if (board[i][j])
			return false;

	// Si pasa todas las verificaciones, la posición es segura
	return true;
}

// Función recursiva para resolver el problema de las N reinas
bool solveNQueens(bool** board, int boardSize, int row = 0, int placedQueens = 0) {
	// Caso base: si se han colocado todas las reinas, se encontró una solución
	if (placedQueens == boardSize) return true;

	// Intentar colocar una reina en cada columna de la fila actual
	for (int col = 0; col < boardSize; col++) {
		// Verificar si la posición es segura
		if (isPositionSafe(board, boardSize, row, col)) {
			// Colocar la reina en la posición actual
			board[row][col] = true;
			placedQueens++;

			// Llamada recursiva para intentar colocar la siguiente reina
			if (solveNQueens(board, boardSize, row + 1, placedQueens)) return true;

			// Si no se encuentra solución, deshacer el movimiento
			board[row][col] = false;
			placedQueens--;
		}
	}

	// Si no se puede colocar una reina en esta fila, retornar falso
	return false;
}

int main() {
	std::cout << "\n\e[1;35m[========= E16-OCHO-REINAS =========]\e[0m\n\n";

	// Solicitar al usuario el tamaño del tablero
	int boardSize;
	getcin("Ingrese el tamaño del tablero: ", boardSize);

	// Validar que el tamaño del tablero sea mayor o igual a 4
	if (boardSize < 4) {
		printf("\n\e[1;31m[ERROR]\e[0m El tamaño del tablero debe ser mayor o igual a 4\n\n");
		return 1;
	}

	// Crear el tablero dinámicamente
	bool** board = new bool*[boardSize];
	for (int i = 0; i < boardSize; i++) {
		board[i] = new bool[boardSize];
		// Inicializar todas las posiciones del tablero como falsas (sin reinas)
		for (int j = 0; j < boardSize; j++) {
			board[i][j] = false;
		}
	}

	// Resolver el problema de las N reinas
	if (solveNQueens(board, boardSize)) {
		// Mostrar el tablero con la solución encontrada
		printf("\n\e[1;32m[RESULTADO]\e[0m Solución encontrada:\n\n");
		printMatrix(board, boardSize, "", " ");
		printf("\n");
	} else {
		// Mensaje de error si no se encuentra solución
		printf("\n\e[1;31m[ERROR]\e[0m No se encontró una solución para el tamaño del tablero ingresado\n");
	}

	// Liberar la memoria asignada dinámicamente para el tablero
	for (int i = 0; i < boardSize; i++) {
		delete[] board[i];
	}
	delete[] board;

	// Finalizar el programa
	return 0;
}
