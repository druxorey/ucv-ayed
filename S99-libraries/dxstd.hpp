#pragma once // Evitar inclusión múltiple del archivo de cabecera

#include <iostream> // Biblioteca para entrada y salida estándar

// Macro para simplificar la sintaxis de los bucles
#define REPEAT(n) for(int i = 0; i < n; i++) 
// Macro para pausar la ejecución y esperar entrada del usuario
#define ENTER std::cin.get(); std::cin.ignore()

// Función plantilla para obtener entrada del usuario con validación
template <typename datatype>
void getcin(std::string message, datatype &input) {
    do {
        std::cout << message;
        std::cin >> input;

        // Si la entrada es válida, salir del bucle
        if (!std::cin.fail()) break;

        // Mensaje de error en caso de entrada inválida
        std::cerr << "\e[0;31m[ERROR]\e[0m Entrada inválida. Por favor, inténtelo de nuevo.\n";

        // Limpiar el estado de error de std::cin
        std::cin.clear();
        // Ignorar los caracteres restantes en el búfer de entrada
        std::cin.ignore(256, '\n');

    } while (true);
}

// Función para validar el número de argumentos de la línea de comandos
inline void isArgumentValid(int argc, char *argv[], int expected) {
    // Verificar si el número de argumentos es el esperado
    if (argc != expected + 1) {
        // Mostrar mensaje de error en caso de argumentos incorrectos
        std::cerr << "\e[0;31m[ERROR]\e[0m Uso: " << argv[0] << " <archivo-entrada>\n";
        exit(1); // Finalizar el programa con un código de error
    }
}
