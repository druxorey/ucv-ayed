#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"

struct StackInfo {
    double sum;
    int count;
};


// Función recursiva que recorre la pila una sola vez para sumar y contar.
// Concepto Teórico (Reducción y Post-procesamiento Recursivo en Estructuras LIFO):
// Para calcular la media de una pila en una sola pasada y sin usar estructuras temporales, 
// delegamos la recolección de datos a la recursividad.
// Al desapilar (ida), almacenamos temporalmente los elementos en la pila de llamadas. 
// Al retornar (vuelta), sumamos el elemento y aumentamos el contador de forma acumulativa en la estructura 'StackInfo'.
// Finalmente, re-apilamos el elemento para restaurar la pila a su estado original.
StackInfo calculateAverageRecursive(DrxStack<int>& P) {
    // Caso base: La pila está vacía. Su suma es 0.0 y el contador de elementos es 0.
    if (P.isEmpty()) {
        return {0.0, 0};
    }

    // Paso recursivo (Fase de Ida):
    // Desapilamos el elemento del tope para guardarlo en la variable local del marco de activación.
    int element = P.top();
    P.pop();

    // Llamada recursiva para obtener la suma y cantidad de los elementos de la subpila restante.
    StackInfo subStackData = calculateAverageRecursive(P);

    // Fase de Retorno (Procesamiento y Acumulación):
    // Incorporamos el elemento actual a los datos consolidados retornados por el nivel inferior.
    subStackData.sum += element;
    subStackData.count++;

    // Restauración: Colocar de vuelta el elemento en la pila.
    P.push(element);

    return subStackData; // Devolver los datos acumulados al nivel superior
}


// Función envoltura (wrapper) que calcula y retorna el promedio.
double calculateAverage(DrxStack<int>& P) {
    StackInfo result = calculateAverageRecursive(P);
    
    if (result.count == 0) {
        return 0.0;
    }
    
    return result.sum / result.count;
}


int main() {
    std::cout << "\n\e[0;35m[========= E22-PROMEDIO-PILA =========]\e[0m\n\n";

    DrxStack<int> myStack;
    
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    std::cout << "Pila inicial (de fondo a tope: [10, 20, 30, 40, 50]):\n";
    myStack.print();

    double average = calculateAverage(myStack);

    printf("\n\e[1;32m[RESULTADO]\e[0m El promedio de los elementos de la pila es: %.2f\n", average);

    std::cout << "\nEstado final de la pila (verificando que se restauró):\n";
    myStack.print();
    std::cout << "\n";

    return 0;
}
