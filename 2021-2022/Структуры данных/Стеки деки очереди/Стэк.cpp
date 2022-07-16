#include <iostream>
#include <string>
using namespace std;
#define MAX_SIZE 100

class stack {
private:
	int balls[MAX_SIZE]; // стек на 100 символов
public:
	int size;
	stack(){ size = 0; }
	bool push_x(int x){
		if (size == MAX_SIZE)
			return 0;
		balls[size] = x;
		size++;
		cout << "ok" << "\n";
		return 1;
	}
	int pop(){
		if (size == 0)
			return int(255);
		cout << balls[size - 1] << "\n";
		size--;
		return 0;
	}
	void clear(){
		for (int i = 0; i < size; i++)
			balls[i] = 0;
		size = 0;
		cout << "ok" << "\n";
	}
	void back(){
		cout << balls[size - 1] << "\n";
	}
	~stack(){
		clear();
	}
};

int main()
{
	int x;
	stack nums;
	string comand;
	cin >> comand;
	while (comand != "exit") {
		if (comand == "push") {
			cin >> x;
			nums.push_x(x);
		}
		else if (comand == "size")
			cout<<nums.size;
		else if (comand == "clear")
			nums.clear();
		else if (comand == "pop")
			nums.pop();
		else if (comand == "back")
			nums.back();
		cin >> comand;
	}
	cout << "bye";
	return 0;
}
