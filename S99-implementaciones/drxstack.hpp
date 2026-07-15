#pragma once

#include "drxnode.hpp"
#include <iostream>
#include <stdexcept>

// Estructura de Pila (DrxStack).
// Una Pila es una estructura de datos de tipo LIFO (Last In, First Out - Último
// en entrar, Primero en salir). Es similar a una pila de platos: solo puedes
// añadir platos en la parte superior (push) y solo puedes retirar platos de la
// parte superior (pop).
// T representa el tipo de dato de los elementos en la pila.
template <typename T> class DrxStack {
  public:
	// Constructor por defecto: Inicializa una pila vacía.
	DrxStack() : _top(nullptr), _size(0) {}

	// Destructor: Se asegura de vaciar la pila liberando memoria
	// dinámica de cada nodo.
	~DrxStack() { clear(); }

	// Constructor de copia profunda.
	// Crea una copia idéntica de la pila sin compartir direcciones de memoria física.
	DrxStack(const DrxStack<T> &other) : _top(nullptr), _size(0) {
		if (other._top == nullptr) return;

		// Clonamos los nodos para mantener el orden original
		SimpleNode<T> *curr = other._top;
		SimpleNode<T> *tempHead = nullptr;
		SimpleNode<T> *tempTail = nullptr;

		while (curr != nullptr) {
			SimpleNode<T> *newNode = new SimpleNode<T>(curr->payload);
			if (tempHead == nullptr) {
				tempHead = newNode;
				tempTail = newNode;
			} else {
				tempTail->next = newNode;
				tempTail = newNode;
			}
			curr = curr->next;
		}

		// Revertir para colocar el orden en el tope correcto al insertar en nuestra pila
		curr = tempHead;
		while (curr != nullptr) {
			SimpleNode<T> *nextNode = curr->next;
			curr->next = _top;
			_top = curr;
			curr = nextNode;
		}
		_size = other._size;
	}

	// Operador de asignación profunda para evitar fugas de memoria y punteros compartidos.
	DrxStack<T> &operator=(const DrxStack<T> &other) {
		if (this != &other) {
			clear();
			if (other._top != nullptr) {
				SimpleNode<T> *curr = other._top;
				SimpleNode<T> *tempHead = nullptr;
				SimpleNode<T> *tempTail = nullptr;

				while (curr != nullptr) {
					SimpleNode<T> *newNode = new SimpleNode<T>(curr->payload);
					if (tempHead == nullptr) {
						tempHead = newNode;
						tempTail = newNode;
					} else {
						tempTail->next = newNode;
						tempTail = newNode;
					}
					curr = curr->next;
				}

				curr = tempHead;
				while (curr != nullptr) {
					SimpleNode<T> *nextNode = curr->next;
					curr->next = _top;
					_top = curr;
					curr = nextNode;
				}
				_size = other._size;
			}
		}
		return *this;
	}

	// Verifica si la pila está vacía.
	bool isEmpty() const { return _top == nullptr; }

	// Obtiene el tamaño actual de la pila.
	int size() const { return _size; }

	// Inserta un elemento en el tope de la pila.
	// Operación O(1). El nuevo nodo pasa a ser la cabeza, apuntando al antiguo tope.
	void push(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		newNode->next = _top;
		_top = newNode;
		_size++;
	}

	// Remueve el elemento del tope.
	// Operación O(1). Desvincula el nodo superior y libera su memoria física.
	void pop() {
		if (isEmpty()) return;
		SimpleNode<T> *temp = _top;
		_top = _top->next;
		delete temp;
		_size--;
	}

	// Obtiene una referencia al elemento del tope.
	T &top() {
		if (isEmpty()) throw std::runtime_error("Pila vacía");
		return _top->payload;
	}

	// Obtiene una referencia constante al elemento del tope.
	const T &top() const {
		if (isEmpty()) throw std::runtime_error("Pila vacía");
		return _top->payload;
	}

	// Vacia la pila liberando la memoria de todos sus nodos.
	void clear() {
		while (!isEmpty()) pop();
	}

	// Imprime el contenido de la pila con fines educativos.
	void print() const {
		DrxStack<T> temp = *this;
		int index = 1;
		while (!temp.isEmpty()) {
			if (index == 1) {
				std::cout << "   Top " << index << " : [" << temp.top() << "]\n";
			} else if (temp.size() == 1) {
				std::cout << "Bottom " << index << " : [" << temp.top() << "]\n";
			} else {
				std::cout << "       " << index << " : [" << temp.top() << "]\n";
			}
			temp.pop();
			index++;
		}
	}
};

// Imprime los elementos de una pila.
template <typename T> inline void printStack(const DrxStack<T> &stack) {
	stack.print();
}
