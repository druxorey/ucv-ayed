#include <iostream>

// Representación de una Cola mediante Arreglo Circular (ArrayQueue).
template <typename T>
class ArrayQueue {
private:
    T* data;          // Arreglo dinámico contenedor
    int capacity;     // Capacidad máxima física
    int frontIndex;   // Índice del primer elemento
    int rearIndex;    // Índice del último elemento encolado
    int elementCount; // Conteo de elementos activos

public:
    ArrayQueue(int cap = 100) : capacity(cap), frontIndex(0), rearIndex(-1), elementCount(0) {
        data = new T[capacity];
    }


    ~ArrayQueue() {
        delete[] data;
    }


    // Inserción en O(1) usando aritmética modular en arreglo circular.
    // Concepto Teórico (Inserción Circular / Encolado):
    // Para insertar (push) un elemento al final de la cola sin desplazar elementos en memoria, 
    // avanzamos el índice 'rearIndex' de manera circular: (rearIndex + 1) % capacity.
    // El operador módulo (%) hace que el índice salte de la última casilla física a la primera (0)
    // si queda espacio disponible, reutilizando las casillas vaciadas anteriormente por los descolados.
    void push(const T& val) {
        if (elementCount == capacity) {
            throw "Cola llena (Overflow)"; // Condición de error al superar la capacidad máxima
        }
        rearIndex = (rearIndex + 1) % capacity; // Avance circular
        data[rearIndex] = val;
        elementCount++; // Incrementar tamaño lógico
    }


    // Eliminación en O(1) moviendo el cursor inicial.
    // Concepto Teórico (Desencolado en Arreglos Circulares):
    // La eliminación (pop) en una cola de prioridad FIFO remueve el elemento en el frente.
    // En lugar de mover todos los elementos un lugar a la izquierda (complejidad O(n)), simplemente 
    // avanzamos el cursor del frente 'frontIndex' un paso circularmente: (frontIndex + 1) % capacity.
    // Esto es de complejidad temporal O(1) y deja libre el espacio al inicio para futuras inserciones circulares.
    void pop() {
        if (isEmpty()) {
            throw "Cola vacía (Underflow)"; // Evitar desapilar de una estructura vacía
        }
        frontIndex = (frontIndex + 1) % capacity; // Desvío circular del frente
        elementCount--; // Decrementar tamaño lógico
    }


    T& front() {
        if (isEmpty()) {
            throw "Cola vacía";
        }
        return data[frontIndex];
    }


    bool isEmpty() const {
        return elementCount == 0;
    }


    int size() const {
        return elementCount;
    }
};


int main() {
    std::cout << "\n\e[0;35m[========= E04-COLA-ARREGLO =========]\e[0m\n\n";

    ArrayQueue<int> queue(5);
    std::cout << "Encolando elementos: 10, 20, 30, 40, 50...\n";
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Desencolando y mostrando los valores:\n";
    while (!queue.isEmpty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << "\n\n";

    return 0;
}
