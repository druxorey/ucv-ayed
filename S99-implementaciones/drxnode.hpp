#pragma once

// Nodo simple para estructuras de datos enlazadas simples (como listas simples, pilas y colas).
// Un nodo es la unidad fundamental de memoria en las estructuras de datos dinámicas.
// Contiene el dato útil (payload) y un puntero de referencia ('next') que almacena la
// dirección física de memoria del siguiente nodo en la secuencia, permitiendo el enlace.
// T representa el tipo de dato genérico que almacenará el nodo.
template <typename T> class SimpleNode {
  public:
	T payload; // Carga útil: el valor real almacenado por el nodo.
	SimpleNode<T> *next; // Enlace: puntero que apunta al siguiente nodo en memoria.

	// Constructor por defecto.
	// Inicializa el payload con el constructor por defecto de su tipo (ej. 0 para enteros)
	// y asegura que el puntero apunte a 'nullptr' (tierra/final de lista) para evitar punteros huérfanos.
	SimpleNode() : payload(T()), next(nullptr) {}

	// Constructor paramétrico.
	// Recibe un valor 'val' para inicializar la carga útil (payload) del nodo
	// y por defecto establece el puntero de enlace al siguiente como nulo.
	SimpleNode(T val) : payload(val), next(nullptr) {}
};

// Nodo doble para estructuras de datos doblemente enlazadas (como listas dobles o bicolas).
// A diferencia del nodo simple, este contiene dos punteros de control: uno hacia el siguiente
// nodo ('next') y otro hacia el anterior ('prev'). Esto permite realizar recorridos en ambas
// direcciones (hacia adelante y hacia atrás), facilitando inserciones y eliminaciones eficientes.
// T representa el tipo de dato genérico que almacenará el nodo.
template <typename T> class DoubleNode {
  public:
	T payload;           // Carga útil: valor del nodo.
	DoubleNode<T> *next; // Enlace adelante: puntero al siguiente nodo.
	DoubleNode<T> *prev; // Enlace atrás: puntero al nodo anterior.

	// Constructor por defecto.
	// Inicializa el dato por defecto y ambos punteros de navegación a 'nullptr'
	// para que no apunten a basura de memoria.
	DoubleNode() : payload(T()), next(nullptr), prev(nullptr) {}

	// Constructor paramétrico.
	// Inicializa la carga útil con el valor recibido y establece ambos punteros como nulos.
	DoubleNode(T val) : payload(val), next(nullptr), prev(nullptr) {}
};

