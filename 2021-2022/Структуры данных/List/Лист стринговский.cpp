#include <iostream>
using namespace std;

class node {
private:
	string _school_num;
	int _repets;
	node* _next;
public:
	void set_repets(int repets) { _repets = repets; }
	string school_num() { return _school_num; }
	node* next() { return _next; }
	int repets() { return _repets; }
	friend class list;
};

class list
{
private:
	node* _first;
	int _size;
public:
	node* first() { return _first; }
	int size() { return _size; }
	list() { _size = 0; _first = 0; }
	~list() {
		if (_first == 0)
			return;
		node* curr = _first;
		node* elem = _first->_next;
		while (elem != 0)
		{
			delete curr;
			curr = elem;
			elem = curr->_next;
		}
		delete curr;
		_first = 0;
	}

	node* create_node(string info)
	{
		node* el = new node;
		el->_school_num = info;
		el->_repets = 1;
		el->_next = 0;
		return el;
	}

	void print_list(node* first_)
	{
		node* curr = first_;
		while (curr != 0)
		{
			cout << curr->_school_num << " ";
			curr = curr->_next;
		}
		cout << "\n";
	}

	void push_front(string info)
	{
		node* new_el;
		new_el = create_node(info);
		new_el->_next = _first;
		_first = new_el;
		_size++;
	}

	void push_back(string info)
	{
		node* curr = _first;
		if (_first == 0)
			_first = create_node(info);
		else
		{
			while (curr->_next != 0)
				curr = curr->_next;
			node* new_el = create_node(info);
			curr->_next = new_el;
		}
		_size++;
	}

	void push_before(node* curr, string info)
	{
		node* temp = _first;
		if (curr == _first)
			push_front(info);
		while (temp->_next != curr)
			temp = temp->_next;
		node* new_el = create_node(info);
		new_el->_next = curr;
		temp->_next = new_el;
		_size++;
	}
};