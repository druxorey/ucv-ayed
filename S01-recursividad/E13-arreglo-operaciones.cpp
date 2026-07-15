#include <iostream>

// Función recursiva para obtener el valor máximo de un arreglo.
// Concepto Teórico (Reducción de Dominio):
// El máximo de un arreglo de tamaño 'n' es el mayor valor entre el último elemento
// y el máximo del subarreglo compuesto por los primeros 'n-1' elementos.
int getMaxValue(const int numbers[], int size) {
    // Casos base:
    // Si size <= 0 (arreglo vacío), no hay máximo definido, se retorna 0 por seguridad.
    // Si size == 1, el único elemento es trivialmente el máximo, deteniendo la recursión.
    if (size <= 0) return 0;
    if (size == 1) return numbers[0];

    // Caso recursivo:
    // 1. Resolvemos para el subarreglo de tamaño size-1 para obtener su máximo ('residualMax').
    // 2. Comparamos el último elemento actual con 'residualMax' y retornamos el mayor de ambos.
    int residualMax = getMaxValue(numbers, size - 1);
    return numbers[size - 1] > residualMax ? numbers[size - 1] : residualMax;
}


// Función recursiva para calcular el valor promedio del arreglo sin calcular la suma total previamente.
// Concepto Teórico (Media Recursiva / Online Average):
// Sea A(k) el promedio de los primeros k elementos. Su suma es k * A(k).
// Para calcular A(k) a partir del promedio anterior A(k-1):
// A(k) = (Suma de los k elementos) / k = (numbers[k-1] + Suma de los k-1 elementos) / k
// Dado que la Suma de los k-1 elementos es (k-1) * A(k-1), sustituimos:
// A(k) = (numbers[k-1] + (k-1) * A(k-1)) / k.
double getMidValue(const int numbers[], int size) {
    // Caso base: El promedio de un arreglo de un solo elemento es el mismo elemento.
    if (size == 1) return numbers[0];

    // Caso recursivo:
    // Aplicamos la fórmula matemática descrita para integrar el último elemento al promedio
    // de los elementos anteriores calculado de manera recursiva.
    return (numbers[size - 1] + (size - 1) * getMidValue(numbers, size - 1)) / size;
}


// Función recursiva para sumar todos los valores del arreglo.
// Concepto Teórico (Acumulación Lineal):
// La suma de un arreglo de tamaño n es el valor del último elemento más la suma del subarreglo restante.
int sumValues(const int numbers[], int size) {
    // Caso base: La suma de un arreglo de tamaño 0 es 0 (neutro aditivo).
    if (size <= 0) return 0;

    // Caso recursivo:
    // Se suma el elemento actual de la posición size-1 con el resultado de la llamada recursiva
    // sobre los primeros size-1 elementos.
    return numbers[size - 1] + sumValues(numbers, size - 1);
}


// Función recursiva para verificar si el arreglo está ordenado de forma ascendente.
// Concepto Teórico (Poda de Ejecución y Recursión de Cola):
// Un arreglo está ordenado de forma ascendente si cada elemento es menor o igual al elemento a su derecha.
// Esta función es de tipo "recursión de cola" (tail recursion) porque el resultado de la llamada recursiva
// se retorna directamente, permitiendo al compilador optimizar el espacio en la pila de llamadas.
bool isSorted(const int numbers[], int size) {
    // Caso base 1: Un arreglo con 1 o ningún elemento siempre está ordenado por definición.
    if (size <= 1) return true;

    // Poda temprana: Si el último elemento es menor que el penúltimo, viola el orden ascendente,
    // por lo que finalizamos la recursión inmediatamente retornando false.
    if (numbers[size - 1] < numbers[size - 2]) return false;

    // Caso recursivo: Si los dos últimos elementos están en orden correcto, se procede a
    // comprobar inductivamente el subarreglo restante de tamaño size-1.
    return isSorted(numbers, size - 1);
}


int main() {
    std::cout << "\n\e[1;35m[========= E13-ARREGLO-OPERACIONES =========]\e[0m\n\n";

    int size;
    std::cout << "Ingrese el tamaño del arreglo: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cerr << "\e[1;31m[ERROR]\e[0m Tamaño inválido.\n\n";
        return 1;
    }

    int* numbers = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "Ingrese el elemento [" << i << "]: ";
        if (!(std::cin >> numbers[i])) {
            delete[] numbers;
            return 1;
        }
    }

    std::cout << "\nArreglo ingresado: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "]\n\n";

    printf("\e[1;33m[RESULTADO]\e[0m El valor máximo es: %d\n", getMaxValue(numbers, size));
    printf("\e[1;33m[RESULTADO]\e[0m La suma de los valores es: %d\n", sumValues(numbers, size));
    printf("\e[1;33m[RESULTADO]\e[0m El valor promedio es: %f\n", getMidValue(numbers, size));

    if (isSorted(numbers, size)) {
        printf("\e[1;32m[RESULTADO]\e[0m El arreglo está ordenado\n\n");
    } else {
        printf("\e[1;31m[RESULTADO]\e[0m El arreglo no está ordenado\n\n");
    }

    delete[] numbers;
    return 0;
}
