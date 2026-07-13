#pragma once

#include <iostream>
#include <stdexcept>

/**
 * @brief Estructura de Montículo Máximo (Max-Heap).
 *
 * Un Montículo (Heap) es un árbol binario completo representado de forma
 * contigua en un arreglo dinámico. Satisface la propiedad de montículo: la
 * clave de cualquier nodo es mayor o igual que las claves de sus hijos (para un
 * Max-Heap), por lo que el elemento máximo siempre reside en la raíz (posición
 * 0 del arreglo).
 *
 * Ventajas: inserción O(log N) y extracción del máximo O(log N) constantes y
 * eficientes.
 *
 * @tparam T Tipo de dato de las claves del montículo.
 */
template <typename T> class DrxHeap {
  public:
	/**
	 * @brief Constructor: Reserva memoria para la capacidad inicial
	 * especificada.
	 */
	DrxHeap(const int resizeStep = 16)
		: resizeStep(resizeStep), elementCount(0), actualSize(resizeStep) {
		data = new T[resizeStep];
	}

	~DrxHeap() { delete[] data; }

	/**
	 * @brief Constructor de copia profunda.
	 */
	DrxHeap(const DrxHeap<T> &other)
		: resizeStep(other.resizeStep), elementCount(other.elementCount),
		  actualSize(other.actualSize) {
		data = new T[actualSize];
		for (int i = 0; i < elementCount; i++) {
			data[i] = other.data[i];
		}
	}

	/**
	 * @brief Operador de asignación profunda.
	 */
	DrxHeap<T> &operator=(const DrxHeap<T> &other) {
		if (this != &other) {
			delete[] data;
			elementCount = other.elementCount;
			actualSize = other.actualSize;
			data = new T[actualSize];
			for (int i = 0; i < elementCount; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	/**
	 * @brief Remueve y retorna el elemento máximo (la raíz/tope) del montículo.
	 * Intercambia la raíz con el último elemento, reduce el conteo y hunde la
	 * nueva raíz a su posición correcta (sink/heapify-down) en O(log N).
	 */
	T top() {
		if (isEmpty()) throw std::runtime_error("El montículo está vacío");
		T topValue = data[0];

		// Mover el último elemento del arreglo a la raíz
		data[0] = data[elementCount - 1];
		elementCount--;

		// Redimensionar el arreglo si queda demasiado espacio ocioso
		if (actualSize - elementCount > resizeStep && actualSize > resizeStep) {
			resizeArray(actualSize - resizeStep);
		}

		// Hundir la raíz para restablecer la propiedad de montículo
		sinkValue(0);
		return topValue;
	}

	/**
	 * @brief Inserta un nuevo elemento en el montículo.
	 * Coloca el elemento al final del arreglo dinámico y lo hace flotar
	 * (float/heapify-up) hacia arriba comparándolo con su padre hasta que se
	 * cumpla la propiedad en O(log N).
	 */
	void insert(T x) {
		if (elementCount + 1 > actualSize) {
			resizeArray(actualSize + resizeStep);
		}

		data[elementCount] = x;
		elementCount++;
		floatValue(elementCount - 1);
	}

	bool isEmpty() const { return elementCount <= 0; }

	int size() const { return elementCount; }

	/**
	 * @brief Mezcla otro montículo en este.
	 */
	void merge(DrxHeap<T> other) {
		while (!other.isEmpty()) {
			insert(other.top());
		}
	}

	/**
	 * @brief Mezcla otro montículo sin añadir claves duplicadas.
	 */
	void mergeWithoutDuplicates(DrxHeap<T> other) {
		while (!other.isEmpty()) {
			T val = other.top();
			bool found = false;
			for (int i = 0; i < elementCount; i++) {
				if (data[i] == val) {
					found = true;
					break;
				}
			}
			if (!found) insert(val);
		}
	}

	friend std::ostream &operator<<(std::ostream &out, const DrxHeap<T> &heap) {
		out << "Data: ";
		for (int i = 0; i < heap.elementCount; i++) {
			out << heap.data[i] << "; ";
		}
		out << "\nElement Count: " << heap.elementCount
			<< ", Capacity: " << heap.actualSize;
		return out;
	}

  private:
	const int resizeStep; // Paso de redimensionamiento.
	int elementCount;     // Conteo de elementos almacenados.
	int actualSize;       // Capacidad máxima física del arreglo.
	T *data;              // Arreglo dinámico contenedor.

	/**
	 * @brief Redimensiona dinámicamente el arreglo a un nuevo tamaño físico.
	 */
	void resizeArray(int newSize) {
		T *newData = new T[newSize];
		for (int i = 0; i < elementCount; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		actualSize = newSize;
	}

	// FÓRMULAS DE DIRECCIONAMIENTO ARITMÉTICO:
	// Dado que el árbol es completo, podemos calcular los índices de padres e
	// hijos directamente:
	int getLeftChildIndex(int parentIndex) const { return parentIndex * 2 + 1; }

	int getRightChildIndex(int parentIndex) const {
		return parentIndex * 2 + 2;
	}

	int getParentIndex(int childIndex) const { return (childIndex - 1) / 2; }

	/**
	 * @brief Verifica si un nodo cumple la propiedad local de montículo máximo
	 * con sus hijos.
	 */
	bool isHeap(int parentIndex) const {
		if (parentIndex < 0) return true;

		int leftIndex = getLeftChildIndex(parentIndex);
		int rightIndex = getRightChildIndex(parentIndex);

		if (leftIndex < elementCount && data[parentIndex] < data[leftIndex])
			return false;
		if (rightIndex < elementCount && data[parentIndex] < data[rightIndex])
			return false;

		return true;
	}

	void swap(int indexA, int indexB) {
		T aux = data[indexA];
		data[indexA] = data[indexB];
		data[indexB] = aux;
	}

	/**
	 * @brief Hunde un valor en la jerarquía (Heapify-Down).
	 * Compara el nodo con sus dos hijos e intercambia con el mayor de ellos,
	 * repitiendo recursivamente hasta que el nodo sea mayor que ambos hijos.
	 */
	void sinkValue(int parentIndex) {
		if (isHeap(parentIndex)) return;

		int leftChild = getLeftChildIndex(parentIndex);
		int rightChild = getRightChildIndex(parentIndex);

		int maxIndex = leftChild;
		if (rightChild < elementCount && data[rightChild] > data[leftChild]) {
			maxIndex = rightChild;
		}

		if (data[parentIndex] < data[maxIndex]) {
			swap(maxIndex, parentIndex);
			if (maxIndex < elementCount - 1) {
				sinkValue(maxIndex);
			}
		}
	}

	/**
	 * @brief Hace flotar un valor en la jerarquía (Heapify-Up).
	 * Compara el nodo actual con su padre. Si es mayor, los intercambia
	 * y continúa flotando recursivamente hacia la raíz.
	 */
	void floatValue(int childIndex) {
		if (childIndex <= 0) return;
		int parentIndex = getParentIndex(childIndex);

		if (data[parentIndex] < data[childIndex]) {
			swap(childIndex, parentIndex);
			floatValue(parentIndex);
		}
	}
};
