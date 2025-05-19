#include <iostream> // Biblioteca para entrada y salida estándar
#include <string>   // Biblioteca para manipulación de strings
#include "../S99-libraries/dxarray.hpp" // Biblioteca personalizada para manejo de arreglos

// Constante que define el tamaño del conjunto de fichas de dominó
const short DOMINO_SET_SIZE = 28;

// Función para generar el conjunto de fichas de dominó
// Cada ficha está representada como una cadena con dos números (ejemplo: "01", "12")
// En el que el primer número es el número superior y el segundo es el número inferior
void generateDominoSet(std::string dominoSet[]) {
	int index = 0; // Índice para llenar el arreglo

	// Generar todas las combinaciones posibles de fichas de dominó
	// El bucle externo recorre los números superiores de las fichas (de 0 a 6)
	for (int topNumber = 0; topNumber < DOMINO_SET_SIZE / 4; topNumber++) {
		// El bucle interno recorre los números inferiores de las fichas
		// Solo genera combinaciones donde el número inferior es menor o igual al superior
		for (int bottomNumber = 0; bottomNumber <= topNumber; bottomNumber++) {
			// Crear la ficha combinando los números superior e inferior como una cadena
			dominoSet[index] = std::to_string(bottomNumber) + std::to_string(topNumber);
			index++; // Incrementar el índice para almacenar la siguiente ficha
		}
	}
}

// Función para iniciar el juego seleccionando la última ficha del conjunto
// Marca la última ficha como usada y la retorna como la ficha inicial
std::string startGame(bool usedPieces[], std::string dominoSet[]) {
	usedPieces[DOMINO_SET_SIZE - 1] = true; // Marcar la última ficha como usada
	return dominoSet[DOMINO_SET_SIZE - 1]; // Retornar la ficha inicial
}

// Función recursiva para determinar si el juego está bloqueado
// Busca si hay fichas que puedan conectarse a los extremos de la cadena activa
void findLockedDomino(bool usedPieces[], std::string dominoSet[], std::string activeNumbers, short usedPiecesCounter = 0) {
	if (usedPiecesCounter == DOMINO_SET_SIZE) return; // Caso base: todas las fichas han sido usadas

	bool isGameLocked = true; // Flag para determinar si el juego está bloqueado

	// Se iteran sobre todas las fichas del conjunto
	for (int i = 0; i < DOMINO_SET_SIZE; i++) {
		char leftEnd = activeNumbers[0]; // Extremo izquierdo de la cadena activa
		char rightEnd = activeNumbers[activeNumbers.size() - 1]; // Extremo derecho de la cadena activa

		if (!usedPieces[i]) { // Verificar si la ficha actual no ha sido usada
			std::string currentPiece = dominoSet[i]; // Obtener la ficha actual
			std::string updatedActiveNumbers; // Cadena actualizada con la nueva ficha

			// Verificar si la ficha no puede conectarse a ninguno de los extremos
			if (currentPiece[0] != leftEnd && currentPiece[0] != rightEnd && currentPiece[1] != leftEnd && currentPiece[1] != rightEnd) {
				continue; // Saltar a la siguiente ficha
			}

			usedPieces[i] = true; // Marcar la ficha como usada
			usedPiecesCounter++; // Incrementar el contador de fichas usadas

			// Verificar y conectar la ficha al extremo derecho
			if (currentPiece[0] == rightEnd) {
				isGameLocked = false; // El juego no está bloqueado
				updatedActiveNumbers = activeNumbers + " " + currentPiece.substr(0, 1) + currentPiece.substr(1, 1);
				findLockedDomino(usedPieces, dominoSet, updatedActiveNumbers, usedPiecesCounter);
				updatedActiveNumbers = activeNumbers; // Restaurar la cadena activa
			}
			if (currentPiece[1] == rightEnd) {
				isGameLocked = false;
				updatedActiveNumbers = activeNumbers + " " + currentPiece.substr(1, 1) + currentPiece.substr(0, 1);
				findLockedDomino(usedPieces, dominoSet, updatedActiveNumbers, usedPiecesCounter);
				updatedActiveNumbers = activeNumbers;
			}

			// Verificar y conectar la ficha al extremo izquierdo
			if (currentPiece[0] == leftEnd) {
				isGameLocked = false;
				updatedActiveNumbers = currentPiece.substr(1, 1) + currentPiece.substr(0, 1) + " " + activeNumbers;
				findLockedDomino(usedPieces, dominoSet, updatedActiveNumbers, usedPiecesCounter);
				updatedActiveNumbers = activeNumbers;
			}
			if (currentPiece[1] == leftEnd) {
				isGameLocked = false;
				updatedActiveNumbers = currentPiece.substr(0, 1) + currentPiece.substr(1, 1) + " " + activeNumbers;
				findLockedDomino(usedPieces, dominoSet, updatedActiveNumbers, usedPiecesCounter);
				updatedActiveNumbers = activeNumbers;
			}

			usedPiecesCounter--; // Restaurar el contador de fichas usadas
			usedPieces[i] = false; // Marcar la ficha como no usada
		}
	}

	if (isGameLocked) {
		// Mensaje indicando que el juego está bloqueado
		printf("\n\e[1;31m[RESULTADO]\e[0m Domino bloqueado: %s\n", activeNumbers.c_str());
		printf("\e[1;33m[INFO]\e[0m Total de piezas usadas: %d\n", usedPiecesCounter);
		return;
	}
}


int main() {
	std::cout << "\n\e[1;35m[========= E09-DOMINO-TRANCADO =========]\e[0m\n\n";

	// Declaración del conjunto de fichas de dominó
	std::string dominoSet[DOMINO_SET_SIZE];
	bool usedPieces[DOMINO_SET_SIZE] = {0}; // Arreglo para rastrear las piezas usadas

	// Generar el conjunto de fichas de dominó
	generateDominoSet(dominoSet);

	// Mostrar el conjunto generado
	printf("\n\e[1;34m[INFO]\e[0m Conjunto de fichas generadas: ");
	printArray(dominoSet, DOMINO_SET_SIZE, "");

	// Iniciar el juego seleccionando la última ficha
	std::string activeNumbers = startGame(usedPieces, dominoSet);

	// Buscar si el juego está bloqueado
	findLockedDomino(usedPieces, dominoSet, activeNumbers);

	return 0;
}
