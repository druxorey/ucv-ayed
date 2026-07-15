#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"

// Función recursiva que vacía la pila, asocia a pares desde el fondo y los suma.
// Concepto Teórico (Emparejamiento de Elementos desde el Fondo mediante Desapilado y Retorno Recursivo):
// Para agrupar y sumar los elementos por parejas comenzando desde el fondo de la pila, desapilamos toda la pila
// recursivamente. Al llegar al fondo (caso base), empezamos a retornar y emparejar de abajo hacia arriba:
// - Si 'hasPending' es false, el elemento actual 'element' es el primero de una pareja. Lo retenemos 
//   temporalmente en 'firstElementOfPair' y marcamos 'hasPending = true'.
// - Si 'hasPending' es true, el elemento actual es el segundo de la pareja. Calculamos la suma de ambos
//   y hacemos 'push(suma)' de vuelta a la pila.
void sumPairsRecursive(DrxStack<int>& P, int& firstElementOfPair, bool& hasPending) {
    // Caso base: Pila vacía. Hemos alcanzado el fondo de la pila.
    // Inicializamos la bandera indicando que no hay ningún miembro de pareja pendiente.
    if (P.isEmpty()) {
        hasPending = false;
        return;
    }

    // Paso recursivo (Fase de Ida):
    // Extraer el elemento actual y guardarlo en la variable local de la llamada recursiva.
    int element = P.top();
    P.pop();

    // Seguir profundizando recursivamente
    sumPairsRecursive(P, firstElementOfPair, hasPending);

    // Fase de Retorno (Fase de Vuelta - Agrupación desde el fondo):
    if (!hasPending) {
        // Guardar el primer elemento de la pareja
        firstElementOfPair = element;
        hasPending = true;
    } else {
        // Encontramos la pareja: calcular suma y apilar el resultado acumulado
        int sum = firstElementOfPair + element;
        P.push(sum);
        hasPending = false; // Resetear bandera para la siguiente pareja
    }
}


// Función envoltura (wrapper)
void sumStackPairs(DrxStack<int>& P) {
    int temp = 0;
    bool hasPending = false;
    sumPairsRecursive(P, temp, hasPending);
    
    if (hasPending) {
        P.push(temp); // Si era cantidad impar, re-apilar el último huérfano
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E23-SUMA-PARES-PILA =========]\e[0m\n\n";

    DrxStack<int> myStack;
    
    myStack.push(1); // Fondo
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5); // Tope

    std::cout << "Pila inicial (de fondo a tope: [1, 2, 3, 4, 5]):\n";
    myStack.print();

    sumStackPairs(myStack);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Pila después de sumar a pares (esperado: [3, 7, 5]):\n";
    myStack.print();
    std::cout << "\n";

    return 0;
}
