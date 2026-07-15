#include <iostream>

// Búsqueda binaria recursiva.
// Concepto Teórico (Estrategia Divide y Vencerás):
// La búsqueda binaria requiere obligatoriamente que el arreglo esté ordenado. 
// En lugar de buscar secuencialmente en O(n), compara el elemento del medio con el buscado 
// y descarta la mitad del arreglo en la que el elemento no puede estar.
// Esto reduce progresivamente el espacio de búsqueda a la mitad, con una complejidad temporal de O(log n).
// Esta implementación utiliza recursión de cola (tail recursion).
int binarySearch(const int array[], int number, int top, int bottom = 0) {
    // Caso base 1: El espacio de búsqueda se ha reducido a la nada (los índices se cruzaron),
    // lo que demuestra matemáticamente que el número no existe en el arreglo. Retorna -1.
    if (top < bottom) return -1;

    // Cálculo del punto medio. Teóricamente divide el espacio en dos partes aproximadamente iguales.
    int middle = (top + bottom) / 2;

    // Caso base 2: Encontramos el número en el índice del medio. Detiene la recursión y retorna la posición.
    if (array[middle] == number) return middle;

    // Caso recursivo 1: El elemento en el medio es menor que el buscado. 
    // Dado que el arreglo está ordenado, el valor buscado solo puede estar en la mitad derecha (valores mayores).
    // Reducimos el rango a [middle + 1, top].
    if (array[middle] < number) {
        return binarySearch(array, number, top, middle + 1);
    }

    // Caso recursivo 2: El elemento en el medio es mayor que el buscado (implícito).
    // El valor buscado solo puede estar en la mitad izquierda (valores menores).
    // Reducimos el rango a [bottom, middle - 1].
    return binarySearch(array, number, middle - 1, bottom);
}


int main() {
    std::cout << "\n\e[1;35m[========= E14-BUSQUEDA-BINARIA =========]\e[0m\n\n";

    int size, number;

    std::cout << "Ingrese el tamaño del arreglo: ";
    if (!(std::cin >> size) || size <= 0) return 1;

    std::cout << "Ingrese el número a buscar: ";
    if (!(std::cin >> number)) return 1;

    int* numbers = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "Ingrese el elemento [" << i << "] (debe estar ordenado): ";
        if (!(std::cin >> numbers[i])) {
            delete[] numbers;
            return 1;
        }
    }

    std::cout << "\nArreglo: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "]\n\n";

    int position = binarySearch(numbers, number, size - 1, 0);

    if (position == -1) {
        printf("\e[1;31m[RESULTADO]\e[0m El número no fue encontrado.\n\n");
    } else {
        printf("\e[1;32m[RESULTADO]\e[0m El número fue encontrado en la posición %d.\n\n", position);
    }

    delete[] numbers;
    return 0;
}
