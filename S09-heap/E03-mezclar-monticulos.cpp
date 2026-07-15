#include <iostream>
#include <stdexcept>

class MaxHeap {
private:
    int* heap;
    int capacity;
    int count;

    int getParent(int i) { return (i - 1) / 2; }
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }

    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void floatUp(int i) {
        while (i > 0 && heap[getParent(i)] < heap[i]) {
            swap(i, getParent(i));
            i = getParent(i);
        }
    }

    void sinkDown(int i) {
        int maxIndex = i;
        int leftIndex = getLeft(i);
        int rightIndex = getRight(i);

        if (leftIndex < count && heap[leftIndex] > heap[maxIndex]) {
            maxIndex = leftIndex;
        }
        if (rightIndex < count && heap[rightIndex] > heap[maxIndex]) {
            maxIndex = rightIndex;
        }

        if (i != maxIndex) {
            swap(i, maxIndex);
            sinkDown(maxIndex);
        }
    }

public:
    MaxHeap(int capacityVal) : capacity(capacityVal), count(0) {
        heap = new int[capacityVal];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(int elem) {
        if (count >= capacity) {
            throw std::runtime_error("Montículo lleno");
        }
        heap[count] = elem;
        count++;
        floatUp(count - 1);
    }

    int remove() {
        if (count == 0) {
            throw std::runtime_error("Montículo vacío");
        }
        int maxVal = heap[0];
        heap[0] = heap[count - 1];
        count--;
        sinkDown(0);
        return maxVal;
    }

    bool contains(int elem) const {
        for (int i = 0; i < count; i++) {
            if (heap[i] == elem) return true;
        }
        return false;
    }

    // Mezcla los elementos de M en este montículo ADMITIENDO claves repetidas.
    // Concepto Teórico (Mezcla Destructiva con Duplicados):
    // Extraemos secuencialmente el elemento máximo del montículo 'M' mediante 'M.remove()' (complejidad O(log K))
    // y lo insertamos en el montículo actual 'this->insert()' (complejidad O(log N)).
    // - Al extraer el máximo en cada paso de M, mantenemos la estructura de M válida y vaciamos M progresivamente.
    // - Este método admite claves duplicadas sin restricciones.
    // Complejidad temporal: O(K * log(N + K)), donde K es el tamaño de M y N el tamaño de este montículo.
    void mergeWithDuplicates(MaxHeap& M) {
        while (M.count > 0) {
            int elem = M.remove(); // O(log K)
            this->insert(elem);   // O(log(N + K))
        }
    }

    // Mezcla los elementos de M en este montículo SIN ADMITIR claves repetidas.
    // Concepto Teórico (Mezcla de Conjuntos / Sin Repetidos):
    // Similar al método anterior, pero antes de insertar el elemento extraído de 'M', 
    // verificamos su presencia en el montículo actual usando 'contains(elem)'.
    // - 'contains' realiza una búsqueda lineal O(N) sobre el arreglo contiguo del heap.
    // - Si el elemento no existe, se inserta; de lo contrario, se descarta.
    // Complejidad temporal: O(K * (N + log(N + K))) debido al costo O(N) del filtrado de duplicados.
    void mergeWithoutDuplicates(MaxHeap& M) {
        while (M.count > 0) {
            int elem = M.remove();
            // Filtrar duplicados mediante búsqueda secuencial en el arreglo
            if (!this->contains(elem)) {
                this->insert(elem);
            }
        }
    }

    bool empty() const { return count == 0; }
    void print() const {
        for (int i = 0; i < count; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "\n\e[0;35m[========= E03-MEZCLAR-MONTICULOS =========]\e[0m\n\n";

    MaxHeap m1(10);
    m1.insert(15);
    m1.insert(10);
    m1.insert(5);

    MaxHeap m2(5);
    m2.insert(10); 
    m2.insert(20); 

    std::cout << "Montículo 1 (Inicial): "; m1.print();
    std::cout << "Montículo 2 (A mezclar): "; m2.print();

    m1.mergeWithoutDuplicates(m2);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Montículo 1 después de la mezcla sin repetidos: ";
    m1.print();
    std::cout << "\n";

    return 0;
}
