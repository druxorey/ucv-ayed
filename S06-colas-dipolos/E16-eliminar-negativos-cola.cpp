#include <iostream>
#include "../S99-implementaciones/drxqueue.hpp"

// Elimina todos los números negativos de la cola manteniendo el orden de los demás.
// Concepto Teórico (Filtrado In-Place en Colas mediante Rotación Selectiva):
// Para filtrar elementos en una cola manteniendo el orden relativo de los elementos restantes y 
// sin utilizar memoria dinámica o estructuras auxiliares adicionales (O(1) de espacio auxiliar):
// - Determinamos el tamaño inicial N.
// - Iteramos N veces descolando el elemento frontal 'current'.
// - Si 'current' es no-negativo (mayor o igual a cero), lo volvemos a encolar al final (Q.push).
// - Si es negativo, simplemente lo ignoramos (no se vuelve a encolar, eliminándolo de la estructura).
// Al terminar las N iteraciones, la cola contendrá únicamente los elementos no-negativos en su secuencia original.
void removeNegatives(DrxQueue<int>& Q) {
    int n = Q.size();
    if (n == 0) return; // Caso base: Cola vacía no tiene elementos

    // Ciclo de evaluación y rotación selectiva
    for (int i = 0; i < n; i++) {
        int current = Q.front();
        Q.pop(); // Extraer elemento del frente

        // Si el número es positivo o cero, se encola de vuelta al final
        if (current >= 0) {
            Q.push(current);
        } else {
            // Si es negativo, se elimina (al no volverlo a encolar)
            std::cout << "  Eliminado elemento negativo: " << current << "\n";
        }
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E16-ELIMINAR-NEGATIVOS-COLA =========]\e[0m\n\n";

    DrxQueue<int> myQueue;
    myQueue.push(10);
    myQueue.push(-5);
    myQueue.push(20);
    myQueue.push(-3);
    myQueue.push(-1);
    myQueue.push(30);

    std::cout << "Cola inicial: [ 10 -5 20 -3 -1 30 ]\n\n";

    removeNegatives(myQueue);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Cola resultante sin elementos negativos: [ ";
    while (!myQueue.isEmpty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << "]\n\n";

    return 0;
}
