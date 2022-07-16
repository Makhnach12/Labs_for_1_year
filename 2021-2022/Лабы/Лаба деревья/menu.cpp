#include <iostream>
#include <string.h>
#include <fstream>
#include "Checkers.h"
#include "menu.h"
#include "Tree.h"
using namespace std;

void write_menu() {
	cout << "1" << "-" << "build tree by your info in console" << "\n";
	cout << "2" << "-" << "build tree by your info in file" << "\n";
	cout << "3" << "-" << "write tree" << "\n";
	cout << "4" << "-" << "add one node" << "\n";
	cout << "5" << "-" << "delete node" << "\n";
	cout << "6" << "-" << "find node" << "\n";
	cout << "7" << "-" << "change node" << "\n";
	cout << "8" << "-" << "write <<good>> students " << "\n";
	cout << "9" << "-" << "write students from one group" << "\n";
	cout << "10" << "-" << "write tree on lvl" << "\n";
	cout << "11" << "-" << "stop please)" << "\n";
} 

void build_tree(tree<student>& tree) {
	int num;
	student obj;
	cout << "Nodes num: " << "\n";
	num = ch_neg_nums();
	cout << "Nodes" << "\n";
	for (int i = 0; i < num; i++) {
		cin >> obj;
		tree.add_node(obj);
	}
}

void build_tree_from_file(tree<student>& tree) {
	ifstream f_in;
	f_in.open("f_in.txt");
	int num;
	student obj;
	cout << "Nodes num: " << "\n";
	f_in >> num;
	cout << "Nodes" << "\n";
	for (int i = 0; i < num; i++) {
		f_in >> obj;
		cout << obj << "\n";
		tree.add_node(obj);
	}
	f_in.close();
}

void write_tree(tree<student>& tree) {
	cout << "tree in LNR perfomace" << "\n";
	tree.print_LNR();
}

void add_tree(tree<student>& tree) {
	cout << "Write what add to your tree" << "\n";
	student obj;
	cin >> obj;
	tree.add_node(obj);
}

void delete_node_from_tree(tree<student>& tree) {
	cout << "Write what delete from your tree" << "\n";
	student obj;
	cin >> obj;
	tree.delete_node(obj);
}

t_node<student>* find_in_tree(tree<student>& tree) {
	cout << "Write what you want to find" << "\n";
	student obj;
	t_node<student>* node;
	cin >> obj;
	if (node = tree.find(obj)) {
		cout << "Yes i find it" << "\n";
		return node;
	}
	cout << "I can't find it(" << "\n";
	return nullptr;
}

void change_node(tree<student>& tree) {
	cout << "Write what you want to change" << "\n";
	student obj;
	t_node<student>* node;
	cin >> obj;
	if (node = tree.find(obj)) {
		cout << "Yes i find it, change it" << "\n";
		tree.delete_node(obj);
		cin >> obj;
		tree.add_node(obj);
		return;
	}
	cout << "I can't find it..." << "\n";
}

void good_students(tree<student>& tree, double score) {
	bool flag = 0;
	scan_tree(tree.get_root(), score, flag);
	if (flag == 0)
		cout << "There is no students with this mid score" << "\n";
}

void students_from_group(tree<student>& tree, int group) {
	bool flag = 0;
	scan_tree_for_equal(tree.get_root(), group, flag);
	if (flag == 0)
		cout << "There is no student from this group" << "\n";
}

void scan_tree(t_node<student>* pos, double score, bool& flag) {
	if (pos == nullptr) return;
	scan_tree(pos->left(), score, flag);
	if (pos->value() >= score) {
		flag = 1;
		student obj = pos->value();
		cout << obj.surname() << " " << obj.group_num() << "\n";
	}
	scan_tree(pos->right(), score, flag);
}

void scan_tree_for_equal(t_node<student>* pos, int group_num, bool& flag) {
	if (pos == nullptr) return;
	scan_tree_for_equal(pos->left(), group_num, flag);
	if (pos->value() == group_num) {
		flag = 1;
		student obj = pos->value();
		cout << obj.surname() << " ";
		obj.show_progress();
		cout << "\n";
	}
	scan_tree_for_equal(pos->right(), group_num, flag);
}

void menu(tree<student>& my_tree) {
	write_menu();
	cout << "Write comand num" << "\n";
	int choice = check_choice();
	while (true) {
		switch (choice) {
		case 1:
			build_tree(my_tree);
			break;
		case 2:
			build_tree_from_file(my_tree);
			break;
		case 3:
			write_tree(my_tree);
			break;
		case 4:
			add_tree(my_tree);
			break;
		case 5:
			delete_node_from_tree(my_tree);
			break;
		case 6:
			find_in_tree(my_tree);
			break;
		case 7:
			change_node(my_tree);
			break;
		case 8:
			cout << "Write mid score" << "\n";
			double score;
			score = check_score();
			good_students(my_tree, score);
			break;
		case 9:
			int group;
			group = ch_neg_nums();
			cout << "Write group" << "\n";
			students_from_group(my_tree, group);
			break;
		case 10:
			int lvl;
			cin >> lvl;
			my_tree.print_LNR_lvl(lvl);
			break;
		case 11:
			return;
		}
		cout << "Write comand num" << "\n";
		choice = check_choice();
	}
}
