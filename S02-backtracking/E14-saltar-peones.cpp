#include <iostream>

const int EMPTY = 0;
const int WHITE = 1;
const int BLACK = 2;

struct Position {
    int r, c;
};

// Direcciones en cruz: arriba, abajo, izquierda, derecha
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// Cuenta cuántos peones blancos quedan en el tablero.
int countWhitePawns(int** board, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == WHITE) count++;
        }
    }
    return count;
}


// Búsqueda recursiva backtracking para eliminar todos los peones blancos con límite de coste.
// Concepto Teórico (Búsqueda en Grafos de Juego Acotada por Coste / Pruning por Coste):
// Buscamos eliminar todos los peones blancos mediante saltos de captura en un coste acumulado <= moveLimit.
// La exploración es un árbol de decisiones con dos tipos de transiciones por dirección (desplazarse o capturar).
// Llevamos un registro de la ruta actual ('path') y del coste de la trayectoria ('currentCost').
bool solveJumps(int r, int c, int moveLimit, int currentCost, int** board, int n, Position path[], int& pathCount) {
    // Caso base de éxito: Si no quedan peones blancos en el tablero, hemos resuelto el problema.
    if (countWhitePawns(board, n) == 0) {
        return true;
    }

    // Poda por costo (Branch and Bound básico):
    // Si el coste acumulado actual supera o iguala el límite máximo permitido, podamos esta rama,
    // ya que cualquier paso posterior excedería el presupuesto.
    if (currentCost >= moveLimit) {
        return false;
    }

    // Probar las 4 direcciones de movimiento (Arriba, Abajo, Izquierda, Derecha)
    for (int dir = 0; dir < 4; dir++) {
        int nr1 = r + dr[dir];
        int nc1 = c + dc[dir];

        // Validar límites del primer paso adyacente
        if (nr1 >= 0 && nr1 < n && nc1 >= 0 && nc1 < n) {
            // Opción 1: Movimiento simple a una casilla vacía adyacente (Costo: 1, sin captura).
            if (board[nr1][nc1] == EMPTY) {
                // Tomar decisión: Registrar nueva posición en la ruta
                path[pathCount] = {nr1, nc1};
                pathCount++;

                // Exploración recursiva incrementando el coste en 1
                if (solveJumps(nr1, nc1, moveLimit, currentCost + 1, board, n, path, pathCount)) {
                    return true; // Propagar éxito si se solucionó
                }

                // Deshacer decisión (Backtracking): Remover la celda de la ruta activa
                pathCount--; 
            }
            // Opción 2: Salto de captura sobre un peón blanco hacia la casilla subsiguiente (Costo: 2).
            else if (board[nr1][nc1] == WHITE) {
                // Calcular coordenada destino del salto (dos unidades en la misma dirección)
                int nr2 = r + 2 * dr[dir];
                int nc2 = c + 2 * dc[dir];

                // Comprobar que la casilla destino del salto esté dentro del tablero y esté vacía
                if (nr2 >= 0 && nr2 < n && nc2 >= 0 && nc2 < n && board[nr2][nc2] == EMPTY) {
                    // Tomar decisión: 
                    // a) Capturar (eliminar) el peón blanco temporalmente de la matriz
                    board[nr1][nc1] = EMPTY; 
                    // b) Registrar el destino del salto en la ruta
                    path[pathCount] = {nr2, nc2};
                    pathCount++;

                    // Exploración recursiva incrementando el coste en 2 (penalización de captura)
                    if (solveJumps(nr2, nc2, moveLimit, currentCost + 2, board, n, path, pathCount)) {
                        return true;
                    }

                    // Deshacer decisión (Backtracking):
                    // a) Restaurar el peón blanco capturado en su celda original.
                    board[nr1][nc1] = WHITE; 
                    // b) Remover el destino de la ruta activa.
                    pathCount--;
                }
            }
        }
    }

    return false; // Retorna false si no se encontró solución válida desde esta posición
}


int main() {
    std::cout << "\n\e[0;35m[========= E14-SALTAR-PEONES =========]\e[0m\n\n";

    int n, moveLimit, startR, startC;
    std::cout << "Introduce el tamaño del tablero N x N: ";
    if (!(std::cin >> n) || n <= 0) return 1;
    
    std::cout << "Introduce el límite máximo de coste de movimientos: ";
    if (!(std::cin >> moveLimit) || moveLimit < 0) return 1;

    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    std::cout << "\nIntroduce la matriz del tablero (0: Vacío, 1: Blanco, 2: Negro):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "Posición (" << i << "," << j << "): ";
            if (!(std::cin >> board[i][j])) {
                for (int k = 0; k < n; k++) delete[] board[k];
                delete[] board;
                return 1;
            }
        }
    }

    std::cout << "\nFila inicial del jugador (0 a N-1): ";
    if (!(std::cin >> startR)) {
        for (int k = 0; k < n; k++) delete[] board[k];
        delete[] board;
        return 1;
    }

    std::cout << "Columna inicial del jugador (0 a N-1): ";
    if (!(std::cin >> startC)) {
        for (int k = 0; k < n; k++) delete[] board[k];
        delete[] board;
        return 1;
    }

    if (startR < 0 || startR >= n || startC < 0 || startC >= n || board[startR][startC] != EMPTY) {
        std::cerr << "\e[1;31m[ERROR]\e[0m La posición inicial debe estar dentro del tablero y ser una casilla vacía.\n\n";
        for (int k = 0; k < n; k++) delete[] board[k];
        delete[] board;
        return 1;
    }

    Position path[1000];
    int pathCount = 0;
    path[pathCount] = {startR, startC};
    pathCount++;

    int initialWhitePawns = countWhitePawns(board, n);
    std::cout << "\nCantidad de peones blancos a saltar: " << initialWhitePawns << "\n";

    if (solveJumps(startR, startC, moveLimit, 0, board, n, path, pathCount)) {
        std::cout << "\n\e[1;32m[RESULTADO]\e[0m ¡Es posible saltar todos los peones blancos!\n";
        std::cout << "Ruta de movimientos:\n";
        for (int i = 0; i < pathCount; i++) {
            std::cout << "  Paso " << i << " -> (" << path[i].r << ", " << path[i].c << ")\n";
        }
        std::cout << "\n";
    } else {
        std::cout << "\n\e[1;31m[RESULTADO]\e[0m No es posible saltar todos los peones blancos con el límite de coste dado.\n\n";
    }

    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
