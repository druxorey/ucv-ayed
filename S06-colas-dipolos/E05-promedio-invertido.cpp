#include <iostream>
#include "../S99-implementaciones/drxqueue.hpp"
#include "../S99-implementaciones/drxstack.hpp"

// Calcula el promedio de la cola e invierte su orden en-sitio utilizando una pila auxiliar.
// Concepto Teórico (Inversión de Colecciones mediante Acoplamiento FIFO/LIFO):
// Una cola entrega elementos en orden de llegada (FIFO). Si extraemos todos los elementos de la cola 
// y los insertamos en una pila (LIFO), el orden de almacenamiento físico se invierte por completo.
// - Al desapilar la pila auxiliar y reinsertar los elementos en la cola original, la cola queda 
//   con sus elementos en el orden inverso respecto a su estado inicial (ej. [10, 20, 30] se convierte en [30, 20, 10]).
// - Durante la transferencia inicial, acumulamos la suma de los valores para calcular la media aritmética.
void calculateAndReverse(DrxQueue<int>& Q) {
    DrxStack<int> auxStack; // Pila auxiliar LIFO para la inversión de orden
    double sum = 0;
    int count = Q.size();

    if (count == 0) {
        std::cout << "\nCola vacía.\n";
        return;
    }

    // 1. Fase de Extracción y Acumulación (FIFO a LIFO):
    // Desencolamos elementos del frente de la cola uno a uno.
    // Acumulamos su valor para el promedio y los apilamos. El primer elemento en salir quedará al fondo de la pila.
    while (!Q.isEmpty()) {
        int value = Q.front();
        sum += value;
        auxStack.push(value); // Apilar el elemento
        Q.pop(); // Remover de la cola
    }

    // Calcular el promedio usando precisión flotante
    double average = sum / count;
    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Promedio de los elementos: " << average << "\n";

    // 2. Fase de Restauración Invertida (LIFO a FIFO):
    // Desapilamos la pila auxiliar. Los elementos salen en orden inverso al original (del último al primero).
    // Los imprimimos y los encolamos de vuelta en Q. 
    // Como el último elemento original sale primero y se encola primero, se convierte en el nuevo frente de la cola.
    std::cout << "Cola en orden invertido: [ ";
    while (!auxStack.isEmpty()) {
        std::cout << auxStack.top() << " ";
        Q.push(auxStack.top()); // Encolar de vuelta en Q (nuevo orden invertido)
        auxStack.pop(); // Remover de la pila
    }
    std::cout << "]\n";
}


int main() {
    std::cout << "\n\e[0;35m[========= E05-PROMEDIO-INVERTIDO =========]\e[0m\n\n";

    DrxQueue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);

    std::cout << "Cola original (Front a Rear): [ 10 20 30 40 50 ]\n";

    calculateAndReverse(myQueue);
    std::cout << "\n";

    return 0;
}
