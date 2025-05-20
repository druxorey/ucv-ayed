#include <iostream> // Biblioteca para entrada y salida estándar
#include <string> // Biblioteca para manipulación de cadenas de texto
#include <vector> // Biblioteca para uso de vectores

// Definimos un alias para un vector de strings que representará los movimientos realizados
typedef std::vector<std::string> squares;

// Tablero de ajedrez representado como una matriz de 8x8. Inicialmente, todas las posiciones están marcadas como no visitadas (false).
bool chessBoard[8][8] = {false};

// Función para imprimir el tablero de ajedrez y los movimientos realizados
void printChessBoard(squares movesMade) {
	// Imprime el estado actual del tablero
	printf("\n\e[1;34m ESTADO FINAL DEL TABLERO\e[0m\n");
	for (int row = 0; row < 8; row++) {
		printf("\n     ");
		for (int cols = 0; cols < 8; cols++) {
			printf("%d ", chessBoard[row][cols]); // Imprime 0 o 1 dependiendo de si la casilla fue visitada
		}
	}

	// Imprime los movimientos realizados por el caballo
	printf("\n\n\e[1;32m[MOVIMIENTOS REALIZADOS]\e[0m [ ");
	for (int i = 0; i < movesMade.size(); i++) {
		std::cout << movesMade[i] << " "; // Imprime cada movimiento en formato de coordenadas
	}
	printf("]\n\n");
}

// Función para verificar si un movimiento es válido
bool isMoveValid(int xPosition, int yPosition) {
	// Verifica que las coordenadas estén dentro del tablero y que la casilla no haya sido visitada
	if (xPosition >= 0 && xPosition < 8 && yPosition >= 0 && yPosition < 8 && !chessBoard[yPosition][xPosition]) {
		return true;
	}
	return false;
}

// Convierte una posición en coordenadas (x, y) a una representación en notación de ajedrez (e.g., "A1")
std::string positionToString(int xPosition, int yPosition) {
	char column = 'A' + xPosition; // Calcula la columna en base a la posición x
	char row = '8' - yPosition;	// Calcula la fila en base a la posición y
	return std::string(1, column) + std::string(1, row); // Retorna la posición como string
}

// Función recursiva para encontrar el recorrido del caballo
bool findKnightTour(int xPosition, int yPosition, squares &movesMade) {
	// Caso base: si se han realizado 64 movimientos, el recorrido está completo
	if (movesMade.size() == 64) {
		printf("\n\e[1;32m[RESULTADO]\e[0m El caballo ha completado el recorrido.\n");
		printChessBoard(movesMade); // Imprime el tablero y los movimientos realizados
		return true;
	}

	// Verifica si el movimiento actual es válido
	if (isMoveValid(xPosition, yPosition)) {
		chessBoard[yPosition][xPosition] = true; // Marca la casilla como visitada
		movesMade.push_back(positionToString(xPosition, yPosition)); // Agrega el movimiento a la lista

		// Intenta realizar los movimientos posibles del caballo
		// Movimiento 1: Dos pasos hacia la derecha y uno hacia arriba
		if (findKnightTour(xPosition + 2, yPosition + 1, movesMade)) return true;
		// Movimiento 2: Dos pasos hacia la derecha y uno hacia abajo
		if (findKnightTour(xPosition + 2, yPosition - 1, movesMade)) return true;
		// Movimiento 3: Dos pasos hacia la izquierda y uno hacia arriba
		if (findKnightTour(xPosition - 2, yPosition + 1, movesMade)) return true;
		// Movimiento 4: Dos pasos hacia la izquierda y uno hacia abajo
		if (findKnightTour(xPosition - 2, yPosition - 1, movesMade)) return true;
		// Movimiento 5: Un paso hacia la derecha y dos hacia arriba
		if (findKnightTour(xPosition + 1, yPosition + 2, movesMade)) return true;
		// Movimiento 6: Un paso hacia la derecha y dos hacia abajo
		if (findKnightTour(xPosition + 1, yPosition - 2, movesMade)) return true;
		// Movimiento 7: Un paso hacia la izquierda y dos hacia arriba
		if (findKnightTour(xPosition - 1, yPosition + 2, movesMade)) return true;
		// Movimiento 8: Un paso hacia la izquierda y dos hacia abajo
		if (findKnightTour(xPosition - 1, yPosition - 2, movesMade)) return true;

		// Si ninguno de los movimientos funciona, retrocede (backtracking)
		chessBoard[yPosition][xPosition] = false; // Desmarca la casilla
		movesMade.pop_back(); // Elimina el último movimiento de la lista
	}

	return false; // Retorna false si no se puede completar el recorrido desde esta posición
}


int main() {
	std::cout << "\n\e[1;35m[========= E10-RECORRIDO-DEL-CABALLO =========]\e[0m\n\n";

	squares movesMade; // Lista para almacenar los movimientos realizados

	if (!findKnightTour(7, 0, movesMade)) { // Inicia el recorrido desde la posición inicial (H1)
		// Mensaje de error si no se puede completar el recorrido
		printf("\n\e[1;31m[ERROR]\e[0m No se pudo completar el recorrido del caballo.\n");
	}

	return 0; // Finaliza el programa
}
