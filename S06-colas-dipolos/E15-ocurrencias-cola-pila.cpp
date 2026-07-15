#include <iostream>
#include "../S99-implementaciones/drxqueue.hpp"
#include "../S99-implementaciones/drxstack.hpp"

// Verifica si un elemento ya fue visitado/procesado anteriormente.
bool alreadyProcessed(int val, int visited[], int count) {
    for (int i = 0; i < count; i++) {
        if (visited[i] == val) return true;
    }
    return false;
}


// Obtiene una pila con los elementos únicos de la cola y sus respectivas ocurrencias.
// Concepto Teórico (Frecuencias In-Place en Colas Mediante Rotaciones e Historial):
// Calcular frecuencias en colas sin destruir su orden y sin usar estructuras asociativas (hashmaps)
// requiere un algoritmo de fuerza bruta estructurado en O(n^2) tiempo y O(n) espacio auxiliar.
// - Usamos un arreglo 'visited' para recordar los elementos únicos ya procesados.
// - Iteramos 'n' veces (una por cada elemento de la cola original).
// - En cada iteración:
//   - Sacamos el elemento frontal 'current'. 
//   - Si es nuevo, rotamos el resto de la cola ('remainingElements') comparándolos uno a uno con 'current'
//     para contar las ocurrencias, re-encolándolos inmediatamente para no perderlos.
//   - Si ya fue visitado, simplemente lo re-encolamos para restaurar su posición sin recalcular su frecuencia.
//   - Los resultados se apilan en pares: primero el valor del elemento y luego su frecuencia.
DrxStack<int> countFrequencies(DrxQueue<int>& Q) {
    DrxStack<int> resultStack;
    int n = Q.size();
    if (n == 0) return resultStack; // Caso base: Cola vacía

    int* visited = new int[n]; // Registro para evitar el doble conteo de un elemento
    int visitedCount = 0;

    // Recorrido de los n elementos de la cola original
    for (int i = 0; i < n; i++) {
        int current = Q.front();
        Q.pop(); // Extraer temporalmente el frente de la cola

        // Si el elemento no ha sido evaluado previamente
        if (!alreadyProcessed(current, visited, visitedCount)) {
            int frequency = 1; // Todo elemento tiene al menos 1 ocurrencia (él mismo)
            
            visited[visitedCount++] = current; // Registrar en la lista de visitados

            // Escanear los elementos restantes que quedan por delante en la cola
            int remainingElements = n - i - 1;
            for (int j = 0; j < remainingElements; j++) {
                int temp = Q.front();
                Q.pop();
                if (temp == current) {
                    frequency++; // Coincidencia encontrada
                }
                Q.push(temp); // Mantener el elemento en el ciclo rotatorio
            }

            // Apilar el par [elemento, frecuencia]
            resultStack.push(current);
            resultStack.push(frequency);
        }
        
        Q.push(current); // Re-encolar 'current' al final para completar su rotación
    }

    delete[] visited; // Liberar memoria dinámica del registro de visitados
    return resultStack;
}


int main() {
    std::cout << "\n\e[0;35m[========= E15-OCURRENCIAS-COLA-PILA =========]\e[0m\n\n";

    DrxQueue<int> myQueue;
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(2);
    myQueue.push(5);
    myQueue.push(3);
    myQueue.push(2);

    std::cout << "Cola de entrada: [ 2 3 2 5 3 2 ]\n";

    DrxStack<int> resultStack = countFrequencies(myQueue);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Contenido de la pila resultante (Pila de [elemento, frecuencia]):\n";
    resultStack.print();
    std::cout << "\n";

    return 0;
}
