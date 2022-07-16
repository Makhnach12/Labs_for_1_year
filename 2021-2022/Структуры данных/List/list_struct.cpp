#include <iostream>
using namespace std;

struct node
{
	int info;
	node* next;
};

node* create_node(int info)
{
	node* el = new node;
	el->info = info;
	el->next = 0;
	return el;
}

void push_front(int info, node** first)
{
	node* new_el;
	new_el = create_node(info);
	new_el->next = *first;
	*first = new_el;
}

void print_list(node* first)
{
	node* curr = first;
	while (curr != 0)
	{
		cout << curr->info << " ";
		curr = curr->next;
	}
	cout << endl;
}

void push_back(int info, node** first)
{
	node* curr = *first;
	if (*first == 0)
		*first = create_node(info);
	else
	{
		while (curr->next != 0)
			curr = curr->next;
		node* new_el = create_node(info);
		curr->next = new_el;
	}
}

void push_before(node** first, node* curr, int info)
{
	node* temp = *first;
	if (curr == *first)
		push_front(info, first);
	while (temp->next != curr)
		temp = temp->next;
	node* new_el = create_node(info);
	new_el->next = curr;
	temp->next = new_el;
}

void get_range(int idx, int count, node* first)
{
	int i = 0;
	node* temp = first;
	while (i != idx){
		temp = temp->next;
		i++;
	}
		print_list(temp);
}

bool condition(node* item)
{
	return item->info > 1;
}

int counter(node* first, bool (*f)(node*))
{
	int num = 0;
	node* temp = first;
	while (temp != 0)
	{
		if (f(temp))
			num++;
		temp = temp->next;
	}
	return num;
}

int main()
{
	int num, info = 0, idx =0, count = 0;
	cin >> num;
	node* list = create_node(info);
	for (int i = 0; i < num; i++)
	{
		cin >> info;
		push_back(info, &list);
	}
	cin >> idx >> count;
	get_range(idx, count, list);
	int count_good_num = counter(list, condition);
	cout << count_good_num;
	return 0;
}