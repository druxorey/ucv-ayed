#pragma once

#include "drxlist.hpp"

/**
 * @brief Nodo de Árbol Binario.
 *
 * En un árbol binario, cada nodo tiene como máximo dos hijos: un subárbol
 * izquierdo ('left') y un subárbol derecho ('right'). Esta estructura
 * jerárquica no lineal es la base de algoritmos de búsqueda y partición
 * sumamente eficientes.
 *
 * @tparam T Tipo de dato a almacenar.
 */
template <typename T> class DrxArbinNode {
  public:
	T value;
	DrxArbinNode<T> *left;  // Puntero al subárbol/hijo izquierdo.
	DrxArbinNode<T> *right; // Puntero al subárbol/hijo derecho.

	DrxArbinNode(T val) : value(val), left(nullptr), right(nullptr) {}

	/**
	 * @brief Destructor recursivo.
	 * Al eliminar este nodo, liberará automáticamente de forma jerárquica
	 * todos los subárboles descendientes, evitando fugas de memoria.
	 */
	~DrxArbinNode() {
		if (left != nullptr) delete left;
		if (right != nullptr) delete right;
	}

	bool isLeaf() const { return left == nullptr && right == nullptr; }
};

/**
 * @brief Estructura de Árbol Binario.
 * Encapsula la raíz del árbol binario y provee métodos de acceso básicos.
 */
template <typename T> class DrxArbin {
  public:
	DrxArbinNode<T> *root; // Puntero al nodo raíz principal.

	DrxArbin() : root(nullptr) {}
	DrxArbin(DrxArbinNode<T> *r) : root(r) {}

	~DrxArbin() {
		if (root != nullptr) {
			delete root;
			root = nullptr;
		}
	}

	bool isEmpty() const { return root == nullptr; }
};

/**
 * @brief Nodo de Árbol General.
 *
 * A diferencia de los árboles binarios, en un árbol general un nodo puede tener
 * una cantidad arbitraria de hijos. Para modelar esto de forma didáctica sin
 * STL, se utiliza una lista enlazada de punteros hacia sus nodos hijos
 * (`DrxList<DrxTreeNode<T>*>`).
 *
 * @tparam T Tipo de dato a almacenar.
 */
template <typename T> class DrxTreeNode {
  public:
	T value;
	DrxList<DrxTreeNode<T> *> children; // Lista dinámica de punteros a hijos.

	DrxTreeNode(T val) : value(val) {}

	/**
	 * @brief Destructor recursivo para árbol general.
	 * Recorre la lista de hijos y destruye recursivamente cada subárbol.
	 */
	~DrxTreeNode() {
		typename DrxList<DrxTreeNode<T> *>::iterator it = children.first();
		while (it != children.end()) {
			DrxTreeNode<T> *child = *children.get(it);
			if (child != nullptr) delete child;
			children.next(it);
		}
		children.clear();
	}

	bool isLeaf() const { return children.isEmpty(); }

	int childrenCount() const { return children.size(); }
};

/**
 * @brief Estructura de Árbol General.
 */
template <typename T> class DrxTree {
  public:
	DrxTreeNode<T> *root; // Puntero al nodo raíz.

	DrxTree(T rootValue) { root = new DrxTreeNode<T>(rootValue); }

	~DrxTree() {
		if (root != nullptr) {
			delete root;
			root = nullptr;
		}
	}

	/**
	 * @brief Añade un nuevo hijo a un nodo padre determinado.
	 */
	void addChildren(T value, DrxTreeNode<T> *parent) {
		if (parent == nullptr) return;
		DrxTreeNode<T> *newChild = new DrxTreeNode<T>(value);
		parent->children.push_back(newChild);
	}
};
