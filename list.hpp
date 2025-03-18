#include <iostream>

struct Node {
    int value;
    std::shared_ptr<Node> next = nullptr;
};

struct List {
    std::shared_ptr<Node> first_node = nullptr;
    size_t size = 0;
};

/*
 *
 */
std::shared_ptr<Node> create_node(int value);

/*
 *
 */
void push_front(int value, std::shared_ptr<List>& list);

/*
 *
 */
void push_back(int value, std::shared_ptr<List>& list);

/*
 *
 */
void insert(int value, std::shared_ptr<List>& list, const int i);

/*
 *
 */
void erase(std::shared_ptr<List>& list, const int i);

/*
 *
 */
void print_list(std::shared_ptr<List>& list);
