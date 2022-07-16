 #include <iostream>
#include <string.h>
#include "Class.h"
using namespace std;

arts::arts() {
	//cout << "Работает конструктор 1" << endl;
}

arts::arts(string name_of_art, string author, int date_of_create, int price) {
	//cout << "Работает конструктор 2" << endl;
	_name_of_art = name_of_art;
	_author = author;
	_date_of_create = date_of_create;
	_price = price;
}

arts::arts(const arts& art)
{
	//cout << "Конструктор копирования";
	_name_of_art = art._name_of_art;
	_author = art._author;
	_date_of_create = art._date_of_create;
	_price = art._price;
}

arts::~arts() {
	cout << "Работает деструктор" << endl;
	_name_of_art = "";
    _author = "";
	_date_of_create = 0; 
	_price = 0;
}

bool arts::operator >(const arts& obj) {
	if (_author > obj._author)
		return true;
	return false;
}

arts arts::operator --(int) {
	arts obj(*this);
	_price--;
	return obj;
}




