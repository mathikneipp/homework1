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

/*
 * Crea un nodo con un shared pointer y lo devuelve.
 */
std::shared_ptr<Node> create_node(int value);

/*
 * Inserta un nodo al frente de la lista.
 */
void push_front(int value, std::shared_ptr<List>& list);

/*
 * Inserta un nodo al final de la lista.
 */
void push_back(int value, std::shared_ptr<List>& list);

/*
 * Inserta un nodo en el lugar indicado, si se le pasa un indice mayor al largo de la lista,
 * lo inserta al final y avisa lo ocurrido.
 */
void insert(int value, std::shared_ptr<List>& list, const int i);

/*
 * Borra el nodo del lugar indicado, si se le pasa un indice mayor al largo de la lista,
 * borra el nodo final y avisa lo ocurrido.
 */
void erase(std::shared_ptr<List>& list, const int i);

/*
 * Imprime la lista completa, separando el valor en cada nodo con “->”.
 */
void print_list(std::shared_ptr<List>& list);
