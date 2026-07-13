#pragma once

#include "drxnode.hpp"
#include <iostream>

/**
 * @brief Estructura de Lista Simplemente Enlazada.
 *
 * Es una colección lineal de elementos en la que cada uno apunta al siguiente.
 * La ventaja principal con respecto a un arreglo es el tamaño dinámico e
 * inserción/eliminación eficientes en posiciones conocidas de O(1), mientras
 * que la desventaja es que no cuenta con acceso aleatorio directo (debe
 * recorrerse secuencialmente desde el inicio).
 *
 * @tparam T Tipo de dato de los elementos de la lista.
 */
template <typename T> class DrxSimplyList {
  public:
	/**
	 * @brief Iterador personalizado para recorrer la lista de forma segura.
	 * Abstrae la manipulación directa de punteros físicos mediante operadores
	 * sobrecargados.
	 */
	class iterator {
	  public:
		iterator(SimpleNode<T> *ptr = nullptr) : node(ptr) {}

		// Desreferenciación: obtiene el dato del nodo apuntado
		T &operator*() const { return node->payload; }
		T *operator->() const { return &(node->payload); }

		// Operador de incremento pre-fijado: avanza al siguiente nodo
		iterator &operator++() {
			if (node != nullptr)
				node = node->next;
			return *this;
		}

		// Operador de incremento post-fijado: avanza al siguiente nodo
		// retornando el estado anterior
		iterator operator++(int) {
			iterator temp = *this;
			if (node != nullptr)
				node = node->next;
			return temp;
		}

		bool operator==(const iterator &other) const {
			return node == other.node;
		}
		bool operator!=(const iterator &other) const {
			return node != other.node;
		}

	  private:
		SimpleNode<T> *node;
		friend class DrxSimplyList<T>;
	};

	/**
	 * @brief Constructor por defecto: Inicializa una lista vacía.
	 */
	DrxSimplyList() : _first(nullptr), _last(nullptr), _size(0) {}

	/**
	 * @brief Destructor: Se encarga de liberar secuencialmente toda la memoria
	 * reservada dinámicamente.
	 */
	~DrxSimplyList() { clear(); }

	// Retorna un iterador apuntando al primer elemento de la lista.
	iterator begin() const { return iterator(_first); }
	// Retorna un iterador apuntando a nullptr, representando el final lógico de
	// la secuencia.
	iterator end() const { return iterator(nullptr); }

	bool isEmpty() const { return _first == nullptr; }
	int size() const { return _size; }

	/**
	 * @brief Inserta un nuevo elemento al final de la lista.
	 * Modifica el enlace del último nodo existente para que apunte al nuevo
	 * nodo.
	 */
	void push_back(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		if (isEmpty()) {
			_first = _last = newNode;
		} else {
			_last->next = newNode;
			_last = newNode;
		}
		_size++;
	}

	/**
	 * @brief Inserta un nuevo elemento al principio de la lista.
	 * El nuevo nodo apunta al que anteriormente era el primer nodo de la lista.
	 */
	void push_front(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		if (isEmpty()) {
			_first = _last = newNode;
		} else {
			newNode->next = _first;
			_first = newNode;
		}
		_size++;
	}

	/**
	 * @brief Elimina un elemento en una posición lógica apuntada por el
	 * iterador. Realiza un puente de enlace: el nodo anterior al objetivo se
	 * enlaza al siguiente del objetivo, aislando el nodo a eliminar para luego
	 * liberar su memoria mediante 'delete'.
	 */
	void erase(iterator pos) {
		if (pos.node == nullptr || isEmpty())
			return;

		SimpleNode<T> *target = pos.node;
		if (target == _first) {
			_first = _first->next;
			if (_first == nullptr)
				_last = nullptr;
			delete target;
		} else {
			SimpleNode<T> *prev = _first;
			while (prev != nullptr && prev->next != target) {
				prev = prev->next;
			}
			if (prev != nullptr) {
				prev->next = target->next;
				if (target == _last) _last = prev;
				delete target;
			}
		}
		_size--;
	}

	/**
	 * @brief Limpia toda la lista eliminando secuencialmente cada uno de sus
	 * nodos.
	 */
	void clear() {
		while (!isEmpty()) erase(begin());
	}

	/**
	 * @brief Imprime el contenido de la lista en consola con fines educativos.
	 */
	void print() const {
		SimpleNode<T> *curr = _first;
		int index = 1;
		while (curr != nullptr) {
			std::cout << "Nodo " << index << ": [" << curr->payload << "]\n";
			curr = curr->next;
			index++;
		}
	}

  private:
	SimpleNode<T> *_first; // Puntero de control hacia el primer nodo.
	SimpleNode<T> *_last;  // Puntero de control hacia el último nodo (para
						   // inserciones O(1) al final).
	int _size;             // Contador interno del número de elementos.
};

