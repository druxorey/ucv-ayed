#include <iostream>
#include "../S99-implementaciones/drxsparse.hpp"

// Función que recorre e imprime los elementos no nulos de una matriz esparcida de forma detallada.
// Concepto Teórico (Recorrido y Visualización Selectiva de Elementos Activos):
// En las matrices esparcidas, la mayor parte de las celdas están vacías (contienen el nulo por defecto).
// Para mostrar un reporte limpio, realizamos una exploración bidimensional en la que ignoramos las celdas nulas,
// detectando y mostrando únicamente los "elementos activos" (no nulos) junto con sus coordenadas de fila y columna (i, j).
// Esto reduce la contaminación visual y se enfoca en los datos útiles de la estructura de datos comprimida.
void displayNonZeroElements(DrxSparseMatrix<double>& matrix, int rows, int cols) {
    std::cout << "Elementos activos de la matriz (Fila, Columna) -> Valor:\n";
    bool hasElements = false; // Bandera para validar si la matriz posee al menos un elemento no nulo

    // Recorrido espacial completo de la matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double val = matrix.get(i, j); // Recuperar valor de la posición (i, j)
            // Si el valor no es el nulo por defecto (0.0), se reporta como activo
            if (val != 0.0) {
                std::cout << "  - Posición (" << i << ", " << j << ") -> \e[1;33m" << val << "\e[0m\n";
                hasElements = true;
            }
        }
    }

    if (!hasElements) {
        std::cout << "  (La matriz no contiene elementos no nulos)\n";
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E08-IMPRIMIR-ESPARCIDA =========]\e[0m\n\n";

    int rows = 3;
    int cols = 5;
    DrxSparseMatrix<double> matrix(0.0);

    // Cargar datos
    matrix.set(0, 1, 3.14);
    matrix.set(1, 4, 9.81);
    matrix.set(2, 2, 2.71);

    std::cout << "Representación visual de la matriz esparcida (3x5):\n";
    matrix.print(rows, cols);
    std::cout << "\n";

    std::cout << "\e[1;32m[RESULTADO]\e[0m ";
    displayNonZeroElements(matrix, rows, cols);
    std::cout << "\n";

    return 0;
}
