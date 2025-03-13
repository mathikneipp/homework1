#include <iostream>
#include <memory>

struct Node {
    int value;
    std::shared_ptr<Node> next = nullptr;
};

struct List {
    std::shared_ptr<Node> first_node = nullptr;
    size_t size = 0;
};

std::shared_ptr<Node> create_node(int value) {
    auto node = std::make_shared<Node>();
    node->value = value;
    return node;

}

void push_front(int value, std::shared_ptr<List>& list) {
    auto new_node = create_node(value);
    new_node->next = std::move(list->first_node);
    list->first_node = std::move(new_node);
    list->size++;
}

void push_back(int value, std::shared_ptr<List>& list) {
    auto new_node = create_node(value);
    if (list->size == 0) {
        list->first_node = new_node;
    } else {
        {
            auto current = list->first_node;
            for (int i = 0; i < (int) list->size - 1; i++) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    list->size++;
}

void insert(int value, std::shared_ptr<List>& list, const int i) {
    if (i < 0) {
        std::cout << "El índice es inválido." << std::endl;
        return;
    }
    if (list->size == 0 || i == 0) {
        push_front(value, list);
        return;
    } 
    if (i >= (int) list->size - 1) {
        if (i > (int) list->size) std::cout << "El indice es mayor al largo de la lista." << std::endl;
        push_back(value, list);
        return;
    }
    auto current = list->first_node;
    for (int j = 0; j < i - 1; j++) {
        current = current->next;
    }
    auto new_node = create_node(value);
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
}

void erase(std::shared_ptr<List>& list, const int i) {
    if (i < 0) {
        std::cout << "El índice es inválido." << std::endl;
        return;
    }
    if (list->size == 0) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    if (i == 0) {
        auto node_to_delete = list->first_node;
        if (list->size > 1) list->first_node = node_to_delete->next;
        node_to_delete.reset();
        list->size--;
        return;
    } 
    auto current = list->first_node;
    int index = i;
    if (i >= (int) list->size) index = list->size - 1;
    for (int j = 0; j < index - 1; j++) {
        current = current->next;
    }
    auto node_to_delete = current->next;
    current->next = node_to_delete->next;
    node_to_delete.reset();
    list->size--;
}

void print_list(std::shared_ptr<List>& list) {
    if (list->size == 0) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    auto current = list->first_node;
    std::cout << current->value;
    for (int j = 0; j < (int) list->size - 1; j++) {
        std::cout << " -> ";
        current = current->next;
        std::cout << current->value;
    }
    std::cout << std::endl;
}

int main() {
    auto list = std::make_shared<List>();

    push_back(1, list);
    push_back(2, list);
    push_back(3, list);
    push_front(4, list);
    insert(5, list, 1);

    std::cout << "Lista después de inserciones:" << std::endl;
    print_list(list);
    std::cout << "El tamaño de la lista es: " << list->size << std::endl;

    erase(list, 2);
    std::cout << "Lista después de borrar el índice 2:" << std::endl;
    print_list(list);
    std::cout << "El tamaño de la lista es: " << list->size << std::endl;

    erase(list, 6);
    std::cout << "Lista después de borrar un índice > a list->size:" << std::endl;
    print_list(list);
    std::cout << "El tamaño de la lista es: " << list->size << std::endl;

    return 0;
}
