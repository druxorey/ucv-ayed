#pragma once

#include <iostream>

// Nodo de Árbol Binario de Búsqueda (BST).
// Contiene enlaces para el hijo izquierdo (menores) e hijo derecho (mayores).
// T representa el tipo de dato a almacenar.
template <typename T> class DrxBstNode {
  public:
	T value;
	DrxBstNode<T> *leftChild;  // Puntero a valores menores.
	DrxBstNode<T> *rightChild; // Puntero a valores mayores.

	// Constructor por defecto.
	// Inicializa el valor por defecto del tipo T y los punteros hijos a nulo.
	DrxBstNode() : value(T()), leftChild(nullptr), rightChild(nullptr) {}


	// Constructor paramétrico.
	// Inicializa la celda con el valor dado y los hijos a nulo.
	DrxBstNode(T val) : value(val), leftChild(nullptr), rightChild(nullptr) {}


	// Destructor recursivo del nodo.
	// Libera automáticamente la memoria de los subárboles izquierdo y derecho.
	~DrxBstNode() {
		if (leftChild != nullptr) delete leftChild;
		if (rightChild != nullptr) delete rightChild;
	}


	// Verifica si el nodo actual es una hoja (no tiene hijos).
	bool isLeaf() const {
		return leftChild == nullptr && rightChild == nullptr;
	}


	// Sobrecarga del operador de salida en flujo para imprimir el nodo.
	friend std::ostream &operator<<(std::ostream &out, const DrxBstNode<T> &node) {
		out << "BstNode Payload: " << node.value;
		out << " Left Child: ";
		if (node.leftChild) out << node.leftChild->value;
		else out << "null";
		out << " Right Child: ";
		if (node.rightChild) out << node.rightChild->value;
		else out << "null";
		return out;
	}
};


// Árbol Binario de Búsqueda (Binary Search Tree - BST).
// El BST es un árbol binario que cumple con una propiedad invariante
// fundamental: para cualquier nodo N, todos los elementos en su subárbol
// izquierdo son MENORES que N, y todos los elementos en su subárbol derecho son
// MAYORES que N. Esto permite búsquedas, inserciones y eliminaciones en tiempo
// promedio de O(log N).
// T representa el tipo de dato.
template <typename T> class DrxBst {
  public:
	DrxBstNode<T> *root;

	// Constructor por defecto: Inicializa el árbol vacío.
	DrxBst() : root(nullptr) {}


	// Destructor del árbol: Libera la raíz de manera recursiva.
	~DrxBst() {
		if (root != nullptr) {
			delete root;
			root = nullptr;
		}
	}


	// Inserta un nuevo valor en el árbol manteniendo la propiedad de orden.
	void insert(T value) { insert(value, root); }


	// Busca recursivamente si un valor existe en el árbol.
	bool found(T value) const { return found(value, root); }

  private:
	// Función recursiva de inserción.
	// Se sumerge a la izquierda si el valor es menor, o a la derecha si es
	// mayor, hasta encontrar un puntero vacío (nullptr) donde ubicar el nuevo nodo.
	void insert(T value, DrxBstNode<T> *&node) {
		if (node == nullptr) {
			node = new DrxBstNode<T>(value);
			return;
		}
		if (node->value == value)
			return; // Propiedad de conjunto: no admitimos duplicados
		if (value < node->value) {
			insert(value, node->leftChild);
		} else {
			insert(value, node->rightChild);
		}
	}


	// Función recursiva de búsqueda.
	// Toma decisiones binarias en cada paso basándose en la propiedad de orden del BST.
	bool found(T value, DrxBstNode<T> *node) const {
		if (node == nullptr) return false;
		if (node->value == value) return true;
		if (value < node->value) return found(value, node->leftChild);
		return found(value, node->rightChild);
	}
};
