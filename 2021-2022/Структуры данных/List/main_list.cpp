#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	int num, info = 0, idx =0, count = 0;
	cin >> num;
	list my_list;
	node my_node;
	for (int i = 0; i < num; i++){
		cin >> my_node.info;
		my_list.push_back(my_node.info);
	}
	cin >> idx >> count;
	my_list.get_range(idx, count);
	int count_good_num = my_list.counter(condition);
	cout << count_good_num;
	return 0;
}