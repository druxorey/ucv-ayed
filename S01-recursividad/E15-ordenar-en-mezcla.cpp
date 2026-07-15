#include <iostream>

// Generador congruencial lineal simple para obtener números pseudoaleatorios sin usar cstdlib.
unsigned int nextRandom() {
    static unsigned int seed = 123456789;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 100; // Retorna valores entre 0 y 99
}


// Función auxiliar para combinar (mezclar) dos subarreglos ordenados de un arreglo.
// Concepto Teórico (Paso Combinar en Divide y Vencerás):
// Dadas dos mitades ordenadas: array[left...middle] y array[middle+1...right], 
// las copiamos en dos arreglos temporales auxiliares. Luego, mediante dos índices,
// comparamos secuencialmente los elementos de ambas mitades para insertarlos en orden ascendente 
// de vuelta en el arreglo original. Esto requiere O(n) memoria auxiliar.
void merge(int array[], int left, int middle, int right) {
    int n1 = middle - left + 1; // Tamaño del subarreglo izquierdo
    int n2 = right - middle;    // Tamaño del subarreglo derecho

    // Asignación de memoria temporal para las dos mitades independientes
    int* tempLeft = new int[n1];
    int* tempRight = new int[n2];

    // Copiado de datos a los arreglos temporales
    for (int i = 0; i < n1; i++) tempLeft[i] = array[left + i];
    for (int j = 0; j < n2; j++) tempRight[j] = array[middle + 1 + j];

    // Combinación de los arreglos temporales de vuelta al arreglo principal 'array'
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        // Estabilidad: Si los elementos son iguales, se prefiere el del subarreglo izquierdo tempLeft,
        // manteniendo el orden original relativo de elementos repetidos (algoritmo de ordenamiento estable).
        if (tempLeft[i] <= tempRight[j]) {
            array[k++] = tempLeft[i++];
        } else {
            array[k++] = tempRight[j++];
        }
    }

    // Copiar los elementos restantes de tempLeft si quedaron pendientes
    while (i < n1) array[k++] = tempLeft[i++];
    // Copiar los elementos restantes de tempRight si quedaron pendientes
    while (j < n2) array[k++] = tempRight[j++];

    // Liberación de la memoria dinámica auxiliar para evitar fugas de memoria
    delete[] tempLeft;
    delete[] tempRight;
}


// Algoritmo de ordenamiento por mezcla (Merge Sort) recursivo.
// Concepto Teórico (Estrategia de Divide y Vencerás):
// Divide el problema original en subproblemas similares más pequeños (mitades),
// resuelve recursivamente cada mitad y finalmente integra las soluciones para ordenar el arreglo.
// Complejidad temporal garantizada de O(n log n).
void mergeSort(int array[], int left, int right) {
    // Caso base: Si el rango tiene 0 o 1 elementos (left >= right),
    // el subarreglo ya está ordenado de forma trivial. Detiene la recursión.
    if (left >= right) return;

    // Calcular el punto medio para la división sin riesgo de desbordamiento (left + (right - left) / 2)
    int middle = left + (right - left) / 2;

    // Fases de División y Conquista recursiva:
    // 1. Ordenar recursivamente la mitad izquierda.
    mergeSort(array, left, middle);
    // 2. Ordenar recursivamente la mitad derecha.
    mergeSort(array, middle + 1, right);

    // Fase de Combinación:
    // Mezcla las dos mitades ya ordenadas en una sola estructura completamente ordenada.
    merge(array, left, middle, right);
}


int main() {
    std::cout << "\n\e[1;35m[========= E15-ORDENAR-EN-MEZCLA =========]\e[0m\n\n";

    int size;
    std::cout << "Ingrese el tamaño del arreglo: ";
    if (!(std::cin >> size) || size <= 0) return 1;

    int* numbers = new int[size];

    // Generar elementos aleatorios con LCG
    for (int i = 0; i < size; ++i) {
        numbers[i] = nextRandom();
    }

    std::cout << "\n\e[1;33m[GENERADO]\e[0m Arreglo generado: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "]\n";

    mergeSort(numbers, 0, size - 1);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Arreglo ordenado: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "]\n\n";

    delete[] numbers;
    return 0;
}
