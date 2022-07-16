#include <iostream>
#include <string.h>
#include "list.h"
using namespace std;

list::~list()
{
	if (first == 0)
		return;
	node* curr = first;
	node* elem = first->next;
	while (elem != 0)
	{
		delete curr;
		curr = elem;
		elem = curr->next;
	}
	delete curr;
	first = 0;
}

node* list::create_node(int info)
{
	node* el = new node;
	el->info = info;
	el->next = 0;
	return el;
}

void list::print_list(node* first_)
{
	node* curr = first_;
	while (curr != 0)
	{
		cout << curr->info << " ";
		curr = curr->next;
	}
	cout << endl;
}

void list::push_front(int info){
	node* new_el;
	new_el = create_node(info);
	new_el->next = first;
	first = new_el;
}

void list::push_back(int info){
	node* curr = first;
	if (first == 0)
		first = create_node(info);
	else
	{
		while (curr->next != 0)
			curr = curr->next;
		node* new_el = create_node(info);
		curr->next = new_el;
	}
}

void list::push_before(node* curr, int info)
{
	node* temp = first;
	if (curr == first)
		push_front(info);
	while (temp->next != curr)
		temp = temp->next;
	node* new_el = create_node(info);
	new_el->next = curr;
	temp->next = new_el;
}

void list::get_range(int idx, int count)
{
	int i = 0;
	node* temp = first;
	while (i != idx - 1) {
		temp = temp->next;
		i++;
	}
	print_list(temp);
}

bool condition(node* item)
{
	return item->info > 1;
}

int list::counter(bool (*f)(node*))
{
	int num = 0;
	node* temp = first;
	while (temp != 0)
	{
		if (f(temp) == 1)
			num++;
		temp = temp->next;
	}
	return num;
}

