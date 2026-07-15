#include <iostream>
#include <stdexcept>

class MaxHeap {
private:
    int* heap;    // Arreglo dinámico contenedor
    int capacity; // Capacidad física
    int count;    // Conteo de elementos activos

    int getParent(int i) { return (i - 1) / 2; }
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }

    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // Flota el elemento en el índice 'i' hacia arriba para mantener la propiedad de max-heap.
    // Concepto Teórico (Flotación Ascendente / Up-Heap / Shift-Up):
    // Cuando insertamos un elemento al final del arreglo (manteniendo la propiedad de forma), 
    // es posible que este sea mayor que su padre, violando la propiedad de orden del Max-Heap.
    // Para corregirlo, comparamos el nodo con su padre:
    // - Si el nodo es mayor, lo intercambiamos (swap) con su padre y nos desplazamos al índice del padre.
    // - Repetimos esto hasta que el nodo sea menor o igual que su padre, o hayamos alcanzado la raíz (índice 0).
    // Complejidad temporal: O(log n) debido a que la altura máxima del árbol es logarítmica.
    void floatUp(int i) {
        while (i > 0 && heap[getParent(i)] < heap[i]) {
            swap(i, getParent(i)); // Intercambio con el padre
            i = getParent(i);      // Subir el cursor
        }
    }

    // Hunde el elemento en el índice 'i' hacia abajo para mantener la propiedad de max-heap.
    // Concepto Teórico (Hundimiento Descendente / Down-Heap / Shift-Down):
    // Al remover el elemento máximo (raíz), reemplazamos la raíz con el último elemento del arreglo 
    // para conservar la forma completa del árbol. Sin embargo, este elemento suele ser pequeño y viola
    // la propiedad de orden.
    // Para restablecer la propiedad:
    // - Comparamos el nodo actual con sus dos hijos (izquierdo y derecho) si existen dentro de los límites.
    // - Determinamos cuál de los tres contiene el mayor valor ('maxIndex').
    // - Si el mayor no es el nodo actual 'i', los intercambiamos y llamamos recursivamente a 'sinkDown' 
    //   sobre el nuevo índice para seguir descendiendo la anomalía.
    // Complejidad temporal: O(log n).
    void sinkDown(int i) {
        int maxIndex = i;
        int leftIndex = getLeft(i);
        int rightIndex = getRight(i);

        // Comparar con el hijo izquierdo
        if (leftIndex < count && heap[leftIndex] > heap[maxIndex]) {
            maxIndex = leftIndex;
        }
        // Comparar con el hijo derecho
        if (rightIndex < count && heap[rightIndex] > heap[maxIndex]) {
            maxIndex = rightIndex;
        }

        // Si la propiedad de max-heap se viola en este nivel, intercambiamos y continuamos hacia abajo
        if (i != maxIndex) {
            swap(i, maxIndex);
            sinkDown(maxIndex); // Recursión de hundimiento
        }
    }

public:
    MaxHeap(int capacityVal) : capacity(capacityVal), count(0) {
        heap = new int[capacityVal];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    // Inserta un elemento en el montículo.
    // Concepto Teórico (Inserción en Montículos):
    // 1. Colocamos el elemento al final del arreglo físico (heap[count] = elem) para no alterar la 
    //    propiedad de estructura (árbol binario completo lleno de izquierda a derecha).
    // 2. Incrementamos la cantidad de elementos.
    // 3. Ejecutamos la flotación 'floatUp(count - 1)' desde el final para reubicar el elemento 
    //    en su posición jerárquica correcta.
    void insert(int elem) {
        if (count >= capacity) {
            throw std::runtime_error("Montículo lleno (Overflow)");
        }
        heap[count] = elem;
        count++;
        floatUp(count - 1); // Re-establecer orden O(log n)
    }

    // Remueve y retorna el elemento máximo (la raíz).
    // Concepto Teórico (Extracción del Máximo / Cima):
    // En un Max-Heap, el elemento prioritario (máximo) se ubica siempre en la raíz (heap[0]).
    // 1. Guardamos el valor de la raíz para retornarlo.
    // 2. Colocamos el último elemento físico (heap[count - 1]) en la raíz para conservar la forma del árbol.
    // 3. Decrementamos el tamaño del montículo.
    // 4. Hundimos el nuevo elemento raíz mediante 'sinkDown(0)' para devolverlo a una ubicación consistente.
    int remove() {
        if (count == 0) {
            throw std::runtime_error("Montículo vacío (Underflow)");
        }
        int maxVal = heap[0];          // Registrar la raíz
        heap[0] = heap[count - 1];     // Trasladar el último elemento a la cima
        count--;                       // Reducir tamaño lógico
        sinkDown(0);                   // Re-establecer orden O(log n)
        return maxVal;
    }

    bool empty() const { return count == 0; }
    int size() const { return count; }

    void print() const {
        for (int i = 0; i < count; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "\n\e[0;35m[========= E02-IMPLEMENTACION-MONTICULO =========]\e[0m\n\n";

    MaxHeap m(10);
    std::cout << "Insertando elementos: 15, 8, 20, 5, 30...\n";
    m.insert(15);
    m.insert(8);
    m.insert(20);
    m.insert(5);
    m.insert(30);

    std::cout << "Estado interno del Heap (Max-Heap esperado): ";
    m.print();

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Extrayendo elementos en orden de prioridad:\n";
    while (!m.empty()) {
        std::cout << "  - Extraído: " << m.remove() << "\n";
    }
    std::cout << "\n";

    return 0;
}
