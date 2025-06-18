#pragma once // Evitar inclusión múltiple del archivo de cabecera

#include <iostream> // Biblioteca para entrada y salida estándar
#include <cstdlib> // Biblioteca para funciones de utilidad general
#include <list> // Biblioteca para utilizar listas

// Clase plantilla que representa una celda en la matriz esparcida
// Una celda contiene la fila, columna y el valor almacenado en esa posición
template<typename datatype>
class Cell {
	public:
		unsigned int row; // Índice de la fila de la celda
		unsigned int column; // Índice de la columna de la celda
		datatype value; // Valor almacenado en la celda

		// Constructor por defecto que inicializa fila y columna a 0
		Cell() : row(0), column(0) {}

		// Constructor que inicializa fila y columna con índices dados
		Cell(unsigned int rowIndex, unsigned int columnIndex) : row(rowIndex), column(columnIndex) {}

		// Constructor que inicializa fila, columna y valor con parámetros dados
		Cell(unsigned int rowIndex, unsigned int columnIndex, datatype value) : row(rowIndex), column(columnIndex), value(value) {}
};

// Clase plantilla que representa una fila en la matriz esparcida
// Una fila contiene un índice y una lista de celdas que pertenecen a esa fila
template<typename datatype>
class Row {
	public:
		unsigned int index; // Índice de la fila
		std::list<Cell<datatype>> cells; // Lista de celdas en la fila

		// Constructor por defecto que inicializa el índice a 0
		Row() : index(0) {}

		// Constructor que inicializa el índice con un parámetro dado
		Row(unsigned int index) : index(index) {}
};

// Clase plantilla que representa una matriz esparcida
// Una matriz esparcida almacena solo los elementos diferentes de un valor nulo (nullValue)
template<typename datatype>
class SparseMatrix {
	public:
		// Constructor que inicializa el valor nulo (nullValue)
		SparseMatrix(datatype nullValue) : nullValue(nullValue) {}

		// Método para obtener el valor en una posición específica (fila y columna)
		datatype get(int rowIndex, int columnIndex);

		// Método para establecer el valor en una posición específica (fila y columna)
		void set(int rowIndex, int columnIndex, datatype value);

		// Método para llenar la matriz con valores aleatorios
		void fill(int rows, int columns, int elements);

		// Método para imprimir la matriz en formato visual
		void print(int rows, int columns);

	private:
		datatype nullValue; // Valor que se devuelve cuando el elemento no existe
		std::list<Row<datatype>> rows; // Lista de filas en la matriz

		// Método para obtener un puntero a una fila por su índice
		Row<datatype>* getRow(int index);

		// Método para obtener un puntero a una celda por su fila y columna
		Cell<datatype>* getCell(Row<datatype>* row, int column);
};

// Implementación del método get
// Devuelve el valor almacenado en una posición específica de la matriz
template<typename datatype>
datatype SparseMatrix<datatype>::get(int rowIndex, int columnIndex) {
	Row<datatype>* thisRow = getRow(rowIndex);

	// Si la fila no existe, devuelve el valor nulo
	if (thisRow == nullptr) return this->nullValue;

	Cell<datatype>* thisCell = getCell(thisRow, columnIndex);

	// Si la celda no existe, devuelve el valor nulo
	if (thisCell == nullptr) return this->nullValue;

	// Devuelve el valor de la celda
	return thisCell->value;
}

// Implementación del método set
// Establece un valor en una posición específica de la matriz
template<typename datatype>
void SparseMatrix<datatype>::set(int rowIndex, int columnIndex, datatype value) {
	Row<datatype>* thisRow = getRow(rowIndex);
	
	// Si la fila no existe, crea una nueva fila y la añade a la lista
	if (thisRow == nullptr) {
		Row<datatype> newRow(rowIndex);
		this->rows.push_back(Row<datatype>(rowIndex)); // Inserta la nueva fila en la lista de filas
		thisRow = &this->rows.back(); // Obtiene la referencia a la fila creada
	}

	Cell<datatype>* thisCell = getCell(thisRow, columnIndex);

	// Si la celda no existe, crea una nueva celda y la añade a la lista
	if (thisCell == nullptr) {
		Cell<datatype> newCell(rowIndex, columnIndex, this->nullValue);
		thisRow->cells.push_back(Cell<datatype>(rowIndex, columnIndex, this->nullValue)); // Inserta la celda en la lista de celdas de la fila
		thisCell = &thisRow->cells.back(); // Obtiene la referencia a la celda creada
	}

	// Establece el valor de la celda
	thisCell->value = value;
}

// Implementación del método getRow
// Busca y devuelve un puntero a la fila con el índice dado
template<typename datatype>
Row<datatype>* SparseMatrix<datatype>::getRow(int index) {
	// Itera sobre las filas para encontrar la fila con el índice dado
	for (auto& row : rows) if (row.index == index) return &row;
	return nullptr;
}

// Implementación del método getCell
// Busca y devuelve un puntero a la celda con la columna dada en una fila específica
template<typename datatype>
Cell<datatype>* SparseMatrix<datatype>::getCell(Row<datatype>* row, int column) {
	if (row == nullptr) return nullptr;

	// Itera sobre las celdas para encontrar la celda con la columna dada
	for (auto& cell : row->cells) {
		if (cell.column == column) return &cell;
	}

	return nullptr;
}

// Método para llenar la matriz con valores aleatorios
// Genera un número específico de elementos en posiciones aleatorias
template<typename datatype>
void SparseMatrix<datatype>::fill(int rows, int columns, int elements) {
	int thisRow, thisColumn, newValue;
	srand(time(NULL)); // Inicializa la semilla para números aleatorios

	int maxElements = columns * rows; // Calcula el número máximo de elementos posibles
	if (elements > maxElements) elements = maxElements; // Ajusta el número de elementos si excede el máximo

	for (int i = 0; i < elements; i++) {
		thisRow = rand() % rows; // Genera una fila aleatoria
		thisColumn = rand() % columns; // Genera una columna aleatoria
		newValue = rand() % 10; // Genera un valor aleatorio entre 0 y 9

		// Si la posición ya tiene un valor diferente de 0, intenta con otro elemento
		if (get(thisRow, thisColumn) != 0) {
			elements++;
			continue;
		}

		// Establece el valor en la posición generada
		set(thisRow, thisColumn, newValue);
	}
}

// Implementación del método print
// Imprime la matriz en formato visual con separadores
template<typename datatype>
void SparseMatrix<datatype>::print(int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		std::cout << "\e[0;34m|\e[0m"; // Imprime el separador inicial
		for (int j = 0; j < columns; j++) {
			int value = this->get(i, j); // Obtiene el valor en la posición actual
			std::cout << value; // Imprime el valor
			std::cout << "\e[0;34m|\e[0m"; // Imprime el separador
		}
		std::cout << '\n'; // Salta a la siguiente línea
	}
}
