#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"

// Función recursiva que elimina elementos en posiciones específicas desde el fondo de la pila.
// Concepto Teórico (Eliminación Selectiva durante el Desapilado de Retorno):
// Para eliminar elementos en posiciones específicas sin usar estructuras auxiliares externas, 
// vaciamos la pila recursivamente (fase de ida), almacenando los elementos en las variables locales de la pila de llamadas.
// En la fase de retorno (unwinding), los elementos se procesan del fondo hacia el tope:
// - Llevamos la cuenta en 'counterFromBottom'.
// - Si la posición actual coincide con uno de los índices marcados para eliminación (posToRemove1 o posToRemove2),
//   simplemente omitimos volver a apilarlo (push). Al no reinsertarlo en la pila, el nodo queda efectivamente 
//   borrado y su memoria liberada por el ciclo de vida de la variable local.
void removeNodesRecursive(DrxStack<int>& P, int posToRemove1, int posToRemove2, int& counterFromBottom) {
    // Caso base: Pila vacía. Hemos vaciado la pila y alcanzado el fondo. 
    // Inicializamos el contador en 0 para iniciar la cuenta en el retorno.
    if (P.isEmpty()) {
        counterFromBottom = 0;
        return;
    }

    // Paso recursivo (Fase de Ida):
    // Desapilar el elemento superior y guardarlo en la variable local del marco de la llamada.
    int element = P.top();
    P.pop();

    // Seguir bajando recursivamente en la pila
    removeNodesRecursive(P, posToRemove1, posToRemove2, counterFromBottom);

    // Fase de Retorno (Fase de Vuelta):
    counterFromBottom++; // Incrementar conforme subimos de vuelta hacia el tope

    // Si la posición actual desde el fondo NO coincide con ninguna de las posiciones a eliminar,
    // restauramos el elemento en la pila. Si coincide, lo omitimos (eliminación física de la pila).
    if (counterFromBottom != posToRemove1 && counterFromBottom != posToRemove2) {
        P.push(element);
    } else {
        printf("  \e[1;31m[ELIMINANDO]\e[0m Elemento %d (posición %d desde el fondo)\n", element, counterFromBottom);
    }
}


// Función envoltura (wrapper)
void removeNodesAtPositions(DrxStack<int>& P, int P_pos, int d) {
    int counter = 0;
    int pos1 = P_pos;
    int pos2 = P_pos + d;
    removeNodesRecursive(P, pos1, pos2, counter);
}


int main() {
    std::cout << "\n\e[0;35m[========= E21-ELIMINAR-NODOS-PILA =========]\e[0m\n\n";

    DrxStack<int> myStack;
    
    myStack.push(10); // Posición 1 desde el fondo
    myStack.push(20); // Posición 2
    myStack.push(30); // Posición 3
    myStack.push(40); // Posición 4
    myStack.push(50); // Posición 5 (tope)

    std::cout << "Pila inicial (de fondo a tope: [10, 20, 30, 40, 50]):\n";
    myStack.print();

    int posP = 2; 
    int desD = 2; 

    std::cout << "\nEliminando nodos en posición P = " << posP << " y P + d = " << (posP + desD) 
              << " desde el fondo de la pila...\n";
              
    removeNodesAtPositions(myStack, posP, desD);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Estado final de la pila:\n";
    myStack.print();
    std::cout << "\n";

    return 0;
}
