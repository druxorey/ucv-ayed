#pragma once

/**
 * @brief Nodo simple para estructuras de datos enlazadas simples (como listas
 * simples, pilas y colas).
 *
 * Un nodo es la unidad fundamental de memoria en las estructuras de datos
 * dinámicas. Contiene el dato útil (payload) y un puntero de referencia
 * ('next') que almacena la dirección física de memoria del siguiente nodo en la
 * secuencia, permitiendo el enlace.
 *
 * @tparam T Tipo de dato genérico que almacenará el nodo.
 */
template <typename T> class SimpleNode {
  public:
	T payload; // Carga útil: el valor real almacenado por el nodo.
	SimpleNode<T>
		*next; // Enlace: puntero que apunta al siguiente nodo en memoria.

	/**
	 * @brief Constructor por defecto.
	 * Inicializa el payload con el constructor por defecto de su tipo (ej. 0
	 * para enteros) y asegura que el puntero apunte a 'nullptr' (tierra/final
	 * de lista) para evitar punteros huérfanos.
	 */
	SimpleNode() : payload(T()), next(nullptr) {}

	/**
	 * @brief Constructor paramétrico.
	 * @param val Valor con el que se inicializará el payload del nodo.
	 */
	SimpleNode(T val) : payload(val), next(nullptr) {}
};

/**
 * @brief Nodo doble para estructuras de datos doblemente enlazadas (como listas
 * dobles o bicolas).
 *
 * A diferencia del nodo simple, este contiene dos punteros de control: uno
 * hacia el siguiente nodo ('next') y otro hacia el anterior ('prev'). Esto
 * permite realizar recorridos en ambas direcciones (hacia adelante y hacia
 * atrás), facilitando inserciones y eliminaciones eficientes.
 *
 * @tparam T Tipo de dato genérico que almacenará el nodo.
 */
template <typename T> class DoubleNode {
  public:
	T payload;           // Carga útil: valor del nodo.
	DoubleNode<T> *next; // Enlace adelante: puntero al siguiente nodo.
	DoubleNode<T> *prev; // Enlace atrás: puntero al nodo anterior.

	/**
	 * @brief Constructor por defecto.
	 * Inicializa el dato por defecto y ambos punteros de navegación a
	 * 'nullptr'.
	 */
	DoubleNode() : payload(T()), next(nullptr), prev(nullptr) {}

	/**
	 * @brief Constructor paramétrico.
	 * @param val Valor a almacenar.
	 */
	DoubleNode(T val) : payload(val), next(nullptr), prev(nullptr) {}
};
