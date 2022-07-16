#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class student {
private:
	int _student_num;
	string _surname;
	string _initials;
	int _group_num;
	int* _st_progress;
public:
	student() {
		_student_num = 0;
		_surname = "";
		_initials = "";
		_group_num = 0;
		_st_progress = new int[5];
		for (int i = 0; i < 5; i++)
			_st_progress[i] = 0;
	}
	student(const student& obj) {
		_student_num = obj._student_num;
		_surname = obj._surname;
		_initials = obj._initials;
		_group_num = obj._group_num;
		_st_progress = new int[5];
		for (int i = 0; i < 5; i++)
			_st_progress[i] = obj._st_progress[i];
	}
	~student() {
		if (_st_progress == nullptr)
			return;
		_student_num = 0;
		_surname = "";
		_initials = "";
		_group_num = 0;
		delete[] _st_progress;
	}
	const int student_num() { return _student_num; }
	const string surname() { return _surname; }
	const string initials() { return _initials; }
	const int group_num() { return _group_num; }
	const int* st_progress() { return _st_progress; }
	double middle_score();

	void set_student_num(int num) { _student_num = num; }
	void set_surname(string surname) { _surname = surname; }
	void set_initials(string initials) { _initials = initials; }
	void set_group_num(int num) { _group_num = num; }
	void set_st_progress(int idx, int num) { _st_progress[idx] = num; }

	void show_progress();

	friend ostream& operator<<(ostream&, const student&);
	friend istream& operator>>(istream&, student&);

	bool operator >(const student& stud);
	bool operator >(const double score);
	bool operator <(const student& stud);
	bool operator ==(const student& stud);
	bool operator ==(int num);
	bool operator >=(const double score);
	void operator =(student& stud);
};

inline ostream& operator<<(ostream& output, const student& stud) {
	output << "student num: " << stud._student_num << "\n";
	output << "student surname: " << stud._surname << "\n";
	output << "student initials: " << stud._initials << "\n";
	output << "student group: " << stud._group_num << "\n";
	output << "student marks: ";
	for (int i = 0; i < 5; i++)
		output << stud._st_progress[i] << " ";
	output << "\n";
	return output;
}

inline istream& operator>>(istream& input, student& stud) {
	cout << "Student number: " << "\n";
	input >> stud._student_num;
	cout << "Student surname: " << "\n";
	input >> stud._surname;
	cout << "Student initials: " << "\n";
	input >> stud._initials;
	cout << "Student group num: " << "\n";
	input >> stud._group_num;
	cout << "Student marks: " << "\n";
	for (int i = 0; i < 5; i++)
		input >> stud._st_progress[i];
	return input;
}

inline bool student::operator ==(const student& stud) {
	if (_surname == stud._surname && _group_num == stud._group_num)
		return true;
	return false;
}

inline bool student::operator ==(int num) {
	if ( _group_num == num )
		return true;
	return false;
}

inline bool student::operator >(const student& stud) {
	int max_l = max(_surname.size(), stud._surname.size());
	for (int i = 0; i < max_l; i++) {
		if (_surname[i] > stud._surname[i])
			return true;
		else if (_surname[i] < stud._surname[i])
			return false;
	}
	if (_group_num > stud._group_num)
		return true;
	else
		return false;
}

inline bool student::operator >(const double score) {
	if (middle_score() > score)
		return 1;
	return 0;

}

inline void student::operator =(student& stud) {
	_student_num = stud._student_num;
	_surname = stud._surname;
	_initials = stud._initials;
	_group_num = stud._group_num;
	for (int i = 0; i < 5; i++)
		_st_progress[i] = stud._st_progress[i];
}


#endif