/**
 * @brief Estructura de Lista Doblemente Enlazada.
 *
 * Cada nodo tiene dos punteros, permitiendo recorrer la lista
 * bidireccionalmente. La inserción y eliminación son más cómodas ya que
 * cualquier nodo conoce tanto a su antecesor como a su sucesor, evitando
 * recorridos previos costosos para enlazar.
 *
 * @tparam T Tipo de dato de los elementos de la lista.
 */
template <typename T> class DrxList {
  public:
	/**
	 * @brief Iterador bidireccional personalizado para DrxList.
	 */
	class iterator {
	  public:
		iterator(DoubleNode<T> *ptr = nullptr) : node(ptr) {}

		T &operator*() const { return node->payload; }
		T *operator->() const { return &(node->payload); }

		iterator &operator++() {
			if (node != nullptr) node = node->next;
			return *this;
		}

		iterator operator++(int) {
			iterator temp = *this;
			if (node != nullptr) node = node->next;
			return temp;
		}

		iterator &operator--() {
			if (node != nullptr) node = node->prev;
			return *this;
		}

		iterator operator--(int) {
			iterator temp = *this;
			if (node != nullptr) node = node->prev;
			return temp;
		}

		bool operator==(const iterator &other) const {
			return node == other.node;
		}
		bool operator!=(const iterator &other) const {
			return node != other.node;
		}

	  private:
		DoubleNode<T> *node;
		friend class DrxList<T>;
	};

	DrxList() : _first(nullptr), _last(nullptr), _size(0) {}

	~DrxList() { clear(); }

	// Retorna iterador al primer elemento.
	iterator first() const { return iterator(_first); }
	// Retorna iterador al último elemento.
	iterator last() const { return iterator(_last); }
	iterator begin() const { return iterator(_first); }
	iterator end() const { return iterator(nullptr); }

	/**
	 * @brief Obtiene la dirección del valor del nodo apuntado.
	 */
	T *get(iterator i) const {
		if (i.node == nullptr) return nullptr;
		return &(i.node->payload);
	}

	/**
	 * @brief Avanza por referencia un iterador al siguiente nodo.
	 */
	void next(iterator &i) const {
		if (i.node != nullptr) i.node = i.node->next;
	}

	/**
	 * @brief Retrocede por referencia un iterador al nodo anterior.
	 */
	void prev(iterator &i) const {
		if (i.node != nullptr) i.node = i.node->prev;
	}

	bool isEmpty() const { return _first == nullptr; }
	int size() const { return _size; }

	/**
	 * @brief Inserta un elemento en relación con la posición dada.
	 * Reconfigura de forma segura hasta 4 punteros de enlace (los del nuevo
	 * nodo, el anterior y el posterior).
	 *
	 * @param pos Iterador de referencia.
	 * @param val Valor a insertar.
	 * @param before Si es verdadero, inserta antes de 'pos', de lo contrario,
	 * después.
	 */
	iterator insert(iterator pos, const T &val, bool before = true) {
		DoubleNode<T> *newNode = new DoubleNode<T>(val);
		_size++;

		if (isEmpty()) {
			_first = _last = newNode;
			return iterator(newNode);
		}

		DoubleNode<T> *current = pos.node;
		if (current == nullptr) { // Si el iterador es nulo, insertamos al final
			newNode->prev = _last;
			_last->next = newNode;
			_last = newNode;
			return iterator(newNode);
		}

		if (before) {
			newNode->next = current;
			newNode->prev = current->prev;
			if (current->prev != nullptr) {
				current->prev->next = newNode;
			} else {
				_first =
					newNode; // Si insertamos al principio, actualizamos _first
			}
			current->prev = newNode;
		} else {
			newNode->next = current->next;
			newNode->prev = current;
			if (current->next != nullptr) {
				current->next->prev = newNode;
			} else {
				_last = newNode; // Si insertamos al final, actualizamos _last
			}
			current->next = newNode;
		}

		return iterator(newNode);
	}

	void push_back(const T &val) { insert(end(), val, true); }

	void push_front(const T &val) { insert(begin(), val, true); }

	/**
	 * @brief Elimina el nodo en la posición dada.
	 * Ajusta los punteros de los nodos vecinos para saltar el nodo actual,
	 * previniendo punteros colgantes antes de liberar la memoria de forma
	 * segura.
	 */
	void deleteNode(iterator pos) {
		DoubleNode<T> *current = pos.node;
		if (current == nullptr) return;

		_size--;

		if (current == _first) _first = current->next;
		if (current == _last) _last = current->prev;
		if (current->prev != nullptr) current->prev->next = current->next;
		if (current->next != nullptr) current->next->prev = current->prev;

		delete current;
	}

	void clear() {
		while (!isEmpty()) {
			deleteNode(first());
		}
	}

	void print() const {
		DoubleNode<T> *curr = _first;
		int index = 1;
		while (curr != nullptr) {
			std::cout << "Nodo " << index << ": [" << curr->payload << "]\n";
			curr = curr->next;
			index++;
		}
	}

  private:
	DoubleNode<T> *_first;
	DoubleNode<T> *_last;
	int _size;
};
