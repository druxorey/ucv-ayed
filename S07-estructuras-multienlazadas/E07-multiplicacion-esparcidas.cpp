#include <iostream>
#include "../S99-implementaciones/drxsparse.hpp"

// Multiplica dos matrices esparcidas A y B, guardando el resultado en C.
// A: M1 x M2
// B: M2 x M3
// C: M1 x M3
// Multiplica dos matrices esparcidas A y B, guardando el resultado en C.
// Concepto Teórico (Multiplicación de Matrices Esparcidas):
// Dadas A de M1 x M2 y B de M2 x M3, la matriz resultante C es de M1 x M3. 
// Cada celda C(i, j) es el producto escalar (dot product) de la fila i de A y la columna j de B:
//   C(i, j) = sumatoria_{k=0}^{M2-1} (A(i, k) * B(k, j)).
// En la optimización para matrices esparcidas:
// - Únicamente sumamos el producto si ambos factores son distintos de cero (valA != 0 && valB != 0).
// - Solo insertamos físicamente el valor en la matriz resultante C (C.set(i, j, sum)) si el total acumulado
//   es diferente de cero, conservando la propiedad de esparcibilidad de la estructura de datos.
DrxSparseMatrix<int> multiplySparseMatrices(DrxSparseMatrix<int>& A, DrxSparseMatrix<int>& B, int M1, int M2, int M3) {
    DrxSparseMatrix<int> C(0); // Matriz resultante inicializada con valor nulo 0

    // Bucle para iterar las filas de A
    for (int i = 0; i < M1; i++) {
        // Bucle para iterar las columnas de B
        for (int j = 0; j < M3; j++) {
            int sum = 0;
            
            // Producto escalar de la fila i de A y la columna j de B
            for (int k = 0; k < M2; k++) {
                int valA = A.get(i, k);
                int valB = B.get(k, j);
                
                // Poda de multiplicación: si alguno es cero, el producto es cero y no altera la suma
                if (valA != 0 && valB != 0) {
                    sum += valA * valB;
                }
            }
            // Registrar en la matriz C únicamente si el resultado es no nulo
            if (sum != 0) {
                C.set(i, j, sum);
            }
        }
    }
    return C;
}


int main() {
    std::cout << "\n\e[0;35m[========= E07-MULTIPLICACION-ESPARCIDAS =========]\e[0m\n\n";

    // Matriz A (2x3)
    DrxSparseMatrix<int> A(0);
    A.set(0, 0, 1);
    A.set(0, 2, 2);
    A.set(1, 1, 3);

    // Matriz B (3x2)
    DrxSparseMatrix<int> B(0);
    B.set(0, 1, 4);
    B.set(1, 0, 5);
    B.set(2, 1, 6);

    std::cout << "Matriz A (2x3):\n";
    A.print(2, 3);

    std::cout << "\nMatriz B (3x2):\n";
    B.print(3, 2);

    DrxSparseMatrix<int> C = multiplySparseMatrices(A, B, 2, 3, 2);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Matriz Resultante C (2x2):\n";
    C.print(2, 2);
    std::cout << "\n";

    return 0;
}
