#pragma once

#include "drxnode.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

/**
 * @brief Estructura de Pila (Stack).
 *
 * Una Pila es una estructura de datos de tipo LIFO (Last In, First Out - Último
 * en entrar, Primero en salir). Es similar a una pila de platos: solo puedes
 * añadir platos en la parte superior (push) y solo puedes retirar platos de la
 * parte superior (pop).
 *
 * @tparam T Tipo de dato de los elementos en la pila.
 */
template <typename T> class DrxStack {
  public:
	/**
	 * @brief Constructor por defecto: Inicializa una pila vacía.
	 */
	DrxStack() : _top(nullptr), _size(0) {}

	/**
	 * @brief Destructor: Se asegura de vaciar la pila liberando memoria
	 * dinámica de cada nodo.
	 */
	~DrxStack() { clear(); }

	/**
	 * @brief Constructor de copia profunda.
	 * Crea una copia idéntica de la pila sin compartir direcciones de memoria
	 * física.
	 *
	 * @param other Pila a copiar.
	 */
	DrxStack(const DrxStack<T> &other) : _top(nullptr), _size(0) {
		if (other._top == nullptr) return;

		// Para mantener el orden original, clonamos la lista de nodos y la
		// insertamos
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

		// Revertir para colocar el orden en el tope correcto al insertar en
		// nuestra pila
		curr = tempHead;
		while (curr != nullptr) {
			SimpleNode<T> *nextNode = curr->next;
			curr->next = _top;
			_top = curr;
			curr = nextNode;
		}
		_size = other._size;
	}

	/**
	 * @brief Operador de asignación profunda para evitar fugas de memoria y
	 * punteros compartidos.
	 */
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

	bool empty() const { return _top == nullptr; }

	bool isEmpty() const { return empty(); }

	int size() const { return _size; }

	/**
	 * @brief Inserta un elemento en el tope de la pila.
	 * Operación O(1). El nuevo nodo pasa a ser la cabeza, apuntando al antiguo
	 * tope.
	 */
	void push(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		newNode->next = _top;
		_top = newNode;
		_size++;
	}

	/**
	 * @brief Remueve el elemento del tope.
	 * Operación O(1). Desvincula el nodo superior y libera su memoria física.
	 */
	void pop() {
		if (empty()) return;
		SimpleNode<T> *temp = _top;
		_top = _top->next;
		delete temp;
		_size--;
	}

	/**
	 * @brief Obtiene una referencia al elemento del tope.
	 */
	T &top() {
		if (empty()) throw std::runtime_error("Pila vacía");
		return _top->payload;
	}

	const T &top() const {
		if (empty()) throw std::runtime_error("Pila vacía");
		return _top->payload;
	}

	void clear() {
		while (!empty()) pop();
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
		DrxStack<T> temp = *this;
		int index = 1;
		int maxNumber = std::to_string(temp.size()).length();
		while (!temp.empty()) {
			if (index == 1) {
				std::cout << "   Top " << index << " : [\e[0;32m" << temp.top() << "\e[0m]\n";
			} else if (temp.size() == 1) {
				std::cout << "Bottom " << index << " : [\e[0;31m" << temp.top() << "\e[0m]\n";
			} else {
				std::cout << "       " << index << " : [\e[0;33m" << temp.top() << "\e[0m]\n";
			}
			temp.pop();
			index++;
		}
	}

  private:
	SimpleNode<T> *_top; // Puntero al tope de la pila.
	int _size;           // Tamaño actual de la pila.
};

template <typename T> inline void printStack(const DrxStack<T> &stack) {
	stack.print();
}
