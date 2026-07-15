#include <iostream>
#include "../S99-implementaciones/drxstack.hpp"

// Clase que administra el historial de comandos deshacer/rehacer (HistoryManager).
class HistoryManager {
private:
    DrxStack<const char*> undoStack;
    DrxStack<const char*> redoStack;

public:
    // Al registrar un nuevo evento/acción, se vacía la pila de rehacer.
    // Concepto Teórico (Inserción de Nueva Acción e Invalidación de Redo):
    // Cuando el usuario realiza una nueva acción, se apila en 'undoStack'. 
    // Al mismo tiempo, se vacía la pila 'redoStack' (redoStack.clear()). Esto se debe a que, en el modelo
    // clásico de Undo/Redo, introducir una nueva acción en la línea de tiempo invalida cualquier acción 
    // que se haya deshecho previamente (se ramifica la historia y se pierde el futuro lineal).
    void recordAction(const char* action) {
        undoStack.push(action);
        redoStack.clear(); // Limpiar el historial de rehacer
        std::cout << "Acción realizada: \"" << action << "\"\n";
    }


    // Deshacer (Undo): Pasa la acción al historial de rehacer.
    // Concepto Teórico (Deshacer con Transferencia LIFO):
    // Deshacer una acción significa revertir el último comando realizado (LIFO). 
    // Extraemos la acción más reciente del tope de 'undoStack' (pop) y la transferimos a 'redoStack' (push),
    // de modo que quede disponible para ser rehecha si el usuario lo solicita.
    void undo() {
        if (undoStack.isEmpty()) {
            std::cout << "\e[1;31m[ERROR]\e[0m Nada que deshacer.\n";
            return;
        }
        const char* action = undoStack.top(); // Obtener la última acción
        undoStack.pop();                      // Sacarla de la pila de deshacer
        redoStack.push(action);               // Colocarla en la de rehacer (para futuro redo)
        std::cout << "Deshecho: \"" << action << "\"\n";
    }


    // Rehacer (Redo): Vuelve a aplicar la acción deshecha.
    // Concepto Teórico (Rehacer con Transferencia LIFO):
    // Rehacer es la operación inversa de deshacer: vuelve a aplicar el último comando que fue deshecho.
    // Extraemos la acción deshecha más recientemente del tope de 'redoStack' (pop) y la transferimos
    // de vuelta a 'undoStack' (push) para reincorporarla en la línea de tiempo activa.
    void redo() {
        if (redoStack.isEmpty()) {
            std::cout << "\e[1;31m[ERROR]\e[0m Nada que rehacer.\n";
            return;
        }
        const char* action = redoStack.top(); // Obtener la última acción deshecha
        redoStack.pop();                      // Sacarla de la pila de rehacer
        undoStack.push(action);               // Colocarla de vuelta en la de deshacer
        std::cout << "Rehecho: \"" << action << "\"\n";
    }


    void showStatus() const {
        std::cout << "  [Pila Deshacer (Tope a Fondo)]: ";
        if (undoStack.isEmpty()) std::cout << "vacía";
        else {
            DrxStack<const char*> temp = undoStack;
            while (!temp.isEmpty()) {
                std::cout << "[" << temp.top() << "] ";
                temp.pop();
            }
        }
        std::cout << "\n  [Pila Rehacer (Tope a Fondo)]: ";
        if (redoStack.isEmpty()) std::cout << "vacía";
        else {
            DrxStack<const char*> temp = redoStack;
            while (!temp.isEmpty()) {
                std::cout << "[" << temp.top() << "] ";
                temp.pop();
            }
        }
        std::cout << "\n\n";
    }
};


int main() {
    std::cout << "\n\e[0;35m[========= E09-DESHACER-REHACER =========]\e[0m\n\n";

    HistoryManager manager;
    manager.recordAction("Escribir párrafo 1");
    manager.recordAction("Insertar imagen");
    manager.recordAction("Cambiar color fuente");
    manager.showStatus();

    std::cout << "Ejecutando Deshacer...\n";
    manager.undo();
    manager.showStatus();

    std::cout << "Ejecutando Deshacer...\n";
    manager.undo();
    manager.showStatus();

    std::cout << "Ejecutando Rehacer...\n";
    manager.redo();
    manager.showStatus();

    return 0;
}
