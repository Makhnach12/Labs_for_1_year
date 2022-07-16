#include "Checkers.h"
#include <iostream>
using namespace std;

int ch_neg_nums() {
	int num_of_nodes;
	cin >> num_of_nodes;
	while (cin.fail() || num_of_nodes < 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> num_of_nodes;
	}
	return num_of_nodes;
}

int check_choice() {
	int choice;
	cin >> choice;
	while (cin.fail() || choice < 0 || choice > 11) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> choice;
	}
	return choice;
}

double check_score() {
	double score;
	cin >> score;
	while (cin.fail() || score < 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> score;
	}
	return score;
}

int idx(int max_num) {
	int idx;
	cin >> idx;
	while (cin.fail() || idx > max_num || idx <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> idx;
	}
	return idx;
}