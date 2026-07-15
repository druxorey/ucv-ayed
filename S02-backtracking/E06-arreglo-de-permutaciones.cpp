#include <iostream>

// Función genérica local para imprimir un arreglo.
template <typename T>
void printArray(const T array[], int size, const char* message) {
    std::cout << message;
    for (int i = 0; i < size; i++) {
        std::cout << array[i];
        if (i != size - 1) std::cout << ",";
    }
    std::cout << "\e[1;34m]\e[0m\n";
}


// Función para intercambiar dos caracteres.
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}


// Función recursiva para generar todas las permutaciones posibles de un arreglo utilizando Backtracking.
// Concepto Teórico (Árbol de Espacio de Estados y Exploración en Profundidad - DFS):
// Las permutaciones se generan fijando un elemento en el índice 'currentIndex' y luego 
// llamando recursivamente para permutar el resto de las posiciones.
// Esta función recorre el árbol de decisiones explorando sistemáticamente todas las combinaciones posibles.
void generatePermutations(char array[], int size, int &validPermutationsCount, int currentIndex = 0) {
    // Caso base: Si el índice actual llega al tamaño del arreglo, significa que se ha tomado 
    // una decisión para cada posición (hoja del árbol de decisiones). 
    // Tenemos una permutación completa y válida, por lo que la imprimimos y retornamos.
    if (currentIndex == size) {
        validPermutationsCount++; // Registrar la permutación encontrada
        std::cout << " ∘ Permutación " << validPermutationsCount << ": \e[1;34m[\e[0m";
        printArray(array, size, "");
        return;
    }

    // Concepto Teórico (Bucle de Decisiones y Restauración del Estado):
    // El bucle 'for' representa las diferentes opciones disponibles para la posición 'currentIndex'.
    // Intercambiamos el carácter de la posición actual con el de la posición 'i' para explorar esa rama.
    for (int i = currentIndex; i < size; i++) {
        // 1. Tomar decisión: Colocamos el elemento en el índice 'i' en la posición actual de decisión 'currentIndex'.
        swap(array[currentIndex], array[i]);
        
        // 2. Explorar recursivamente: Resolvemos las permutaciones para las posiciones restantes (currentIndex + 1).
        generatePermutations(array, size, validPermutationsCount, currentIndex + 1);
        
        // 3. Deshacer decisión (Backtracking): Revertimos el intercambio. Restauramos el estado original del arreglo 
        //    antes de avanzar a la siguiente iteración. Esto garantiza que las siguientes decisiones en este nivel 
        //    partan del mismo estado de partida y no se vean alteradas por exploraciones previas.
        swap(array[currentIndex], array[i]);
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E06-ARREGLO-DE-PERMUTACIONES =========]\e[0m\n\n";

    int arraySize;
    int validPermutations = 0;

    std::cout << "Ingresa el tamaño del arreglo: ";
    if (!(std::cin >> arraySize) || arraySize <= 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m El tamaño debe ser mayor que cero y válido.\n\n";
        return 1;
    }

    char* letters = new char[arraySize];
    for (int i = 0; i < arraySize; i++) {
        letters[i] = 'a' + i;
    }

    std::cout << "\n";
    generatePermutations(letters, arraySize, validPermutations);

    printf("\n\e[1;32m[RESULTADO]\e[0m Total de permutaciones: %d.\n\n", validPermutations);

    delete[] letters;
    return 0;
}
