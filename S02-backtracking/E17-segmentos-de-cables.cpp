#include <iostream>

const int TARGET = 100; // Meta: 100 metros

// Backtracking para buscar la combinación que requiera el menor número de soldaduras.
// Concepto Teórico (Problema de la Suma de Subconjuntos con Optimización / Subset Sum):
// Queremos encontrar un subconjunto de cables cuya suma sea exactamente TARGET (100 metros) y 
// que minimice la cantidad de segmentos utilizados (soldaduras = tamaño de combinación - 1).
// Es una exploración binaria de árbol (tomar o no tomar cada elemento).
// Se implementa una poda por optimalidad para descartar ramas subóptimas tempranamente.
void findOptimalCombination(int idx, int currentSum, const int cables[], int cablesSize, 
                             int currentCombination[], int currentSize, 
                             int bestCombination[], int& bestSize) {
    // Caso base de éxito: La combinación actual suma exactamente la meta (100 metros).
    if (currentSum == TARGET) {
        // Si es la primera combinación válida encontrada (bestSize == -1) 
        // o si esta combinación usa menos cables que la mejor anterior (currentSize < bestSize)
        if (bestSize == -1 || currentSize < bestSize) {
            bestSize = currentSize; // Actualizar el mínimo global de cables
            for (int i = 0; i < currentSize; i++) {
                bestCombination[i] = currentCombination[i]; // Registrar la combinación ganadora
            }
        }
        return; // Retornar, no hay necesidad de seguir agregando cables
    }

    // Pruebas de Poda (Filtros de Viabilidad y Optimalidad):
    // 1. Poda por exceso: Si la suma actual supera la meta, no es posible reducirla agregando más cables (longitudes positivas).
    if (currentSum > TARGET) return;
    
    // 2. Poda por optimalidad: Si ya conocemos una solución válida de tamaño 'bestSize' y la combinación
    //    actual ya tiene igual o más elementos (currentSize >= bestSize), cualquier adición solo empeorará 
    //    o igualará la solución actual. Cortamos esta rama inmediatamente.
    if (bestSize != -1 && currentSize >= bestSize) return;
    
    // 3. Poda por fin de datos: Si recorrimos todos los cables disponibles sin alcanzar el TARGET.
    if (idx >= cablesSize) return;

    // Bucle de decisiones binarias (Incluir o Excluir el elemento 'idx'):
    
    // Decisión 1: Seleccionar el cable actual 'idx'
    currentCombination[currentSize] = cables[idx]; // Guardar temporalmente el cable en el subconjunto
    // Llamada recursiva avanzando al siguiente cable, acumulando longitud y aumentando el tamaño
    findOptimalCombination(idx + 1, currentSum + cables[idx], cables, cablesSize, currentCombination, currentSize + 1, bestCombination, bestSize);

    // Decisión 2: Omitir el cable actual 'idx'
    // Llamada recursiva sin agregar el cable al subconjunto. El backtracking es implícito, 
    // ya que 'currentSize' no aumenta, por lo que futuras inclusiones sobrescribirán la posición en 'currentCombination'.
    findOptimalCombination(idx + 1, currentSum, cables, cablesSize, currentCombination, currentSize, bestCombination, bestSize);
}


int main() {
    std::cout << "\n\e[0;35m[========= E17-SEGMENTOS-DE-CABLES =========]\e[0m\n\n";

    int n;
    std::cout << "Introduce el número total de pedazos de cable (N): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m El número de cables debe ser mayor que cero.\n\n";
        return 1;
    }

    int* cables = new int[n];
    std::cout << "\nIntroduce la longitud de cada uno de los " << n << " pedazos de cable:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Longitud de cable " << (i + 1) << " (metros): ";
        if (!(std::cin >> cables[i])) {
            delete[] cables;
            return 1;
        }
    }

    int* currentCombination = new int[n];
    int* bestCombination = new int[n];
    int bestSize = -1;

    findOptimalCombination(0, 0, cables, n, currentCombination, 0, bestCombination, bestSize);

    if (bestSize != -1) {
        int welds = bestSize - 1;
        std::cout << "\n\e[1;32m[RESULTADO]\e[0m ¡Se puede generar un cable de 100 metros!\n";
        std::cout << "Segmentos de cable utilizados: ";
        for (int i = 0; i < bestSize; i++) {
            std::cout << bestCombination[i] << "m";
            if (i != bestSize - 1) std::cout << ", ";
        }
        std::cout << "\nCantidad de soldaduras necesarias (mínima): " << welds << "\n\n";
    } else {
        std::cout << "\n\e[1;31m[RESULTADO]\e[0m No es posible combinar ningún conjunto de cables que sume exactamente 100 metros.\n\n";
    }

    delete[] cables;
    delete[] currentCombination;
    delete[] bestCombination;

    return 0;
}
