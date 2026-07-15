#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Elimina todos los elementos duplicados de la lista de forma in-place.
// Elimina todos los elementos duplicados de la lista de forma in-place.
// Concepto Teórico (Eliminación In-Place de Duplicados en Colecciones No Ordenadas):
// Para eliminar duplicados sin usar memoria adicional (como tablas hash), recurrimos a un 
// enfoque de doble bucle de complejidad O(n^2) en tiempo y O(1) en espacio auxiliar.
// - El iterador externo 'baseNumber' fija un elemento de referencia.
// - El iterador interno 'comparator' recorre la sublista restante buscando coincidencia de valor.
void removeDuplicates(DrxList<int>& dataList) {
    typename DrxList<int>::Iterator baseNumber = dataList.first();
    
    // Bucle externo: fija el elemento de comparación base
    while (baseNumber != dataList.end()) {
        typename DrxList<int>::Iterator comparator = baseNumber;
        dataList.next(comparator); // El comparador empieza en el siguiente nodo

        // Bucle interno: escanea la lista restante en busca de duplicados
        while (comparator != dataList.end()) {
            int* baseVal = dataList.get(baseNumber);
            int* compVal = dataList.get(comparator);

            // Si los valores coinciden, el elemento apuntado por 'comparator' es un duplicado
            if (baseVal != nullptr && compVal != nullptr && *baseVal == *compVal) {
                // Resguardo de Iterador (Crucial en Modificación de Listas):
                // Eliminar un nodo invalida el iterador que lo apunta. Para continuar el recorrido
                // de forma segura, primero copiamos el iterador a borrar ('toDelete'), avanzamos 
                // el iterador 'comparator' al siguiente nodo válido, y finalmente eliminamos 'toDelete'.
                typename DrxList<int>::Iterator toDelete = comparator;
                dataList.next(comparator);
                dataList.deleteNode(toDelete); // Libera memoria y reestructura enlaces del nodo duplicado
            } else {
                dataList.next(comparator); // Avanzar normalmente si no es duplicado
            }
        }
        dataList.next(baseNumber); // Avanzar la base al siguiente elemento de la lista
    }
}


int main() {
    std::cout << "\n\e[0;35m[========= E12-ELIMINAR-DUPLICADOS =========]\e[0m\n\n";

    DrxList<int> myList;

    std::cout << "\e[0;33mLista original\e[0m: [ ";
    // Insertar algunos duplicados a propósito
    myList.pushBack(10);
    myList.pushBack(20);
    myList.pushBack(10);
    myList.pushBack(30);
    myList.pushBack(20);

    typename DrxList<int>::Iterator it = myList.first();
    while (it != myList.end()) {
        int* val = myList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        myList.next(it);
    }
    std::cout << "]\n";

    removeDuplicates(myList);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Lista sin duplicados: [ ";
    it = myList.first();
    while (it != myList.end()) {
        int* val = myList.get(it);
        if (val != nullptr) std::cout << *val << " ";
        myList.next(it);
    }
    std::cout << "]\n\n";

    return 0;
}
