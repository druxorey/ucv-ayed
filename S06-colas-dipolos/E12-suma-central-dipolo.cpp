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


// Función recursiva que viaja hacia el centro del dipolo desapilando los extremos.
// Concepto Teórico (Reducción Concéntrica e Involución en Deques):
// Un Dipolo permite extraer de ambos extremos en O(1). Para procesar elementos empezando desde el centro 
// hacia los extremos, diseñamos una recursión que en cada paso de ida "pela" los extremos (popFront y popBack) 
// reduciendo el tamaño en 2.
// - Al llegar al centro (cola vacía o con 1 solo elemento), iniciamos el retorno de la recursión (fase de vuelta).
// - Durante el retorno, los elementos se vuelven a colocar en sus extremos originales (pushFront y pushBack) 
//   para restaurar el dipolo.
// - La suma acumulativa se realiza en la fase de retorno, lo que garantiza que los elementos más cercanos 
//   al centro se sumen primero (de adentro hacia afuera).
void sumFromCenter(Deque& D, int N, int& elementsSummed, int& sum) {
    // Caso base 1: El dipolo está vacío (longitud par y terminamos de pelarlo). Retornamos.
    if (D.isEmpty()) {
        return;
    }

    // Caso base 2: Queda exactamente un elemento (longitud impar, el centro absoluto).
    // Lo extraemos, lo sumamos si cumple la cuota N, y lo restauramos.
    if (D.size() == 1) {
        int center = D.front();
        D.popFront();
        if (elementsSummed < N) {
            sum += center;
            elementsSummed++;
        }
        D.pushFront(center); // Restaurar el centro absoluto
        return;
    }

    // Paso recursivo (Fase de Ida - Deshojando el dipolo):
    // Extraemos los dos elementos en los extremos actuales del dipolo.
    int leftVal = D.front(); D.popFront();
    int rightVal = D.back(); D.popBack();

    // Llamada recursiva con el sub-dipolo restante (reducido en 2 elementos)
    sumFromCenter(D, N, elementsSummed, sum);

    // Fase de Retorno (Vuelta - Sumando del centro hacia afuera y restaurando):
    // Procesamos primero el elemento izquierdo y luego el derecho según la cuota de elementos a sumar N.
    if (elementsSummed < N) {
        sum += leftVal;
        elementsSummed++;
    }
    if (elementsSummed < N) {
        sum += rightVal;
        elementsSummed++;
    }

    // Restauración de los extremos correspondientes a este nivel del dipolo
    D.pushFront(leftVal);
    D.pushBack(rightVal);
}


int main() {
    std::cout << "\n\e[0;35m[========= E12-SUMA-CENTRAL-DIPOLO =========]\e[0m\n\n";

    Deque D;
    D.pushBack(1);
    D.pushBack(5);
    D.pushBack(6);
    D.pushBack(7);
    D.pushBack(3);

    std::cout << "Dipolo inicial: ";
    D.print();
    std::cout << "\n";

    int N = 3;
    int elementsSummed = 0;
    int sum = 0;

    sumFromCenter(D, N, elementsSummed, sum);

    std::cout << "\n\e[1;32m[RESULTADO]\e[0m Suma de los primeros " << N 
              << " elementos desde el centro hacia afuera: " << sum << "\n";
              
    std::cout << "Dipolo restaurado: ";
    D.print();
    std::cout << "\n\n";

    return 0;
}
