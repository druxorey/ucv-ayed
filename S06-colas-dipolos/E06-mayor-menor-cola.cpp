#include <iostream>
#include "../S99-implementaciones/drxqueue.hpp"

// Busca el mayor y menor elemento en la cola preservando su orden e integridad.
// Concepto Teórico (Rotación de Colas para Preservación In-Place):
// Las colas solo exponen su frente (front). Para examinar todos sus elementos sin destruir la estructura
// y sin usar memoria auxiliar adicional (O(1) espacio), recurrimos a la técnica de Rotación:
// - Desencolamos (pop) el elemento del frente, lo procesamos.
// - Inmediatamente lo re-encolamos (push) al final.
// Al repetir este ciclo exactamente N veces (siendo N el tamaño de la cola), todos los elementos
// son evaluados y regresan a sus posiciones originales relativas.
void showMaxMin(DrxQueue<int>& Q) {
    if (Q.isEmpty()) {
        std::cout << "\nCola vacía.\n";
        return;
    }

    int n = Q.size();
    int minVal = Q.front(); // Inicializar el mínimo con el primer elemento
    int maxVal = Q.front(); // Inicializar el máximo con el primer elemento

    // Ciclo de rotación completa: O(n) tiempo, O(1) memoria auxiliar
    for (int i = 0; i < n; i++) {
        int current = Q.front();
        Q.pop(); // Sacar del frente temporalmente

        // Evaluar mínimo y máximo globales
        if (current < minVal) minVal = current;
        if (current > maxVal) maxVal = current;

        Q.push(current); // Re-encolar al final para restaurar su posición en el anillo lógico
    }

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Elemento Mayor: " << maxVal << "\n";
    std::cout << "\e[1;32m[RESULTADO]\e[0m Elemento Menor: " << minVal << "\n";
}


int main() {
    std::cout << "\n\e[0;35m[========= E06-MAYOR-MENOR-COLA =========]\e[0m\n\n";

    DrxQueue<int> myQueue;
    myQueue.push(15);
    myQueue.push(4);
    myQueue.push(42);
    myQueue.push(8);
    myQueue.push(23);

    std::cout << "Elementos de la cola: [ 15 4 42 8 23 ]\n";

    showMaxMin(myQueue);
    std::cout << "\n";

    return 0;
}
