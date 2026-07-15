#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"
#include "../S99-implementaciones/drxqueue.hpp"

// Convierte un número decimal almacenado en una pila a binario en una cola.
// Concepto Teórico (Conversión Decimal a Binario y Reversión de bits):
// La conversión de decimal a binario se realiza mediante divisiones sucesivas por 2. 
// Los residuos (bits) se calculan desde el menos significativo (LSB) al más significativo (MSB).
// - Para presentarlos en el orden binario estándar (de izquierda a derecha, MSB a LSB),
//   utilizamos una Pila temporal 'remStack' (LIFO) donde el MSB quedará en el tope de la pila.
// - Luego, vaciamos 'remStack' en una Cola 'resultQueue' (FIFO), lo que resulta en una cola que expone
//   los bits en el orden de lectura tradicional, listos para su impresión directa.
DrxQueue<int> decimalToBinary(DrxStack<int>& decimalStack) {
    DrxQueue<int> resultQueue;
    
    if (decimalStack.isEmpty()) return resultQueue;

    // Desapilar el número decimal de entrada
    int number = decimalStack.top();
    decimalStack.pop();

    // Caso especial: El número 0 tiene representación binaria 0.
    if (number == 0) {
        resultQueue.push(0);
        return resultQueue;
    }

    DrxStack<int> remStack; // Pila para invertir el orden de los residuos

    // 1. Fase de Divisiones Sucesivas (Cálculo de bits de derecha a izquierda):
    // El residuo (number % 2) es el bit actual. Lo apilamos en 'remStack'.
    // El cociente (number / 2) se convierte en el nuevo número.
    while (number > 0) {
        remStack.push(number % 2); // Apilar el residuo (LSB se va al fondo, MSB al tope)
        number /= 2;
    }

    // 2. Fase de Transferencia (Restauración de orden MSB a LSB):
    // Desapilar de 'remStack' y encolar en 'resultQueue'.
    // Esto asegura que el MSB (que está al tope) sea el primero en entrar a la cola y, por ende, el primero en salir.
    while (!remStack.isEmpty()) {
        resultQueue.push(remStack.top());
        remStack.pop();
    }

    return resultQueue;
}


int main() {
    std::cout << "\n\e[0;35m[========= E10-DECIMAL-A-BINARIO =========]\e[0m\n\n";

    DrxStack<int> numStack;
    numStack.push(36);
    std::cout << "Número decimal almacenado en la pila: 36\n";

    DrxQueue<int> binaryQueue = decimalToBinary(numStack);

    std::cout << "\e[1;32m[RESULTADO]\e[0m Representación binaria en la cola resultante: ";
    while (!binaryQueue.isEmpty()) {
        std::cout << binaryQueue.front();
        binaryQueue.pop();
    }
    std::cout << "\n\n";

    return 0;
}
