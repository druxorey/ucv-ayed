#pragma once

#include "drxlist.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Celda individual de la Matriz Esparcida.
// Representa un nodo que almacena únicamente los elementos con valores no nulos
// en la matriz, guardando su fila, columna y valor correspondiente.
// T representa el tipo de dato de los elementos.
template <typename T> class DrxSparseCell {
  public:
	unsigned int row;    // Índice de fila.
	unsigned int column; // Índice de columna.
	T value;             // Valor real.

	DrxSparseCell() : row(0), column(0), value(T()) {}
	DrxSparseCell(unsigned int r, unsigned int c) : row(r), column(c), value(T()) {}
	DrxSparseCell(unsigned int r, unsigned int c, T val) : row(r), column(c), value(val) {}
};

// Representación de una Fila en la Matriz Esparcida.
// Contiene una lista doblemente enlazada (`cells`) que guarda únicamente las
// celdas activas de esa fila, ordenadas lógicamente.
// T representa el tipo de dato.
template <typename T> class DrxSparseRow {
  public:
	unsigned int index;              // Índice numérico de la fila.
	DrxList<DrxSparseCell<T>> cells; // Celdas no nulas en esta fila.

	DrxSparseRow() : index(0) {}
	DrxSparseRow(unsigned int idx) : index(idx) {}
};

// Estructura de Matriz Esparcida (Sparse Matrix).
// Una matriz esparcida es una matriz en la cual la gran mayoría de los
// elementos son cero o nulos. Para evitar el desperdicio masivo de memoria de
// una matriz estática (ej. 1000x1000), se almacena dinámicamente una lista de
// filas, y dentro de cada fila, una lista de celdas activas. Las posiciones
// vacías no consumen memoria y retornan un valor nulo de referencia.
// T representa el tipo de dato.
template <typename T> class DrxSparseMatrix {
  public:
	// Constructor: Inicializa la matriz definiendo el valor de retorno nulo.
	// nullVal: Valor por defecto retornado si una posición está vacía.
	DrxSparseMatrix(T nullVal) : nullValue(nullVal) {}

	// Obtiene el valor en la fila y columna indicadas.
	// Busca la fila en O(R) y la celda correspondiente en O(C). Si no existe,
	// retorna el valor nulo.
	T get(int rowIndex, int columnIndex) {
		DrxSparseRow<T> *thisRow = getRow(rowIndex);
		if (thisRow == nullptr) return nullValue;

		DrxSparseCell<T> *thisCell = getCell(thisRow, columnIndex);
		if (thisCell == nullptr) return nullValue;

		return thisCell->value;
	}

	// Establece un valor en la fila y columna dadas.
	// Si la fila o la celda no existen, las crea dinámicamente y las enlaza a
	// la estructura.
	void set(int rowIndex, int columnIndex, T value) {
		DrxSparseRow<T> *thisRow = getRow(rowIndex);
		if (thisRow == nullptr) {
			DrxSparseRow<T> newRow(rowIndex);
			rows.pushBack(newRow);
			typename DrxList<DrxSparseRow<T>>::Iterator lastIt = rows.last();
			thisRow = rows.get(lastIt);
		}

		DrxSparseCell<T> *thisCell = getCell(thisRow, columnIndex);
		if (thisCell == nullptr) {
			DrxSparseCell<T> newCell(rowIndex, columnIndex, nullValue);
			thisRow->cells.pushBack(newCell);
			typename DrxList<DrxSparseCell<T>>::Iterator lastCellIt = thisRow->cells.last();
			thisCell = thisRow->cells.get(lastCellIt);
		}

		thisCell->value = value;
	}

	// Llena la matriz de forma aleatoria con un número determinado de
	// elementos activos.
	void fill(int rCount, int cCount, int elements) {
		srand(time(nullptr));
		int maxElements = rCount * cCount;
		if (elements > maxElements) elements = maxElements;

		for (int i = 0; i < elements; i++) {
			int thisRow = std::rand() % rCount;
			int thisColumn = std::rand() % cCount;
			T newValue = static_cast<T>(std::rand() % 10 + 1);

			if (get(thisRow, thisColumn) != nullValue) {
				elements++;
				continue;
			}

			set(thisRow, thisColumn, newValue);
		}
	}

	// Imprime la matriz en consola mostrando los bordes y valores de forma legible.
	void print(int rCount, int cCount) {
		for (int i = 0; i < rCount; i++) {
			std::cout << "\e[0;34m|\e[0m";
			for (int j = 0; j < cCount; j++) {
				T val = get(i, j);
				std::cout << val << "\e[0;34m|\e[0m";
			}
			std::cout << "\n";
		}
	}

  private:
	T nullValue;                   // Valor retornado para las celdas vacías.
	DrxList<DrxSparseRow<T>> rows; // Lista doblemente enlazada de filas.

	// Busca y retorna el puntero a la fila dada por índice.
	DrxSparseRow<T> *getRow(int index) {
		typename DrxList<DrxSparseRow<T>>::Iterator it = rows.first();
		while (it != rows.end()) {
			DrxSparseRow<T> *r = rows.get(it);
			if (r->index == index) return r;
			rows.next(it);
		}
		return nullptr;
	}

	// Busca y retorna la celda dada por columna dentro de una fila.
	DrxSparseCell<T> *getCell(DrxSparseRow<T> *row, int column) {
		if (row == nullptr) return nullptr;
		typename DrxList<DrxSparseCell<T>>::Iterator it = row->cells.first();
		while (it != row->cells.end()) {
			DrxSparseCell<T> *cell = row->cells.get(it);
			if (cell->column == column) return cell;
			row->cells.next(it);
		}
		return nullptr;
	}
};
