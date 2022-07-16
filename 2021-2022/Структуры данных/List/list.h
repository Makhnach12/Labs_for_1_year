#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
using namespace std;

class node{
public:
    int info;
    node* next;
};

class list
{
private:
    node* first;
public:
    list() { first = 0; }
    void print_list(node* first_);
    node* create_node(int info);
    void push_back(int info);
    void push_before(node* curr, int info);
    void push_front(int info);
    void get_range(int idx, int count);
    int counter(bool (*f)(node*));
    ~list();
};

bool condition(node* item);

#endif
