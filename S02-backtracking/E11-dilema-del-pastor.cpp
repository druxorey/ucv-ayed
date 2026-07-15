#include <iostream> // Biblioteca para entrada y salida estándar

const short MAX_SIZE = 3; // Tamaño máximo del arreglo


// Función para verificar si un estado de una orilla es válido.
// Concepto Teórico (Restricciones del Espacio de Estados):
// La oveja y el lobo no pueden quedar solos en la misma orilla (el lobo se comería a la oveja).
// La oveja y el repollo no pueden quedar solos en la misma orilla (la oveja se comería al repollo).
// Nota: Dado que esta función se evalúa sobre una orilla en la que el pastor *no* estará 
// (se ha retirado cruzando el río), si ambos elementos conflictivos están presentes en esa orilla,
// el estado se considera inválido y se retorna false (poda del camino).
bool isValidState(bool riverSide[MAX_SIZE]) {
	if (riverSide[0] && riverSide[1]) return false; // Lobo (0) y oveja (1) se quedan solos
	if (riverSide[1] && riverSide[2]) return false; // Oveja (1) y repollo (2) se quedan solos
	return true; // Estado seguro
}

// Función para verificar si se alcanzó el estado objetivo.
// El juego termina exitosamente cuando Lobo, Oveja y Repollo están en la orilla derecha.
bool isGoalState(bool riverSide[MAX_SIZE]) {
	for (int i = 0; i < 3; i++) {
		if (!riverSide[i]) return false; 
	}
	return true;
}

// Función recursiva para encontrar un camino válido para cruzar el río mediante Backtracking.
// Concepto Teórico (Búsqueda en Grafos de Transición de Estados):
// El dilema del pastor se modela como un grafo donde cada nodo es un estado seguro de distribución
// de los elementos, y las aristas son cruces del pastor en bote (solo o con un elemento).
// Para evitar ciclos infinitos (ej. llevar y traer al lobo de forma indefinida), usamos 'lastMovedItem'.
bool findCrossingPath(bool leftRiver[MAX_SIZE], bool rightRiver[MAX_SIZE], bool isFarmerOnLeft = true, int lastMovedItem = -1) {
	printState(leftRiver, rightRiver, isFarmerOnLeft);

	// Caso base: Si todos los elementos han cruzado a la orilla derecha, el algoritmo finaliza con éxito.
	if (isGoalState(rightRiver)) {
		printf("\n\n\e[1;32m[RESULTADO]\e[0m ¡Todos los elementos han cruzado el río con éxito!\n\n");
		return true;
	}

	// Escenario A: El pastor está en el lado izquierdo y debe cruzar al derecho.
	// El pastor puede cruzar solo (esta opción no se evalúa pues siempre es inseguro dejar solos al lobo-oveja o oveja-repollo)
	// o intentar llevar a uno de los objetos permitidos (Lobo, Oveja o Repollo).
	if (isFarmerOnLeft) {
		for (int i = 0; i < MAX_SIZE; i++) {
			// Intentamos mover el elemento 'i' si está en este lado y no fue el que acabamos de mover
			if (leftRiver[i] && i != lastMovedItem) {
				// 1. Tomar decisión temporal: Sacar elemento 'i' del lado izquierdo
				leftRiver[i] = false; 

				// Verificamos si los elementos restantes en la izquierda se quedan en un estado seguro sin el pastor
				if (isValidState(leftRiver)) { 
					// Confirmar decisión: Colocar el elemento 'i' en el lado derecho
					rightRiver[i] = true; 
					
					// 2. Exploración recursiva: El pastor cruza al lado derecho
					if (findCrossingPath(leftRiver, rightRiver, !isFarmerOnLeft, i)) return true;
					
					// 3. Deshacer decisión (Backtracking): Si la exploración falló, revertir lado derecho
					rightRiver[i] = false; 
				}

				// Revertir lado izquierdo para probar con otro elemento en el bucle
				leftRiver[i] = true; 
			}
		}
	}
	// Escenario B: El pastor está en el lado derecho y debe retornar al izquierdo.
	else {
		// Opción 1: El pastor regresa solo. 
		// Esto es válido si el estado en la orilla derecha (sin el pastor) es seguro.
		if (isValidState(rightRiver)) {
			if (findCrossingPath(leftRiver, rightRiver, !isFarmerOnLeft, -1)) return true;
		}

		// Opción 2: El pastor regresa con un elemento 'i' del lado derecho hacia el izquierdo.
		for (int i = 0; i < MAX_SIZE; i++) {
			if (rightRiver[i] && i != lastMovedItem) {
				// 1. Tomar decisión temporal: Sacar el elemento 'i' del lado derecho
				rightRiver[i] = false; 

				// Verificamos si los elementos restantes en la derecha quedan en un estado seguro sin el pastor
				if (isValidState(rightRiver)) { 
					// Confirmar decisión: Colocar el elemento 'i' en la izquierda
					leftRiver[i] = true; 
					
					// 2. Exploración recursiva: El pastor regresa al lado izquierdo con el elemento
					if (findCrossingPath(leftRiver, rightRiver, !isFarmerOnLeft, i)) return true;
					
					// 3. Deshacer decisión (Backtracking): Revertir estado en la izquierda
					leftRiver[i] = false; 
				}

				// Revertir lado derecho para probar con otro elemento en el bucle
				rightRiver[i] = true; 
			}
		}
	}

	return false; // Retorna false si desde este estado no hay ningún movimiento que conduzca a la meta
}


int main() {
	std::cout << "\n\e[0;35m[========= E11-DILEMA-DEL-PASTOR =========]\e[0m\n";

	// Definición de los elementos del dilema
	// Pastor (P), Lobo (W), Oveja (S), Repollo (C)

	// Inicializar los estados del río
	bool leftRiver[] = {1, 1, 1}; // Todos los elementos están inicialmente en el lado izquierdo
	bool rightRiver[] = {0, 0, 0}; // Ningún elemento está en el lado derecho

	// Intentar encontrar un camino para cruzar el río
	if (!findCrossingPath(leftRiver, rightRiver, true)) {
		printf("\n\e[1;31m[ERROR]\e[0m No se encontró una solución para cruzar el río.\n");
	}

	return 0;
}
