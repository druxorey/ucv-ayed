#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"

// Función recursiva auxiliar para insertar un elemento al fondo de una pila.
// Concepto Teórico (Inserción en la Base de la Pila mediante Desapilado Temporal):
// Para insertar un elemento 'item' en la base de la pila sin usar otra pila auxiliar,
// desapilamos recursivamente todos los elementos superiores guardándolos en la pila de llamadas (call stack) 
// de C++ en la variable local 'temp'. Cuando la pila queda vacía (base), hacemos push del 'item' y 
// luego volvemos a apilar 'temp' conforme retorna la recursión.
template <typename T>
void insertAtBottom(DrxStack<T>& P, const T& item) {
    // Caso base: La pila está vacía. Es seguro colocar 'item' aquí, que ahora será el fondo de la pila.
    if (P.isEmpty()) {
        P.push(item);
        return;
    }

    // Paso recursivo:
    // 1. Guardar el tope actual en la variable local de la trama de activación 'temp' y desapilarlo.
    T temp = P.top();
    P.pop();

    // 2. Llamada recursiva para insertar el elemento en la subpila restante (hasta llegar al fondo).
    insertAtBottom(P, item);

    // 3. Restauración: Apilar de vuelta 'temp' encima del elemento recién insertado.
    P.push(temp);
}


// Función recursiva principal para invertir la pila utilizando únicamente la pila de ejecución.
// Concepto Teórico (Inversión por Retorno de Pila):
// Para invertir los elementos, desapilamos secuencialmente el tope actual y lo guardamos 
// en la variable 'item' de la pila de llamadas del sistema. Recursivamente invertimos la pila
// reducida. Al retornar del caso base (pila vacía), insertamos el 'item' al fondo de la pila 
// invertida mediante la función 'insertAtBottom'.
// Complejidad temporal: O(n^2) y complejidad espacial: O(n) por el uso de la pila de llamadas.
template <typename T>
void reverseStack(DrxStack<T>& P) {
    // Caso base: Una pila vacía ya está invertida. Detiene la recursión.
    if (P.isEmpty()) {
        return;
    }

    // 1. Desapilar el elemento del tope y guardarlo en la variable local de la llamada recursiva.
    T item = P.top();
    P.pop();

    // 2. Llamada recursiva: Invertir la subpila restante (tamaño n-1).
    reverseStack(P);

    // 3. Colocar el elemento que estaba en el tope en el fondo de la pila ya invertida.
    insertAtBottom(P, item);
}


int main() {
    std::cout << "\n\e[0;35m[========= E17-INVERTIR-PILA =========]\e[0m\n\n";

    DrxStack<int> myStack;
    
    std::cout << "Inicializando pila con valores (de fondo a tope): [1, 2, 3, 4, 5]\n";
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    std::cout << "\nEstado inicial de la pila:\n";
    myStack.print();

    reverseStack(myStack);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Estado de la pila invertida (de fondo a tope: [5, 4, 3, 2, 1]):\n";
    myStack.print();
    std::cout << "\n";

    return 0;
}
