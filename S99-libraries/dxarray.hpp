#pragma once // Evitar inclusión múltiple del archivo de cabecera

#include <iostream> // Biblioteca para entrada y salida estándar
#include <ctime> // Biblioteca para funciones relacionadas con el tiempo

// Función genérica para imprimir un arreglo de cualquier tipo de dato
// El template permite que la función sea genérica y pueda trabajar con cualquier tipo de dato (datatype)
// La palabra clave inline sugiere al compilador que inserte el código de la función directamente donde se llama,
// para reducir la sobrecarga de la llamada a la función (aunque depende del compilador si lo aplica o no)
template <typename datatype>
inline void printArray(datatype array[], int size, std::string message = "\n\e[0;33mEl arreglo es:") {

    // Imprime el inicio del arreglo con formato de color
    std::cout <<  message << "\e[0;34m[\e[0m";
    for (int i = 0; i < size; i++) {
        std::cout << array[i];

        // Imprime una coma entre elementos, pero no después del último elemento
        if (i != size - 1) std::cout << ",";
    }
    // Imprime el final del arreglo con formato de color
    std::cout << "\e[0;34m]\e[0m" << '\n';
}


// Función para llenar un arreglo de enteros con valores aleatorios
inline void randArray(int array[], int size) {
    // Inicializa la semilla del generador de números aleatorios usando el tiempo actual y el reloj
    srand(time(NULL) ^ (clock()));

    // Llena el arreglo con valores aleatorios en el rango [0, size * 2)
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (size * 2);
    }
}

// Función para llenar un arreglo de enteros con valores secuenciales
inline void fillArray(int array[], int size) {
    // Llena el arreglo con valores desde 0 hasta size - 1
    for (int i = 0; i < size; i++) array[i] = i;
}

// Función para llenar un arreglo de caracteres con letras alfabéticas secuenciales
inline void fillArray(char array[], int size) {
    // Llena el arreglo con caracteres desde 'a' en adelante
    for (int i = 0; i < size; i++) array[i] = i + 'a';
}

// Función para inicializar un arreglo de enteros con un valor específico
inline void initArray(int array[], int size, int value) {
    // Llena el arreglo con el valor proporcionado
    for (int i = 0; i < size; i++) array[i] = value;
}
