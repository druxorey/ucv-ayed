#pragma once

#include "drxnode.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

/**
 * @brief Estructura de Cola (Queue).
 *
 * Una Cola es una estructura de datos de tipo FIFO (First In, First Out -
 * Primero en entrar, Primero en salir). Es similar a una fila en el banco: el
 * cliente que llega primero se atiende primero, y los nuevos clientes se forman
 * al final.
 *
 * @tparam T Tipo de dato de los elementos en la cola.
 */
template <typename T> class DrxQueue {
  public:
	/**
	 * @brief Constructor por defecto: Inicializa una cola vacía.
	 */
	DrxQueue() : _front(nullptr), _rear(nullptr), _size(0) {}

	/**
	 * @brief Destructor: Libera dinámicamente toda la memoria de los nodos en
	 * la cola.
	 */
	~DrxQueue() { clear(); }

	/**
	 * @brief Constructor de copia profunda.
	 */
	DrxQueue(const DrxQueue<T> &other)
		: _front(nullptr), _rear(nullptr), _size(0) {
		SimpleNode<T> *curr = other._front;
		while (curr != nullptr) {
			push(curr->payload);
			curr = curr->next;
		}
	}

	/**
	 * @brief Operador de asignación profunda.
	 */
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

	bool empty() const { return _front == nullptr; }

	bool isEmpty() const { return empty(); }

	int size() const { return _size; }

	/**
	 * @brief Encola un nuevo elemento al final (rear) de la cola.
	 * Operación O(1) usando el puntero de control del final de la fila.
	 */
	void push(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		if (empty()) {
			_front = _rear = newNode;
		} else {
			_rear->next = newNode;
			_rear = newNode;
		}
		_size++;
	}

	/**
	 * @brief Desencola el elemento que está al principio (front) de la cola.
	 * Operación O(1). Mueve la referencia de inicio y libera la memoria física
	 * del nodo antiguo.
	 */
	void pop() {
		if (empty())
			return;
		SimpleNode<T> *temp = _front;
		_front = _front->next;
		if (_front == nullptr) {
			_rear = nullptr; // Si la cola se vació, el final también es nulo
		}
		delete temp;
		_size--;
	}

	/**
	 * @brief Obtiene una referencia al elemento al principio de la cola.
	 */
	T &front() {
		if (empty()) {
			throw std::runtime_error("Cola vacía");
		}
		return _front->payload;
	}

	const T &front() const {
		if (empty()) {
			throw std::runtime_error("Cola vacía");
		}
		return _front->payload;
	}

	void clear() {
		while (!empty()) {
			pop();
		}
	}

	void fill(int count, int initialValue = 0) {
		for (int i = initialValue; i < count + initialValue; i++) {
			push(i);
		}
	}

	void rand(int count) {
		srand(time(nullptr));
		for (int i = 0; i < count; i++) {
			push(std::rand() % (count * 2));
		}
	}

	void print() const {
		SimpleNode<T> *curr = _front;
		int index = 1;
		int maxNumber = std::to_string(_size).length();
		while (curr != nullptr) {
			if (index == 1) {
				std::cout << "  Front " << index << " : [\e[0;32m" << curr->payload << "\e[0m]\n";
			} else if (curr->next == nullptr) {
				std::cout << "   Rear " << index << " : [\e[0;31m" << curr->payload << "\e[0m]\n";
			} else {
				std::cout << "        " << index << " : [\e[0;33m" << curr->payload << "\e[0m]\n";
			}
			curr = curr->next;
			index++;
		}
	}

  private:
	SimpleNode<T>
		*_front; // Puntero al principio de la cola (primer elemento en salir).
	SimpleNode<T>
		*_rear; // Puntero al final de la cola (lugar de inserción O(1)).
	int _size;
};

template <typename T> inline void printQueue(const DrxQueue<T> &queue) {
	queue.print();
}
