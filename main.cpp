#include <iostream>

#include "Control.h"

void test();

void list(bool);

void sortedList();

void selector();

Monitor createMonitor();

int main() {
    selector();
    return 0;
}

void selector() {
    int op;
    std::cout << "Seleccione el tipo de lista que desea utilizar: " << std::endl
              << "1. Normal" << std::endl
              << "2. Ordenada" << std::endl;
    std::cin >> op;
    int isSorted = op == 2;
    list(isSorted);

    std::cout << "Desea cambiar de lista?" << std::endl << "1. Si" << std::endl << "2. No" << std::endl;
    std::cin >> op;
    op == 1 ? selector() : exit(0);
}

void list(bool isSorted) {
    LinkedList<Monitor> *monitores = new LinkedList<Monitor>();
    LinkedList<Monitor> *sorted = new LinkedList<Monitor>();
    Control *control = new Control(isSorted ? sorted : monitores);
    int op = 0;
    Monitor monitor;
    do {
        std::cout << "------BIENVENIDO------" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout
                << "1. Comprobar si la lista esta vacia" << std::endl
                << "2. Agregar Nodo" << std::endl
                << "3. Encontrar Nodo" << std::endl
                << "4. Eliminar Nodo" << std::endl
                << "5. Obtener datos" << std::endl
                << "6. Salir" << std::endl;
        std::cin >> op;
        switch (op) {
            case 1: {
                std::cout << "La lista esta: " << (control->isEmpty()?"Vacia":"Con objetos") << std::endl;
                break;
            }
            case 2: {
                if (!isSorted) {
                    int op2 = 0;
                    std::cout << "Seleccione una opcion:" << std::endl
                              << "1. Agregar nodo al inicio" << std::endl
                              << "2. Agregar nodo al final" << std::endl
                              << "3. Agregar nodo despues de un nodo" << std::endl
                              << "4. Agregar nodo antes de un nodo" << std::endl;
                    std::cin >> op2;
                    monitor = createMonitor();
                    switch (op2) {
                        case 1:
                            control->addNodeFirst(monitor);
                            std::cout << "Monitor agregado al inicio" << std::endl;
                            break;
                        case 2:
                            control->addNodeLast(monitor);
                            std::cout << "Monitor agregado al final" << std::endl;
                            break;
                        case 3: {
                            std::string id;
                            std::cout << "Ingrese el id del nodo: " << std::endl;
                            std::cin >> id;
                            if (control->addNodeAfter(id, monitor)) {
                                std::cout << "Nodo agregado despues del nodo con id " << id << std::endl;
                            } else {
                                std::cout << "Error al añadir nodo" << std::endl;
                            }
                            break;
                        }
                        case 4: {
                            std::string id;
                            std::cout << "Ingrese el id del nodo: " << std::endl;
                            std::cin >> id;
                            if (control->addNodeBefore(id, monitor)) {
                                std::cout << "Nodo agregado antes del nodo con id " << id << std::endl;
                            } else {
                                std::cout << "Error al añadir nodo" << std::endl;
                            }
                            break;
                        }
                        default:
                            std::cout << "Opcion invalida, volviendo al menu" << std::endl;
                            break;
                    }
                } else {
                    monitor = createMonitor();
                    control->addNodeSorted(monitor);
                    std::cout << "Nodo agregado ordenado" << std::endl;
                }
                break;
            }
            case 3: {
                int op2 = 0;
                std::cout << "Seleccione una opcion:" << std::endl
                          << "1. Encontrar nodo" << std::endl
                          << "2. Ver la informacion de un nodo" << std::endl;
                std::cin >> op2;
                std::string id;
                switch (op2) {
                    case 1: {
                        std::cout << "Ingrese el id del nodo:" << std::endl;
                        std::cin >> id;
                        std::cout << control->findNode(id) << std::endl;
                    }
                        break;
                    case 2:
                        std::cout << "Ingrese el id del nodo:" << std::endl;
                        std::cin >> id;
                        std::cout << control->findInfo(id);
                        break;
                    default:
                        std::cout << "Opcion invalida" << std::endl;
                        break;
                }
                break;
            }
            case 4: {
                std::string id;
                std::cout << "Ingrese el id de nodo a eliminar" << std::endl;
                std::cin >> id;
                std::cout << control->deleteNode(id) << std::endl;

            }
                break;
            case 5: {
                int op2 = 0;
                std::cout << "Seleccione una opcion:" << std::endl
                          << "1. Obtener toda la lista" << std::endl
                          << "2. Obtener el tamaño de la lista" << std::endl
                          << "3. Obtener el objeto por id" << std::endl
                          << "4. Obtener el primer nodo" << std::endl
                          << "4. Obtener el ultimo nodo" << std::endl;
                std::cin >> op2;
                switch (op2) {
                    case 1: {
                        int op3;
                        std::cout << "Selecciona como desea obtener a lista:  " << std::endl
                                  << "1. De arriba hacia abajo" << std::endl
                                  << "2. De abajo hacia arriba" << std::endl;
                        std::cin >> op3;
                        if (op3 != 1 and op3 != 2) {
                            std::cout << "Opcion no valida" << std::endl;
                        }
                        std::cout << control->getList(op3) << std::endl;
                        break;
                    }
                    case 2:
                        std::cout << "El tamaño de la lista es " << control->getSize() << std::endl;
                        break;
                    case 3: {
                        int id;
                        std::cout << "Ingrese el indice del objeto que desea obtener: " << std::endl;
                        std::cin >> id;
                        Monitor *mon = control->getObject(id);
                        if (mon != NULL) {
                            std::cout << "El objeto es " << mon << std::endl;
                        } else {
                            std::cout << "No se ha encontrado el objeto" << std::endl;
                        }
                        break;
                    }
                    case 4: {
                        std::cout << "El primer elemento es" << control->getFirst() << std::endl;
                        break;
                    }
                    case 5: {
                        std::cout << "El ultimo elemento es" << control->getLast() << std::endl;
                        break;
                    }
                }
                break;
            }
            case 6:
                break;
            default:
                std::cout << "Opcion no valida, intentelo nuevamente" << std::endl;
                break;
        }
    } while (op != 6);
}

Monitor createMonitor() {
    std::string brand;
    std::string color;
    std::string id;
    int inches;
    double refreshRate;
    std::cout << "Ingrese el id del monitor: " << std::endl;
    std::cin >> id;
    std::cout << "Ingrese la marca del monitor: " << std::endl;
    std::cin >> brand;
    std::cout << "Ingrese el color del monitor: " << std::endl;
    std::cin >> color;
    std::cout << "Ingrese las pulgadas del monitor: " << std::endl;
    std::cin >> inches;
    std::cout << "Ingrese los hz del monitor: " << std::endl;
    std::cin >> refreshRate;
    return Monitor(brand, color, id, inches, refreshRate);
}

