#include <iostream>
#include "../S99-implementaciones/drxsparse.hpp"
#include "../S99-implementaciones/drxlist.hpp"

// Extrae los elementos de la diagonal principal de la matriz esparcida NxN.
// Concepto Teórico (Matrices Esparcidas y Diagonalización):
// Una Matriz Esparcida (Sparse Matrix) es aquella donde la mayoría de las celdas contienen el valor nulo (generalmente 0).
// Para no desperdiciar memoria con arreglos bidimensionales O(N * M), se implementa mediante Listas Ortogonales,
// donde cada elemento no nulo se enlaza horizontalmente (en su fila) y verticalmente (en su columna).
// - La diagonal principal de una matriz cuadrada cumple la propiedad matemática de fila == columna: (i, i).
// - Consultamos secuencialmente las posiciones (i, i). Si la celda contiene un elemento no nulo en la estructura,
//   lo recolectamos en la lista simple.
DrxSimplyList<int> getSparseDiagonal(DrxSparseMatrix<int>& matrix, int n) {
    DrxSimplyList<int> diagonal;

    // Los elementos de la diagonal principal cumplen que fila == columna (i, i)
    for (int i = 0; i < n; i++) {
        int value = matrix.get(i, i); // Obtener valor en (i, i). Si no existe enlace, retorna el nulo por defecto (0)
        if (value != 0) {
            diagonal.pushBack(value); // Agregar elemento de la diagonal a la lista de salida
        }
    }
    return diagonal;
}


int main() {
    std::cout << "\n\e[0;35m[========= E06-DIAGONAL-ESPARCIDA =========]\e[0m\n\n";

    int n = 4;
    DrxSparseMatrix<int> matrix(0); // 0 representa el valor nulo por defecto

    std::cout << "Inicializando matriz esparcida con valores...\n";
    matrix.set(0, 0, 10); // Diagonal principal
    matrix.set(0, 2, 55);
    matrix.set(1, 1, 20); // Diagonal principal
    matrix.set(2, 2, 0);  // Nulo en la diagonal
    matrix.set(3, 1, 44);
    matrix.set(3, 3, 40); // Diagonal principal

    std::cout << "\nVisualizando la matriz esparcida (4x4):\n";
    matrix.print(n, n);

    DrxSimplyList<int> diagList = getSparseDiagonal(matrix, n);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Elementos de la diagonal principal en la lista:\n";
    diagList.print();
    std::cout << "\n";

    return 0;
}
