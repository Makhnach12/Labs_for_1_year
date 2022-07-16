#include <iostream>
#include <string.h>
#include "Student.h"
using namespace std;

double student::middle_score() {
	double sum = 0;
	for (int i = 0; i < 5; i++)
		sum += _st_progress[i];
	return sum / 5;
}

void student::show_progress() {
	for (int i = 0; i < 5; i++)
		cout << _st_progress[i] << " ";
}

bool student::operator <(const student& stud) {
	int max_l = max(_surname.size(), stud._surname.size());
	for (int i = 0; i < max_l; i++) {
		if (_surname[i] < stud._surname[i])
			return true;
		else if (_surname[i] > stud._surname[i])
			return false;
	}
	if (_group_num < stud._group_num)
		return true;
	else
		return false;
}

bool student::operator >=(const double score) {
	if (middle_score() >= score)
		return 1;
	return 0;

}
