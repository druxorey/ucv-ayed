#include <iostream>

// Generador congruencial lineal simple para obtener números pseudoaleatorios sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 987654321;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 100;
}


// Imprime el estado del laberinto en la consola con colores.
void printMatrix(int** matrix, int mazeSize) {
    for (int i = 0; i < mazeSize; i++) {
        std::cout << "\e[0;34m|\e[0m";
        for (int j = 0; j < mazeSize; j++) {
            int val = matrix[i][j];
            if (val == 2) {
                std::cout << " \e[1;32mX\e[0m \e[0;34m|\e[0m";
            } else if (val == 1) {
                std::cout << " \e[1;31m#\e[0m \e[0;34m|\e[0m";
            } else {
                std::cout << "   \e[0;34m|\e[0m";
            }
        }
        std::cout << '\n';
    }
}


// Genera obstáculos aleatorios en el laberinto.
void generateMaze(int** mazeGrid, int mazeSize) {
    for (int row = 0; row < mazeSize; row++) {
        for (int col = 0; col < mazeSize; col++) {
            if (nextRandom() <= 25) mazeGrid[row][col] = 1;
            else mazeGrid[row][col] = 0;
        }
    }
    // Asegurar que la entrada y la salida estén limpias
    mazeGrid[0][0] = 0;
    mazeGrid[mazeSize - 1][mazeSize - 1] = 0;
}


// Verifica si la celda es transitable y está dentro de los límites.
// Concepto Teórico (Restricción Física y Estado de Celda):
// Una celda es válida si se encuentra dentro de los límites de la matriz (0 a mazeSize-1)
// y está vacía/disponible (valor 0). Si es un muro (valor 1) o ya pertenece al camino actual 
// (valor 2), se descarta para evitar colisiones y bucles infinitos.
bool isCellValid(int** mazeGrid, int mazeSize, int row, int col) {
    if (row < 0 || col < 0 || row >= mazeSize || col >= mazeSize) return false;
    if (mazeGrid[row][col] != 0) return false; // Solo transitable si es 0 (limpio y no visitado)
    return true;
}


// Algoritmo de backtracking para la búsqueda de un camino en el laberinto.
// Concepto Teórico (Búsqueda en Rejillas Bidimensionales):
// Buscamos un camino continuo desde la entrada (0,0) hasta la salida (N-1, N-1). 
// Al entrar a una celda válida, la marcamos temporalmente como parte de la ruta (valor 2)
// y exploramos sus 4 vecinas (Abajo, Derecha, Arriba, Izquierda). Si todas fallan, 
// restauramos su estado original (valor 0) para permitir que otras rutas la utilicen.
bool findMazePath(int** mazeGrid, int mazeSize, int row = 0, int col = 0) {
    // Caso base: Llegamos a la esquina inferior derecha (meta). 
    // Marcamos la celda final como parte de la ruta, imprimimos el laberinto resuelto y retornamos éxito.
    if (row == mazeSize - 1 && col == mazeSize - 1) {
        mazeGrid[row][col] = 2;
        printf("\n\e[1;32m[RESULTADO]\e[0m ¡Se encontró un camino en el laberinto!\n\n");
        printMatrix(mazeGrid, mazeSize);
        printf("\n");
        return true;
    }

    // Si la celda es válida, intentamos explorar desde ella
    if (isCellValid(mazeGrid, mazeSize, row, col)) {
        printf("\e[1;33m[INFO]\e[0m Explorando celda (%d, %d)\n", row, col);
        
        // 1. Tomar decisión: Marcar la celda actual como parte de la ruta activa (valor 2).
        //    Esto también actúa como "visitado", impidiendo que las llamadas hijas vuelvan a entrar aquí.
        mazeGrid[row][col] = 2;

        // 2. Exploración recursiva en 4 direcciones (DFS):
        // Abajo
        if (findMazePath(mazeGrid, mazeSize, row + 1, col)) return true;
        // Derecha
        if (findMazePath(mazeGrid, mazeSize, row, col + 1)) return true;
        // Arriba
        if (findMazePath(mazeGrid, mazeSize, row - 1, col)) return true;
        // Izquierda
        if (findMazePath(mazeGrid, mazeSize, row, col - 1)) return true;

        // 3. Deshacer decisión (Backtracking):
        // Si ninguna dirección fue exitosa, esta celda es un callejón sin salida.
        // La desmarcamos devolviéndole su estado inicial (valor 0) antes de retornar false.
        mazeGrid[row][col] = 0; 
    }

    printf("\e[1;31m[INFO]\e[0m Retrocediendo desde la celda (%d, %d)\n", row, col);
    return false; // Notificar al nivel anterior que esta ruta no tiene salida
}


int main() {
    std::cout << "\n\e[0;35m[========= E12-CAMINO-DEL-LABERINTO =========]\e[0m\n\n";

    int mazeSize;
    std::cout << "Ingresa el tamaño del laberinto: ";
    if (!(std::cin >> mazeSize) || mazeSize <= 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m El tamaño debe ser mayor que cero y válido.\n\n";
        return 1;
    }

    int** mazeGrid = new int*[mazeSize];
    for (int i = 0; i < mazeSize; i++) {
        mazeGrid[i] = new int[mazeSize];
    }

    generateMaze(mazeGrid, mazeSize);

    std::cout << "\nLaberinto inicial:\n";
    printMatrix(mazeGrid, mazeSize);
    std::cout << "\n";

    if (!findMazePath(mazeGrid, mazeSize)) {
        printf("\e[1;31m[RESULTADO]\e[0m No hay un camino disponible para salir del laberinto.\n\n");
    }

    for (int i = 0; i < mazeSize; i++) {
        delete[] mazeGrid[i];
    }
    delete[] mazeGrid;

    return 0;
}
