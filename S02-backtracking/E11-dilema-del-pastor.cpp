#include <iostream> // Biblioteca para entrada y salida estándar

const short MAX_SIZE = 3; // Tamaño máximo del arreglo


// Función para verificar si un estado es válido
// Un estado no es válido si el lobo (W) y la oveja (S) están juntos sin el pastor
// O si la oveja (S) y el repollo (C) están juntos sin el pastor
bool isValidState(bool riverSide[MAX_SIZE]) {
	if (riverSide[0] && riverSide[1]) return false; // Lobo y oveja juntos
	if (riverSide[1] && riverSide[2]) return false; // Oveja y repollo juntos
	return true; // Estado válido
}

// Función para verificar si se alcanzó el estado objetivo
// El estado objetivo es cuando todos los elementos están en el lado derecho del río
bool isGoalState(bool riverSide[MAX_SIZE]) {
	for (int i = 0; i < 3; i++) {
		if (!riverSide[i]) return false; // Si algún elemento no está en el lado derecho
	}
	return true; // Todos los elementos están en el lado derecho
}

// Función para imprimir los elementos de un lado del río
void printSide(bool riverSide[MAX_SIZE]) {
	char items[] = { 'L', 'O', 'R' }; // L: Lobo, O: Oveja, R: Repollo

	// Imprimir los elementos presentes en el lado del río
	for (int i = 0; i < MAX_SIZE; i++) {
		if (riverSide[i]) std::cout << items[i] << " "; // Imprimir el elemento si está presente
		else std::cout << "  "; // Espacio en blanco si el elemento no está presente
	}
}

// Función para imprimir el estado actual del río
void printState(bool leftRiver[MAX_SIZE], bool rightRiver[MAX_SIZE], bool isFarmerLeft) {
	printf("\n\e[1;33m[ESTADO ACTUAL]\e[0m: ");

	// Imprimir el lado izquierdo del río
	if (isFarmerLeft) printf("(P) "); // P: Pastor
	else printf("    ");
	printSide(leftRiver);

	// Imprimir el río y el lado derecho
	printf(" ~~~~~   ");
	printSide(rightRiver);
	if (!isFarmerLeft) printf("(P)");
}

// Función recursiva para encontrar un camino válido para cruzar el río
bool findCrossingPath(bool leftRiver[MAX_SIZE], bool rightRiver[MAX_SIZE], bool isFarmerOnLeft = true, int lastMovedItem = -1) {
	printState(leftRiver, rightRiver, isFarmerOnLeft);

	// Verificar si se alcanzó el estado objetivo
	if (isGoalState(rightRiver)) {
		printf("\n\n\e[1;32m[RESULTADO]\e[0m ¡Todos los elementos han cruzado el río con éxito!\n\n");
		return true;
	}

	// Si el pastor está en el lado izquierdo
	if (isFarmerOnLeft) {
		for (int i = 0; i < MAX_SIZE; i++) {
			if (leftRiver[i] && i != lastMovedItem) { // Intentar mover un elemento
				leftRiver[i] = false; // Sacar el elemento del lado izquierdo

				if (isValidState(leftRiver)) { // Verificar si el estado es válido
					rightRiver[i] = true; // Mover el elemento al lado derecho
					if (findCrossingPath(leftRiver, rightRiver, !isFarmerOnLeft, i)) return true;
					rightRiver[i] = false; // Revertir el movimiento si no funciona
				}

				leftRiver[i] = true; // Revertir el movimiento
			}
		}
	}
	// Si el pastor está en el lado derecho
	else {
		if (isValidState(rightRiver)) // Verificar si el estado actual es válido
			if (findCrossingPath(leftRiver, rightRiver, !isFarmerOnLeft, -1)) return true;

		for (int i = 0; i < MAX_SIZE; i++) {
			if (rightRiver[i] && i != lastMovedItem) { // Intentar mover un elemento
				rightRiver[i] = false; // Sacar el elemento del lado derecho

				if (isValidState(rightRiver)) { // Verificar si el estado es válido
					leftRiver[i] = true; // Mover el elemento al lado izquierdo
					if (findCrossingPath(leftRiver, rightRiver, !isFarmerOnLeft, i)) return true;
					leftRiver[i] = false; // Revertir el movimiento si no funciona
				}

				rightRiver[i] = true; // Revertir el movimiento
			}
		}
	}

	return false; // No se encontró un camino válido
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
