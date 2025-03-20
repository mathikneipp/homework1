#include "list.h"
#include <iostream>
#include <memory>

std::shared_ptr<Node> create_node(int value) {
    auto node = std::make_shared<Node>(); // Creo un shared pointer al nodo.
    node->value = value; // Asigna el valor al nodo.
    return node;

}

void push_front(int value, std::shared_ptr<List>& list) {
    auto new_node = create_node(value);
    new_node->next = std::move(list->first_node); // Asigno como siguiente nodo del nuevo que se creo al primer nodo de la lista
    list->first_node = std::move(new_node);  // Asigno como primer nodo de la lista al creado
    list->size++; // Aumento en 1 el tamano de la lista
}

void push_back(int value, std::shared_ptr<List>& list) {
    auto new_node = create_node(value);
    if (list->size == 0) { // Si la lista esta vacia, lo asigno como primer nodo.
        list->first_node = new_node; 
    } else {
        auto current = list->first_node;
        for (int i = 0; i < (int) list->size - 1; i++) { // Recorro la lista hasta llegar a la ultima posicion.
            current = current->next;
        }
        current->next = new_node; // Asigno como siguiente nodo del anterior ultimo, al creado.
    }
    list->size++; // Aumento en 1 el tamano de la lista.
}

void insert(int value, std::shared_ptr<List>& list, const int i) {
    if (i < 0) { // Si se pide un indice menor a 0
        std::cout << "El índice es inválido." << std::endl; 
        return;
    }
    if (list->size == 0 || i == 0) { // En caso de que no haya ningun elemento en la lista o el indice sea el 0.
        push_front(value, list); 
        return;
    } 
    if (i > (int) list->size - 1) { // En caso de que el indice sea mayor al ultimo de la lista.
        if (i > (int) list->size) std::cout << "AVISO: El indice es mayor al largo de la lista." << std::endl; // En caso de que sea mayor, lo avisa.
        push_back(value, list);
        return;
    }
    auto current = list->first_node;
    for (int j = 0; j < i - 1; j++) { // Si esta entre medio de la lista, la recorro hasta la pos y lo inserto.
        current = current->next;
    }
    auto new_node = create_node(value);
    new_node->next = current->next;
    current->next = new_node;
    list->size++; // Aumento en 1 el tamano de la lista
}

void erase(std::shared_ptr<List>& list, const int i) {
    if (i < 0) { // Si se pide un indice menor a 0.
        std::cout << "El índice es inválido." << std::endl;
        return;
    }
    if (list->size == 0) { // Caso de que no haya ningun elemento para borrar.
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    if (i == 0) { // Caso de que haya que borrar el primer elemento de la lista.
        auto node_to_delete = list->first_node;
        if (list->size > 1) list->first_node = node_to_delete->next;
        list->size--; // Disminuye en 1 el tamano de la lista.
        return;
    } 
    auto current = list->first_node;
    int index = i;
    if (i >= (int) list->size) {
        index = list->size - 1; // En caso de que el indice sea mayor al rango de la lista, se lo asigna al ultimo elemento.
        std::cout << "AVISO: El indice es mayor al largo de la lista." << std::endl;
    }
    for (int j = 0; j < index - 1; j++) { // Recorro la lista hasta la pos y borro el elemento.
        current = current->next;
    }
    auto node_to_delete = current->next;
    current->next = node_to_delete->next;
    list->size--; // Disminuye en 1 el tamano de la lista.
}

void print_list(std::shared_ptr<List>& list) {
    if (list->size == 0) { // En caso de que la lista este vacia.
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    auto current = list->first_node;
    std::cout << current->value;
    for (int j = 0; j < (int) list->size - 1; j++) { // Recorre la lista imprimiendo los nodos entre ->
        std::cout << " -> ";
        current = current->next;
        std::cout << current->value;
    }
    std::cout << std::endl;
}

// Compilar y ejecutar con make run_list
int main() {
    auto list = std::make_shared<List>();

    push_back(1, list);
    push_back(2, list);
    push_back(3, list);
    push_front(4, list);
    insert(5, list, 1);
    insert(6, list, 4);

    std::cout << "Lista después de las inserciones:" << std::endl;
    print_list(list);
    std::cout << "El tamaño de la lista es: " << list->size << std::endl << std::endl;;

    erase(list, 2);
    std::cout << "Lista después de borrar el índice 2:" << std::endl;
    print_list(list);
    std::cout << "El tamaño de la lista es: " << list->size << std::endl << std::endl;;

    insert(7, list, 10);
    std::cout << "Lista después de insertar en un índice > a list->size:" << std::endl;
    print_list(list);
    std::cout << "El tamaño de la lista es: " << list->size << std::endl << std::endl;;

    erase(list, 6);
    std::cout << "Lista después de borrar un índice > a list->size:" << std::endl;
    print_list(list);
    std::cout << "El tamaño de la lista es: " << list->size << std::endl;

    return 0;
}
