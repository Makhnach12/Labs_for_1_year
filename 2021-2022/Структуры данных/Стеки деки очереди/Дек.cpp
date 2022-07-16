#include <iostream>
#include <vector>
using namespace std;

//класс дек
class deque {
private:
	int* _arr;
	int _size = 0;
	int _arr_size;
public:
	int head() { return _arr[0]; }
	int last() { return _arr[_size - 1]; }

	deque(int size) {
		_arr = new int[size];
		_arr_size = size;
		_size = 0;
	}

	void push_back(int v) {
		if (_size == _arr_size)
			return;
		else
			_arr[_size++] = v;
	}

	void push_front(int v) {
		if (_size == _arr_size)
			return;
		else {
			_size++;
			for (int i = _size - 1; i >= 0; i--)
				_arr[i] = _arr[i - 1];
			_arr[0] = v;
		}
	}

	void pop_front(int& el) {
		if (_size == 0)
			return;
		else {
			el = _arr[0];
			for (int i = 0; i < _size - 1; i++)
				_arr[i] = _arr[i + 1];
			_size--;
		}
	}

	void pop_back(int& el) {
		if (_size == 0)
			return;
		else {
			el = _arr[_size - 1];
			_size--;
		}
	}

	int front() {
		if (_size > 0)
			return _arr[0];
	}

	int back() {
		if (_size != 0)
			return _arr[_size - 1];
	}

	int size() { return _size; }

	void clear() { _size = 0; }

	~deque() {
		delete[] _arr;
		clear();
	}
};