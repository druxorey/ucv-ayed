#pragma once

#include "drxnode.hpp"
#include <iostream>
#include <stdexcept>

// Estructura de Cola (DrxQueue).
// Una Cola es una estructura de datos de tipo FIFO (First In, First Out -
// Primero en entrar, Primero en salir). Es similar a una fila en el banco: el
// cliente que llega primero se atiende primero, y los nuevos clientes se forman
// al final.
// T representa el tipo de dato de los elementos en la cola.
template <typename T> class DrxQueue {
  public:
	// Constructor por defecto: Inicializa una cola vacía.
	DrxQueue() : _front(nullptr), _rear(nullptr), _size(0) {}

	// Destructor: Libera dinámicamente toda la memoria de los nodos en la cola.
	~DrxQueue() { clear(); }

	// Constructor de copia profunda.
	DrxQueue(const DrxQueue<T> &other)
		: _front(nullptr), _rear(nullptr), _size(0) {
		SimpleNode<T> *curr = other._front;
		while (curr != nullptr) {
			push(curr->payload);
			curr = curr->next;
		}
	}

	// Operador de asignación profunda.
	DrxQueue<T> &operator=(const DrxQueue<T> &other) {
		if (this != &other) {
			clear();
			SimpleNode<T> *curr = other._front;
			while (curr != nullptr) {
				push(curr->payload);
				curr = curr->next;
			}
		}
		return *this;
	}

	// Verifica si la cola está vacía.
	bool isEmpty() const { return _front == nullptr; }

	// Obtiene el tamaño actual de la cola.
	int size() const { return _size; }

	// Encola un nuevo elemento al final (rear) de la cola.
	// Operación O(1) usando el puntero de control del final de la fila.
	void push(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		if (isEmpty()) {
			_front = _rear = newNode;
		} else {
			_rear->next = newNode;
			_rear = newNode;
		}
		_size++;
	}

	// Desencola el elemento que está al principio (front) de la cola.
	// Operación O(1). Mueve la referencia de inicio y libera la memoria física
	// del nodo antiguo.
	void pop() {
		if (isEmpty())
			return;
		SimpleNode<T> *temp = _front;
		_front = _front->next;
		if (_front == nullptr) {
			_rear = nullptr; // Si la cola se vació, el final también es nulo
		}
		delete temp;
		_size--;
	}

	// Obtiene una referencia al elemento al principio de la cola.
	T &front() {
		if (isEmpty()) {
			throw std::runtime_error("Cola vacía");
		}
		return _front->payload;
	}

	// Obtiene una referencia constante al elemento al principio de la cola.
	const T &front() const {
		if (isEmpty()) {
			throw std::runtime_error("Cola vacía");
		}
		return _front->payload;
	}

	// Vacia la cola eliminando todos sus nodos.
	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}

	// Imprime el contenido de la cola con fines educativos.
	void print() const {
		SimpleNode<T> *curr = _front;
		int index = 1;
		while (curr != nullptr) {
			if (index == 1) {
				std::cout << "  Front " << index << " : [" << curr->payload << "]\n";
			} else if (curr->next == nullptr) {
				std::cout << "   Rear " << index << " : [" << curr->payload << "]\n";
			} else {
				std::cout << "        " << index << " : [" << curr->payload << "]\n";
			}
			curr = curr->next;
			index++;
		}
	}

  private:
	SimpleNode<T> *_front; // Puntero al principio de la cola (primer elemento en salir).
	SimpleNode<T> *_rear;  // Puntero al final de la cola (lugar de inserción O(1)).
	int _size;             // Tamaño actual
};

// Imprime los elementos de la cola.
template <typename T> inline void printQueue(const DrxQueue<T> &queue) {
	queue.print();
}
