#include <iostream>
#include "../S99-implementaciones/drxsparse.hpp"

// Busca la primera ocurrencia de un valor en la matriz esparcida.
// Concepto Teórico (Búsqueda Lineal con Detención Temprana en Matrices Esparcidas):
// Para localizar un valor específico en la matriz esparcida:
// - Recorremos el espacio lógico de la matriz por filas y columnas de manera secuencial (exploración exhaustiva).
// - Evaluamos cada celda llamando a 'matrix.get(i, j)'.
// - Si encontramos una coincidencia (incluso si buscamos el valor nulo por defecto), registramos las coordenadas
//   (i, j) en las variables pasadas por referencia 'rowFound' y 'colFound', y retornamos 'true' inmediatamente.
// - Esta salida anticipada (short-circuit) optimiza el tiempo de ejecución al no seguir recorriendo la matriz
//   una vez hallada la primera coincidencia.
// Complejidad temporal: O(rows * cols) en el peor de los casos.
bool searchInSparse(DrxSparseMatrix<int>& matrix, int rows, int cols, int valueToSearch, int& rowFound, int& colFound) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Comparar el valor de la celda con el buscado
            if (matrix.get(i, j) == valueToSearch) {
                rowFound = i; // Retornar fila por referencia
                colFound = j; // Retornar columna por referencia
                return true;  // Éxito: detener búsqueda
            }
        }
    }
    return false; // El valor no se encuentra en la matriz
}


int main() {
    std::cout << "\n\e[0;35m[========= E09-BUSCAR-ESPARCIDA =========]\e[0m\n\n";

    int rows = 4;
    int cols = 4;
    DrxSparseMatrix<int> matrix(0);

    matrix.set(0, 2, 88);
    matrix.set(1, 1, 99);
    matrix.set(2, 3, 77);

    std::cout << "Matriz esparcida:\n";
    matrix.print(rows, cols);

    int value = 99;
    int row = -1, col = -1;

    std::cout << "\nBuscando el valor " << value << " en la matriz...\n";
    if (searchInSparse(matrix, rows, cols, value, row, col)) {
        printf("\n\e[1;32m[RESULTADO]\e[0m El valor %d fue encontrado en la posición (\e[1;33m%d\e[0m, \e[1;33m%d\e[0m).\n\n", value, row, col);
    } else {
        printf("\n\e[1;31m[RESULTADO]\e[0m El valor %d NO se encuentra en la matriz.\n\n", value);
    }

    return 0;
}
