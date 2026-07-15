#pragma once

#include "drxnode.hpp"
#include <iostream>

// Estructura de Lista Simplemente Enlazada (DrxSimplyList).
// Es una colección lineal de elementos en la que cada uno apunta al siguiente.
// La ventaja principal con respecto a un arreglo es el tamaño dinámico e
// inserción/eliminación eficientes en posiciones conocidas de O(1), mientras
// que la desventaja es que no cuenta con acceso aleatorio directo (debe
// recorrerse secuencialmente desde el inicio).
// T representa el tipo de dato de los elementos de la lista.
template <typename T> class DrxSimplyList {
  public:
	// Iterador personalizado para recorrer la lista de forma segura.
	// Abstrae la manipulación directa de punteros físicos mediante operadores
	// sobrecargados.
	class Iterator {
	  public:
		Iterator(SimpleNode<T> *ptr = nullptr) : node(ptr) {}

		// Desreferenciación: obtiene el dato del nodo apuntado
		T &operator*() const { return node->payload; }
		T *operator->() const { return &(node->payload); }

		// Operador de incremento pre-fijado: avanza al siguiente nodo
		Iterator &operator++() {
			if (node != nullptr)
				node = node->next;
			return *this;
		}

		// Operador de incremento post-fijado: avanza al siguiente nodo
		// retornando el estado anterior
		Iterator operator++(int) {
			Iterator temp = *this;
			if (node != nullptr)
				node = node->next;
			return temp;
		}

		bool operator==(const Iterator &other) const {
			return node == other.node;
		}
		bool operator!=(const Iterator &other) const {
			return node != other.node;
		}

	  private:
		SimpleNode<T> *node;
		friend class DrxSimplyList<T>;
	};

	// Constructor por defecto: Inicializa una lista vacía.
	DrxSimplyList() : _first(nullptr), _last(nullptr), _size(0) {}

	// Destructor: Se encarga de liberar secuencialmente toda la memoria
	// reservada dinámicamente llamando a clear().
	~DrxSimplyList() { clear(); }

	// Retorna un iterador apuntando al primer elemento de la lista.
	Iterator begin() const { return Iterator(_first); }

	// Retorna un iterador apuntando a nullptr, representando el final lógico de la secuencia.
	Iterator end() const { return Iterator(nullptr); }

	// Verifica si la lista está vacía.
	bool isEmpty() const { return _first == nullptr; }

	// Obtiene el tamaño actual de la lista.
	int size() const { return _size; }

	// Inserta un nuevo elemento al final de la lista.
	// Modifica el enlace del último nodo existente para que apunte al nuevo nodo.
	void pushBack(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		if (isEmpty()) {
			_first = _last = newNode;
		} else {
			_last->next = newNode;
			_last = newNode;
		}
		_size++;
	}

	// Inserta un nuevo elemento al principio de la lista.
	// El nuevo nodo apunta al que anteriormente era el primer nodo de la lista.
	void pushFront(const T &val) {
		SimpleNode<T> *newNode = new SimpleNode<T>(val);
		if (isEmpty()) {
			_first = _last = newNode;
		} else {
			newNode->next = _first;
			_first = newNode;
		}
		_size++;
	}

	// Elimina un elemento en una posición lógica apuntada por el iterador.
	// Realiza un puente de enlace: el nodo anterior al objetivo se enlaza al siguiente
	// del objetivo, aislando el nodo a eliminar para luego liberar su memoria mediante 'delete'.
	void erase(Iterator pos) {
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

	// Limpia toda la lista eliminando secuencialmente cada uno de sus nodos.
	void clear() {
		while (!isEmpty()) erase(begin());
	}

	// Imprime el contenido de la lista en consola con fines educativos.
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
	SimpleNode<T> *_last;  // Puntero de control hacia el último nodo (para inserciones O(1) al final).
	int _size;             // Contador interno del número de elementos.
};


// Estructura de Lista Doblemente Enlazada (DrxList).
// Cada nodo tiene dos punteros, permitiendo recorrer la lista bidireccionalmente.
// La inserción y eliminación son más cómodas ya que cualquier nodo conoce tanto a su
// antecesor como a su sucesor, evitando recorridos previos costosos para enlazar.
// T representa el tipo de dato de los elementos de la lista.
template <typename T> class DrxList {
  public:
	// Iterador bidireccional personalizado para DrxList.
	class Iterator {
	  public:
		Iterator(DoubleNode<T> *ptr = nullptr) : node(ptr) {}

		T &operator*() const { return node->payload; }
		T *operator->() const { return &(node->payload); }

		Iterator &operator++() {
			if (node != nullptr) node = node->next;
			return *this;
		}

		Iterator operator++(int) {
			Iterator temp = *this;
			if (node != nullptr) node = node->next;
			return temp;
		}

		Iterator &operator--() {
			if (node != nullptr) node = node->prev;
			return *this;
		}

		Iterator operator--(int) {
			Iterator temp = *this;
			if (node != nullptr) node = node->prev;
			return temp;
		}

		bool operator==(const Iterator &other) const {
			return node == other.node;
		}
		bool operator!=(const Iterator &other) const {
			return node != other.node;
		}

	  private:
		DoubleNode<T> *node;
		friend class DrxList<T>;
	};

	DrxList() : _first(nullptr), _last(nullptr), _size(0) {}

	~DrxList() { clear(); }

	// Retorna iterador al primer elemento.
	Iterator first() const { return Iterator(_first); }

	// Retorna iterador al último elemento.
	Iterator last() const { return Iterator(_last); }

	Iterator begin() const { return Iterator(_first); }

	Iterator end() const { return Iterator(nullptr); }

	// Obtiene la dirección del valor del nodo apuntado.
	T *get(Iterator i) const {
		if (i.node == nullptr) return nullptr;
		return &(i.node->payload);
	}

	// Avanza por referencia un iterador al siguiente nodo.
	void next(Iterator &i) const {
		if (i.node != nullptr) i.node = i.node->next;
	}

	// Retrocede por referencia un iterador al nodo anterior.
	void prev(Iterator &i) const {
		if (i.node != nullptr) i.node = i.node->prev;
	}

	// Verifica si la lista está vacía.
	bool isEmpty() const { return _first == nullptr; }

	// Obtiene el tamaño actual de la lista.
	int size() const { return _size; }

	// Inserta un elemento en relación con la posición dada.
	// Reconfigura de forma segura hasta 4 punteros de enlace (los del nuevo
	// nodo, el anterior y el posterior).
	// pos: Iterador de referencia.
	// val: Valor a insertar.
	// before: Si es verdadero, inserta antes de 'pos', de lo contrario, después.
	Iterator insert(Iterator pos, const T &val, bool before = true) {
		DoubleNode<T> *newNode = new DoubleNode<T>(val);
		_size++;

		if (isEmpty()) {
			_first = _last = newNode;
			return Iterator(newNode);
		}

		DoubleNode<T> *current = pos.node;
		if (current == nullptr) { // Si el iterador es nulo, insertamos al final
			newNode->prev = _last;
			_last->next = newNode;
			_last = newNode;
			return Iterator(newNode);
		}

		if (before) {
			newNode->next = current;
			newNode->prev = current->prev;
			if (current->prev != nullptr) {
				current->prev->next = newNode;
			} else {
				_first = newNode; // Si insertamos al principio, actualizamos _first
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

		return Iterator(newNode);
	}

	// Agrega un elemento al final de la lista.
	void pushBack(const T &val) { insert(end(), val, true); }

	// Agrega un elemento al principio de la lista.
	void pushFront(const T &val) { insert(begin(), val, true); }

	// Elimina el nodo en la posición dada.
	// Ajusta los punteros de los nodos vecinos para saltar el nodo actual,
	// previniendo punteros colgantes antes de liberar la memoria de forma segura.
	void deleteNode(Iterator pos) {
		DoubleNode<T> *current = pos.node;
		if (current == nullptr) return;

		_size--;

		if (current == _first) _first = current->next;
		if (current == _last) _last = current->prev;
		if (current->prev != nullptr) current->prev->next = current->next;
		if (current->next != nullptr) current->next->prev = current->prev;

		delete current;
	}

	// Vacia la lista eliminando todos los nodos de forma secuencial.
	void clear() {
		while (!isEmpty()) {
			deleteNode(first());
		}
	}

	// Muestra la lista en la salida estándar para depuración.
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
	DoubleNode<T> *_first; // Puntero al primer nodo
	DoubleNode<T> *_last;  // Puntero al último nodo
	int _size;             // Tamaño total
};
