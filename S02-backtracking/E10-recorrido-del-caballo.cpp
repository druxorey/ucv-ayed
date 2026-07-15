#include <iostream>

// Tablero de ajedrez representado como una matriz de 8x8. Inicialmente, todas las posiciones están marcadas como no visitadas (false).
bool chessBoard[8][8] = {false};

// Función para imprimir el tablero de ajedrez y los movimientos realizados.
void printChessBoard(const int movesX[], const int movesY[], int movesMadeCount) {
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
	for (int i = 0; i < movesMadeCount; i++) {
		char column = 'A' + movesX[i]; // Calcula la columna
		char row = '8' - movesY[i];    // Calcula la fila
		std::cout << column << row << " ";
	}
	printf("]\n\n");
}


// Función para verificar si un movimiento es válido.
// Concepto Teórico (Restricción de Límites y Estado):
// Un paso es viable si y solo si cae dentro de las coordenadas físicas del tablero de ajedrez (8x8)
// y si la casilla destino no ha sido previamente visitada en la ruta actual.
bool isMoveValid(int xPosition, int yPosition) {
	if (xPosition >= 0 && xPosition < 8 && yPosition >= 0 && yPosition < 8 && !chessBoard[yPosition][xPosition]) {
		return true;
	}
	return false;
}


// Función recursiva para encontrar el recorrido del caballo (Knight's Tour) usando Backtracking.
// Concepto Teórico (Camino Hamiltoniano en un Grafo de Rejilla):
// El objetivo es encontrar una secuencia de movimientos legales para que el caballo visite cada una de las 
// 64 casillas del tablero exactamente una vez. Representa una búsqueda en profundidad (DFS) en el espacio de estados.
bool findKnightTour(int xPosition, int yPosition, int movesX[], int movesY[], int &movesMadeCount) {
	// Caso base: Si la cantidad de movimientos es 64, significa que hemos visitado
	// todas las casillas del tablero (8x8 = 64) exactamente una vez. Hemos encontrado
	// un recorrido completo exitoso.
	if (movesMadeCount == 64) {
		printf("\n\e[1;32m[RESULTADO]\e[0m El caballo ha completado el recorrido.\n");
		printChessBoard(movesX, movesY, movesMadeCount); 
		return true;
	}

	// Si el movimiento planteado a esta casilla es válido, intentamos avanzar por esta rama
	if (isMoveValid(xPosition, yPosition)) {
		// 1. Tomar decisión: Marcar la casilla como visitada en la matriz global
		//    y registrar la coordenada en el historial de movimientos.
		chessBoard[yPosition][xPosition] = true; 
		movesX[movesMadeCount] = xPosition;
		movesY[movesMadeCount] = yPosition;
		movesMadeCount++;

		// 2. Exploración recursiva:
		// Un caballo de ajedrez tiene hasta 8 movimientos posibles en forma de "L".
		// Intentamos cada uno de ellos en secuencia. Si alguno de ellos tiene éxito en completar
		// el recorrido (retorna true), propagamos ese éxito retornando true inmediatamente (poda de búsqueda).
		
		// Movimiento 1: Dos pasos a la derecha, uno arriba
		if (findKnightTour(xPosition + 2, yPosition + 1, movesX, movesY, movesMadeCount)) return true;
		// Movimiento 2: Dos pasos a la derecha, uno abajo
		if (findKnightTour(xPosition + 2, yPosition - 1, movesX, movesY, movesMadeCount)) return true;
		// Movimiento 3: Dos pasos a la izquierda, uno arriba
		if (findKnightTour(xPosition - 2, yPosition + 1, movesX, movesY, movesMadeCount)) return true;
		// Movimiento 4: Dos pasos a la izquierda, uno abajo
		if (findKnightTour(xPosition - 2, yPosition - 1, movesX, movesY, movesMadeCount)) return true;
		// Movimiento 5: Un paso a la derecha, dos arriba
		if (findKnightTour(xPosition + 1, yPosition + 2, movesX, movesY, movesMadeCount)) return true;
		// Movimiento 6: Un paso a la derecha, dos abajo
		if (findKnightTour(xPosition + 1, yPosition - 2, movesX, movesY, movesMadeCount)) return true;
		// Movimiento 7: Un paso a la izquierda, dos arriba
		if (findKnightTour(xPosition - 1, yPosition + 2, movesX, movesY, movesMadeCount)) return true;
		// Movimiento 8: Un paso a la izquierda, dos abajo
		if (findKnightTour(xPosition - 1, yPosition - 2, movesX, movesY, movesMadeCount)) return true;

		// 3. Deshacer decisión (Backtracking):
		// Si llegamos a esta línea, significa que ninguno de los 8 movimientos posibles desde la casilla
		// actual nos condujo a una solución completa (camino sin salida). 
		// Desmarcamos esta casilla como visitada y decrementamos el contador de movimientos. 
		// De esta forma, dejamos el tablero intacto para que otros caminos alternativos puedan usar esta casilla.
		chessBoard[yPosition][xPosition] = false; 
		movesMadeCount--;
	}

	return false; // Retorna false informando al nivel anterior que este camino no tuvo éxito.
}


int main() {
	std::cout << "\n\e[1;35m[========= E10-RECORRIDO-DEL-CABALLO =========]\e[0m\n\n";

	int movesX[64] = {0};
	int movesY[64] = {0};
	int movesMadeCount = 0;

	if (!findKnightTour(7, 0, movesX, movesY, movesMadeCount)) { // Inicia el recorrido desde la posición inicial (H1)
		// Mensaje de error si no se puede completar el recorrido
		printf("\n\e[1;31m[ERROR]\e[0m No se pudo completar el recorrido del caballo.\n");
	}

	return 0; // Finaliza el programa
}
