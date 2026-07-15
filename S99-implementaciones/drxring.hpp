#pragma once

#include "drxlist.hpp"
#include <stdexcept>

// Estructura de Lista Circular (Ring).
// En una lista circular, no existe un final absoluto: el último elemento apunta
// de vuelta al primero. Para fines didácticos, esta clase hereda de DrxList<T>
// y encapsula un iterador ('it') que avanza indefinidamente de manera circular.
// T representa el tipo de dato de los elementos en el anillo.
template <typename T> class DrxRing : public DrxList<T> {
  public:
	// Constructor: Inicializa el anillo y coloca el cursor inicial en el fin (nullptr).
	DrxRing() : DrxList<T>() { it = this->begin(); }

	// Añade un nuevo elemento al anillo.
	// Si es el primer elemento de la lista circular, posiciona el cursor sobre él.
	void add(const T &value) {
		this->pushBack(value);
		if (this->size() == 1) {
			it = this->begin();
		}
	}

	// Remueve el elemento en la posición actual del cursor.
	// Avanza el cursor al siguiente elemento válido del anillo antes de
	// eliminar el actual.
	void remove() {
		if (!this->isEmpty()) {
			typename DrxList<T>::Iterator target = it;
			++it; // Avanzar el cursor antes de eliminar
			this->deleteNode(target);
			// Si el cursor llegó al final lógico, lo regresamos al principio
			if (it == this->end() && !this->isEmpty()) {
				it = this->begin();
			}
		}
	}

	// Avanza el cursor y retorna el elemento actual.
	// Simula el comportamiento circular: si se alcanza el final de la lista,
	// salta de vuelta al primer elemento automáticamente en O(1).
	T &next() {
		if (this->isEmpty()) {
			throw std::out_of_range("El anillo está vacío");
		}
		if (it == this->end()) {
			it = this->begin();
		}
		T &value = *it;
		++it;
		if (it == this->end()) {
			it = this->begin();
		}
		return value;
	}

  private:
	typename DrxList<T>::Iterator it; // Cursor para navegación circular.
};
