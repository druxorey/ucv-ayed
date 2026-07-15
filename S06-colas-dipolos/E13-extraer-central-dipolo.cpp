#include <iostream>
#include "../S99-implementaciones/drxlist.hpp"

// Abstracción básica de Dipolo usando lista doblemente enlazada (Deque).
class Deque {
private:
    DrxList<int> list;

public:
    void pushFront(int val) {
        list.pushFront(val);
    }


    void pushBack(int val) {
        list.pushBack(val);
    }


    void popFront() {
        if (!isEmpty()) list.deleteNode(list.first());
    }


    void popBack() {
        if (!isEmpty()) list.deleteNode(list.last());
    }


    int front() {
        return *list.get(list.first());
    }


    int back() {
        return *list.get(list.last());
    }


    bool isEmpty() const {
        return list.isEmpty();
    }


    int size() const {
        return list.size();
    }
    

    void print() const {
        typename DrxList<int>::Iterator it = list.first();
        std::cout << "[ ";
        while (it != list.end()) {
            std::cout << *list.get(it) << " ";
            list.next(it);
        }
        std::cout << "]";
    }
};


// Función recursiva que remueve el/los elemento(s) central(es) de un dipolo.
// Concepto Teórico (Detección de Centro e Inducción de Paridad con Retorno de Señal):
// Extraer el centro de un dipolo requiere diferenciar dinámicamente si la longitud es par o impar.
// - Si es Impar: El centro es un elemento único. Se detecta cuando D.size() == 1. Se remueve y se retorna 'false'
//   para indicar que los elementos de niveles superiores (los bordes) NO deben ser eliminados.
// - Si es Par: El centro consta de dos elementos. Al "pelar" el dipolo de dos en dos, terminamos en D.isEmpty() (tamaño 0).
//   Retornamos 'true' para indicarle al nivel inmediato superior (que tiene los dos elementos centrales) 
//   que debe eliminarlos (no re-apilarlos). Dicho nivel remueve sus extremos y retorna 'false' para salvar a los niveles de más arriba.
bool extractCentersRecursive(Deque& D) {
    // Caso base Par: El dipolo original tenía longitud par.
    // Llegamos al final absoluto sin elementos centrales únicos. Retornamos true
    // para ordenar al padre inmediato que descarte sus dos extremos.
    if (D.isEmpty()) {
        return true;
    }

    // Caso base Impar: El dipolo original tenía longitud impar.
    // Llegamos a un elemento único central. Lo extraemos (popFront) y retornamos false
    // para indicar a los padres que no descarten sus extremos.
    if (D.size() == 1) {
        std::cout << "  Elemento central extraído: " << D.front() << "\n";
        D.popFront(); // Borrar el centro único
        return false; // Evitar que los niveles superiores eliminen sus extremos
    }

    // Paso recursivo (Fase de Ida - Remoción de bordes):
    int leftVal = D.front(); D.popFront();
    int rightVal = D.back(); D.popBack();

    // Llamada recursiva con el sub-dipolo restante
    bool discardEdges = extractCentersRecursive(D);

    // Fase de Retorno (Fase de Vuelta):
    // Si la llamada hija devolvió 'true', significa que el nivel inferior era el caso base vacío,
    // por lo tanto, los elementos de este nivel (leftVal y rightVal) son los dos centros de la lista par.
    // Los imprimimos y NO los reinsertamos (eliminación física).
    if (discardEdges) {
        std::cout << "  Elementos centrales extraídos (par): " << leftVal << " y " << rightVal << "\n";
        return false; // Retornamos false para salvar a los niveles superiores
    }

    // Si 'discardEdges' es false, estos elementos no son el centro.
    // Los reinsertamos en sus extremos correspondientes para restaurar la integridad del resto del dipolo.
    D.pushFront(leftVal);
    D.pushBack(rightVal);
    return false; // Indicar que no se deben borrar más elementos
}


int main() {
    std::cout << "\n\e[0;35m[========= E13-EXTRAER-CENTRAL-DIPOLO =========]\e[0m\n\n";

    // Prueba Caso Impar
    Deque D1;
    D1.pushBack(5);
    D1.pushBack(3);
    D1.pushBack(8); // Central
    D1.pushBack(1);
    D1.pushBack(6);

    std::cout << "Caso Impar Inicial: "; D1.print(); std::cout << "\n";
    extractCentersRecursive(D1);
    std::cout << "\e[1;32m[RESULTADO]\e[0m Caso Impar Final: "; D1.print(); std::cout << "\n\n";

    // Prueba Caso Par
    Deque D2;
    D2.pushBack(5);
    D2.pushBack(3);
    D2.pushBack(8); // Central 1
    D2.pushBack(9); // Central 2
    D2.pushBack(1);
    D2.pushBack(6);

    std::cout << "Caso Par Inicial: "; D2.print(); std::cout << "\n";
    extractCentersRecursive(D2);
    std::cout << "\e[1;32m[RESULTADO]\e[0m Caso Par Final: "; D2.print(); std::cout << "\n\n";

    return 0;
}
