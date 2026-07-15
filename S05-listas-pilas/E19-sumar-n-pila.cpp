#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"

// Función recursiva que vacía la pila, cuenta y suma los N primeros elementos desde el fondo.
// Concepto Teórico (Recorrido Inverso en Pilas mediante Retorno de Recursión):
// Las pilas tienen acceso directo únicamente al tope. Para acceder al fondo, debemos desapilar todo.
// Al desapilar recursivamente, los elementos quedan guardados en las tramas de la pila de llamadas (call stack).
// Al llegar al caso base (pila vacía), estamos en el "fondo". Al retornar (fase de desapilado o retorno),
// los elementos se procesan en orden inverso (del fondo hacia el tope).
// Esto nos permite llevar un contador 'counterFromBottom' que se incrementa en el retorno, 
// sumar los primeros N elementos desde el fondo y luego volver a apilarlos (push) para restaurar el estado original.
void sumFromBottomRecursive(DrxStack<int>& P, int N, int& counterFromBottom, int& sum) {
    // Caso base: La pila está vacía. Hemos llegado más allá del fondo de la pila.
    // Inicializamos el contador desde el fondo en 0 para iniciar la cuenta en el retorno.
    if (P.isEmpty()) {
        counterFromBottom = 0;
        return;
    }

    // Paso recursivo (Fase de Ida):
    // Desapilamos el elemento del tope para guardarlo en la variable local 'element' de la pila de llamadas
    int element = P.top();
    P.pop();

    // Seguir desapilando recursivamente hasta vaciar la pila
    sumFromBottomRecursive(P, N, counterFromBottom, sum);

    // Fase de Retorno (Fase de Vuelta - Procesamiento desde el fondo):
    counterFromBottom++; // Al volver, cada nivel representa un elemento más lejos del fondo

    // Si la distancia desde el fondo es menor o igual a N, sumamos este elemento
    if (counterFromBottom <= N) {
        sum += element;
    }

    // Restauración: Volvemos a colocar el elemento en la pila para dejarla en su estado inicial
    P.push(element);
}


// Función envoltura (wrapper)
int sumNFromBottom(DrxStack<int>& P, int N) {
    int counter = 0;
    int sum = 0;
    sumFromBottomRecursive(P, N, counter, sum);
    return sum;
}


int main() {
    std::cout << "\n\e[0;35m[========= E19-SUMAR-N-PILA =========]\e[0m\n\n";

    DrxStack<int> myStack;
    
    myStack.push(2); // Fondo
    myStack.push(4);
    myStack.push(6);
    myStack.push(8); // Tope

    std::cout << "Pila inicial (de fondo a tope: [2, 4, 6, 8]):\n";
    myStack.print();

    int n;
    std::cout << "\nIngrese el número N de elementos a sumar desde el fondo: ";
    if (!(std::cin >> n)) return 1;

    if (n < 0 || n > myStack.size()) {
        std::cerr << "\e[1;31m[ERROR]\e[0m N debe estar entre 0 y el tamaño de la pila (" << myStack.size() << ").\n\n";
        return 1;
    }

    int result = sumNFromBottom(myStack, n);

    printf("\n\e[1;32m[RESULTADO]\e[0m La suma de los %d primeros elementos desde el fondo es: %d\n", n, result);
    
    std::cout << "\nEstado final de la pila (verificando que se haya restaurado):\n";
    myStack.print();
    std::cout << "\n";

    return 0;
}
