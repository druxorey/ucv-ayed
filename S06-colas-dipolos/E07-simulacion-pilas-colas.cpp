#include <iostream>
#include "../S99-implementaciones/drxqueue.hpp"
#include "../S99-implementaciones/drxstack.hpp"

// Simulación de Pila utilizando una sola Cola.
template <typename T>
class SimulatedStack {
private:
    DrxQueue<T> Q;

public:
    // Insertar mantiene el elemento más nuevo al frente de la cola (LIFO).
    // Concepto Teórico (Simulación de LIFO usando FIFO con Rotación O(N)):
    // Para simular una pila usando una cola, debemos garantizar que el elemento insertado más recientemente 
    // sea el primero en salir (LIFO). 
    // Para lograr esto en 'push':
    // 1. Encolamos (push) el elemento al final de la cola de manera normal.
    // 2. Desencolamos y re-encolamos los 'n - 1' elementos anteriores uno por uno. 
    // Esto desplaza el nuevo elemento al frente de la cola, permitiendo que 'top()' y 'pop()' 
    // se resuelvan en O(1) tiempo simplemente consultando el frente de la cola.
    void push(const T& val) {
        Q.push(val);
        int n = Q.size();
        // Rotación de los n-1 elementos previos para colocarlos detrás del elemento nuevo
        for (int i = 0; i < n - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
    }


    void pop() {
        Q.pop();
    }


    T& top() {
        return Q.front();
    }


    bool isEmpty() const {
        return Q.isEmpty();
    }


    int size() const {
        return Q.size();
    }


    T sumElements() {
        T sum = 0;
        DrxQueue<T> temp = Q;
        while (!temp.isEmpty()) {
            sum += temp.front();
            temp.pop();
        }
        return sum;
    }
};


// Simulación de Cola utilizando dos Pilas (Amortizado).
template <typename T>
class SimulatedQueue {
private:
    DrxStack<T> P1; // Pila de entrada: Recibe los nuevos elementos (cola trasera / rear)
    DrxStack<T> P2; // Pila de salida: Provee los elementos en orden FIFO (cola delantera / front)

    // Concepto Teórico (Transferencia y Costo Amortizado O(1)):
    // Para proveer comportamiento FIFO con dos pilas LIFO, usamos P1 para insertar y P2 para extraer.
    // Cuando P2 está vacía, transferimos todos los elementos de P1 a P2. Esta operación revierte 
    // el orden de los elementos (el fondo de P1 pasa a ser el tope de P2), quedando en orden FIFO correcto.
    // Aunque una transferencia individual cuesta O(n), cada elemento se mueve entre pilas un número constante
    // de veces (4 operaciones de pila en total), lo que resulta en un costo amortizado de O(1) por operación de cola.
    void transfer() {
        if (P2.isEmpty()) {
            while (!P1.isEmpty()) {
                P2.push(P1.top());
                P1.pop();
            }
        }
    }

public:
    void push(const T& val) {
        P1.push(val);
    }


    void pop() {
        transfer();
        P2.pop();
    }


    T& front() {
        transfer();
        return P2.top();
    }


    bool isEmpty() {
        return P1.isEmpty() && P2.isEmpty();
    }
};


int main() {
    std::cout << "\n\e[0;35m[========= E07-SIMULACION-PILAS-COLAS =========]\e[0m\n\n";

    // Probar Pila simulada con Cola
    SimulatedStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Pila simulada (Tope esperado: 30): " << stack.top() << "\n";
    std::cout << "Suma de elementos de la pila: " << stack.sumElements() << "\n\n";

    // Probar Cola simulada con Pilas
    SimulatedQueue<int> queue;
    queue.push(100);
    queue.push(200);
    queue.push(300);

    std::cout << "\e[1;32m[RESULTADO]\e[0m Cola simulada (desencolando): ";
    while (!queue.isEmpty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << "\n\n";

    return 0;
}
