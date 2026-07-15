#include <iostream>

const short DOMINO_SET_SIZE = 28;

// Estructura que representa una ficha de dominó con sus valores izquierdo y derecho.
struct Domino {
    int left;
    int right;
};

// Imprime la cadena de dominó actual en pantalla.
void printChain(const int chain[], int left, int right) {
    for (int i = left; i <= right; i += 2) {
        std::cout << "[" << chain[i] << "|" << chain[i + 1] << "] ";
    }
    std::cout << "\n";
}

// Genera el conjunto estándar de 28 fichas de dominó (doble 6).
void generateDominoSet(Domino dominoSet[]) {
    int index = 0;
    for (int top = 0; top <= 6; top++) {
        for (int bottom = 0; bottom <= top; bottom++) {
            dominoSet[index].left = bottom;
            dominoSet[index].right = top;
            index++;
        }
    }
}

// Función recursiva para determinar si el juego está bloqueado y buscar caminos usando Backtracking.
// Concepto Teórico (Detección Dinámica de Hojas / Estados Terminales):
// El juego de dominó se "tranca" (bloquea) cuando ningún jugador puede colocar una ficha. En el árbol de 
// decisiones, esto representa un estado hoja o un callejón sin salida donde no es posible realizar transiciones válidas.
// Exploramos todas las formas de construir la cadena. Si en un estado dado ninguna ficha restante se puede conectar,
// identificamos que la cadena está bloqueada, imprimimos la configuración y retrocedemos (Backtracking).
void findLockedDomino(bool usedPieces[], const Domino dominoSet[], int chain[], int left, int right, int usedPiecesCount) {
    // Si ya colocamos las 28 fichas, el juego ha finalizado con éxito completo, no hay bloqueo posible.
    if (usedPiecesCount == DOMINO_SET_SIZE) return;

    // Asumimos inicialmente que el juego está bloqueado (estado terminal). 
    // Si logramos conectar al menos una ficha válida, cambiaremos esta bandera a false.
    bool isGameLocked = true;

    // Bucle de decisiones: Probar cada una de las 28 fichas disponibles
    for (int i = 0; i < DOMINO_SET_SIZE; i++) {
        if (!usedPieces[i]) {
            int leftEnd = chain[left];
            int rightEnd = chain[right];
            Domino currentPiece = dominoSet[i];

            // Condición de viabilidad (Poda / Filtrado):
            // La ficha actual solo puede usarse si alguno de sus valores coincide con los extremos actuales.
            bool canConnect = (currentPiece.left == leftEnd || currentPiece.right == leftEnd ||
                               currentPiece.left == rightEnd || currentPiece.right == rightEnd);
            if (!canConnect) continue; // Si no conecta, podamos esta rama del árbol

            // Registrar decisión: Marcamos la ficha como utilizada
            usedPieces[i] = true;

            // Exploración de transiciones en el extremo derecho:
            // Caso A: El lado izquierdo de la ficha coincide con el extremo derecho del tablero.
            if (currentPiece.left == rightEnd) {
                isGameLocked = false;
                chain[right + 1] = currentPiece.left;
                chain[right + 2] = currentPiece.right;
                findLockedDomino(usedPieces, dominoSet, chain, left, right + 2, usedPiecesCount + 1);
            } 
            // Caso B: El lado derecho de la ficha coincide con el extremo derecho del tablero (hay que rotarla).
            else if (currentPiece.right == rightEnd) {
                isGameLocked = false;
                chain[right + 1] = currentPiece.right;
                chain[right + 2] = currentPiece.left;
                findLockedDomino(usedPieces, dominoSet, chain, left, right + 2, usedPiecesCount + 1);
            }

            // Exploración de transiciones en el extremo izquierdo:
            // Caso C: El lado derecho de la ficha coincide con el extremo izquierdo del tablero.
            if (currentPiece.right == leftEnd) {
                isGameLocked = false;
                chain[left - 1] = currentPiece.right;
                chain[left - 2] = currentPiece.left;
                findLockedDomino(usedPieces, dominoSet, chain, left - 2, right, usedPiecesCount + 1);
            } 
            // Caso D: El lado izquierdo de la ficha coincide con el extremo izquierdo del tablero (hay que rotarla).
            else if (currentPiece.left == leftEnd) {
                isGameLocked = false;
                chain[left - 1] = currentPiece.left;
                chain[left - 2] = currentPiece.right;
                findLockedDomino(usedPieces, dominoSet, chain, left - 2, right, usedPiecesCount + 1);
            }

            // Deshacer decisión (Backtracking):
            // Desmarcamos la ficha como usada para permitir que otras configuraciones de la cadena
            // prueben esta misma ficha en posiciones o momentos distintos del recorrido.
            usedPieces[i] = false; 
        }
    }

    // Si tras revisar todas las fichas no utilizadas ninguna pudo acoplarse,
    // significa que hemos llegado a un estado de bloqueo ("juego trancado").
    if (isGameLocked) {
        std::cout << "\n\e[1;31m[RESULTADO]\e[0m Domino bloqueado: ";
        printChain(chain, left, right);
        std::cout << "\e[1;33m[INFO]\e[0m Total de piezas usadas: " << usedPiecesCount << "\n";
        return;
    }
}

int main() {
    std::cout << "\n\e[0;35m[========= E09-DOMINO-TRANCADO =========]\e[0m\n\n";

    Domino dominoSet[DOMINO_SET_SIZE];
    bool usedPieces[DOMINO_SET_SIZE] = {false};

    generateDominoSet(dominoSet);

    std::cout << "\e[1;34m[INFO]\e[0m Conjunto de fichas generadas:\n";
    for (int i = 0; i < DOMINO_SET_SIZE; i++) {
        std::cout << "[" << dominoSet[i].left << "|" << dominoSet[i].right << "] ";
        if ((i + 1) % 7 == 0) std::cout << "\n";
    }
    std::cout << "\n";

    // Iniciar con la última pieza (doble 6) en el centro de un arreglo grande
    int chain[120] = {0};
    int left = 50;
    int right = 51;
    chain[left] = dominoSet[DOMINO_SET_SIZE - 1].left;
    chain[right] = dominoSet[DOMINO_SET_SIZE - 1].right;
    usedPieces[DOMINO_SET_SIZE - 1] = true;

    findLockedDomino(usedPieces, dominoSet, chain, left, right, 1);

    return 0;
}
