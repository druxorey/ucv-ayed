#include <iostream>

// Imprime el tablero de ajedrez con las reinas colocadas.
void printBoard(bool** board, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "\e[0;34m|\e[0m";
        for (int j = 0; j < size; j++) {
            if (board[i][j]) {
                std::cout << " \e[1;35mQ\e[0m \e[0;34m|\e[0m";
            } else {
                std::cout << " . \e[0;34m|\e[0m";
            }
        }
        std::cout << '\n';
    }
}


// Verifica si es seguro posicionar una reina en (row, col).
// Concepto Teórico (Restricciones del Tablero de Ajedrez):
// Dos reinas no pueden amenazarse mutuamente (no pueden estar en la misma fila, columna o diagonal).
// Dado que colocamos una reina por fila en orden descendente (de fila 0 a N-1), no necesitamos comprobar 
// filas inferiores. Solo verificamos:
// 1. La misma columna hacia arriba.
// 2. La diagonal superior izquierda.
// 3. La diagonal superior derecha.
bool isPositionSafe(bool** board, int boardSize, int row, int col) {
    // 1. Comprobar columna superior
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // 2. Comprobar diagonal superior izquierda (\)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // 3. Comprobar diagonal superior derecha (/)
    for (int i = row, j = col; i >= 0 && j < boardSize; i--, j++) {
        if (board[i][j]) return false;
    }

    return true; // La posición es segura frente a las reinas ya colocadas
}


// Solución del problema de N-Reinas por backtracking recursivo.
// Concepto Teórico (Búsqueda Sistemática fila por fila):
// Intentamos colocar una reina en cada columna de la fila actual ('row').
// Si es seguro hacerlo, avanzamos recursivamente a la siguiente fila.
// Si no se puede completar el tablero desde esa decisión (dead end), deshacemos la asignación (Backtracking)
// y probamos con la siguiente columna.
bool solveNQueens(bool** board, int boardSize, int row = 0, int placedQueens = 0) {
    // Caso base de éxito: Si la cantidad de reinas colocadas es igual a N (tamaño del tablero),
    // significa que hemos posicionado con éxito todas las reinas sin conflictos. Retornamos true.
    if (placedQueens == boardSize) return true;

    // Bucle de decisiones: Probar colocar una reina en cada columna 'col' de la fila actual 'row'
    for (int col = 0; col < boardSize; col++) {
        // Verificar si la casilla (row, col) no genera amenazas con las reinas anteriores
        if (isPositionSafe(board, boardSize, row, col)) {
            // 1. Tomar decisión: Colocar la reina en el tablero e incrementar el contador
            board[row][col] = true;
            placedQueens++;

            // 2. Exploración recursiva: Pasar a la siguiente fila (row + 1)
            if (solveNQueens(board, boardSize, row + 1, placedQueens)) return true;

            // 3. Deshacer decisión (Backtracking):
            // Si la llamada recursiva no encontró solución, retiramos la reina de la casilla 
            // y decrementamos el contador antes de intentar con la columna 'col + 1'.
            board[row][col] = false; 
            placedQueens--;
        }
    }

    return false; // Retorna false si no se pudo colocar una reina en ninguna columna de la fila actual
}


int main() {
    std::cout << "\n\e[0;35m[========= E16-OCHO-REINAS =========]\e[0m\n\n";

    int boardSize;
    std::cout << "Ingrese el tamaño del tablero: ";
    if (!(std::cin >> boardSize) || boardSize < 1) {
        printf("\n\e[1;31m[ERROR]\e[0m El tamaño del tablero debe ser mayor a cero y válido.\n\n");
        return 1;
    }

    bool** board = new bool*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        board[i] = new bool[boardSize];
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = false;
        }
    }

    if (solveNQueens(board, boardSize)) {
        printf("\n\e[1;32m[RESULTADO]\e[0m Solución encontrada:\n\n");
        printBoard(board, boardSize);
        printf("\n");
    } else {
        printf("\n\e[1;31m[RESULTADO]\e[0m No se encontró solución para un tablero de tamaño %d.\n\n", boardSize);
    }

    for (int i = 0; i < boardSize; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
