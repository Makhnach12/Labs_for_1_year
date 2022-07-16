#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;

template <class T>
class t_node {
private:
	T _value;
	t_node<T>* _left = nullptr;
	t_node<T>* _right = nullptr;
	t_node<T>* _parent = nullptr;
	t_node(T& val) { _value = val; _left = _right = _parent = 0; }
public: 
    void set_value(T val) { _value = val; }
	t_node<T>* left() { return _left; }
	t_node<T>* right() { return _right; }
	T value() { return _value; }
	template <class Ti> friend class tree;
};

template <class T>
class tree {
public:
	tree() { _root = 0; }
	int high() {
		int levels = 0;
		if (_root == 0)
			return 0;
		high(_root, 0, levels);
		return levels;
	}
	void print() { print(_root, 0); }
	void print_LNR() { print_LNR(_root); }
 	void print_LNR_lvl(int max_lvl) { print_LNR_lvl(_root, 0, max_lvl); }
	void scan_tree(t_node<T>* pos, double, bool&);
	void scan_tree_for_equal(t_node<T>* pos, int group_num, bool& flag);

	void add_node(T& val) { add_node(val, _root); }
	void delete_node(T& val) { delete_node(val, _root); }
	t_node<T>* find(T&  val) { return find(_root, val); }
	t_node<T>* get_root() { return _root; }
	~tree() { destroy(_root); }
private:
	t_node<T>* _root;

	void add_node(T& val, t_node<T>* pos);

	void delete_node(T& val, t_node<T>* pos);

	void print(t_node<T>* pos, int level);

	void print_LNR(t_node<T>* pos);

	void print_LNR_lvl(t_node<T>* pos, int lvl, const int max_lvl);

	void high(t_node<T>* pos, int space, int& levels);

	t_node<T>* find(t_node<T>* pos, T& val);

	t_node<T>* min(t_node<T>* pos);

	void destroy(t_node<T>* pos);

};

template <class T> void tree<T>::add_node(T& val, t_node<T>* pos) {
	if (pos == nullptr) {
		pos = new t_node<T>(val);
		_root = pos;
		return;
	}
	if (pos->_value == val)
		return;
	if (pos->_value < val) {
		if (pos->_right == nullptr) {
			pos->_right = new t_node<T>(val);
			pos->_right->_parent = pos;
		}
		else
			add_node(val, pos->_right);
	}
	if (pos->_value > val) {
		if (pos->_left == nullptr) {
			pos->_left = new t_node<T>(val);
			pos->_left->_parent = pos;
		}
		else
			add_node(val, pos->_left);
	}
}

template <class T> void tree<T>::print(t_node<T>* pos, int level) {
	if (pos == 0) return;
	print(pos->_right, level + 1);
	for (int i = 0; i < level; i++)
		cout << ' ';
	cout << pos->_value << '\n';
	print(pos->_left, level + 1);
}

template <class T> void tree<T>::high(t_node<T>* pos, int space, int& levels) {
	if (pos == nullptr)
		return;
	high(pos->_left, space + 1, levels);
	levels = max(space + 1, levels);
	high(pos->_right, space + 1, levels);
}

template <class T> t_node<T>* tree<T>::find(t_node<T>* pos, T& val) {
	if (!pos) return nullptr;
	if (pos->_value == val) return pos;
	if (pos->_value < val) return find(pos->_right, val);
	return find(pos->_left, val);
}

template <class T> void tree<T>::destroy(t_node<T>* pos) {
	if (!pos) return;
	destroy(pos->_left);
	destroy(pos->_right);
	delete pos;
}

template <class T> t_node<T>* tree<T>::min(t_node<T>* pos){
 	if ( pos->_left == nullptr || pos->_left->_left == nullptr) {
		t_node<T>* app_node = nullptr;
		if (pos->_left != nullptr)
			app_node = pos->_left;
		else
			app_node = pos;
		pos->_left = nullptr;
		return app_node;
	}
	return min(pos->_left);
}

template <class T> void tree<T>::delete_node(T& val, t_node<T>* pos) {
	if (!find(val)) {
		cout << "Problem i can't find this element(" << "\n";
		return;
	}
	if (val < pos->_value)
		delete_node(val, pos->_left);
	else if (val > pos->_value)
		delete_node(val, pos->_right);
	else {
		if (pos->_left == 0 && pos->_right == 0) {
			if (pos->_parent == nullptr)
				delete pos;
			else {
				if (pos->_parent->_left != nullptr && pos->_parent->_left->_value == val)
					pos->_parent->_left = nullptr;
				else
					pos->_parent->_right = nullptr;
				delete pos;
			}
		}
		else if (pos->_left != 0 && pos->_right != 0) {
			if (pos->_right->_left == nullptr || pos->_right->_left->_value == 0) {
				t_node<T>* app_node = nullptr;
				app_node = pos->_right->_right;
				pos->_value = pos->_right->_value;
				delete pos->_right;
				pos->_right = app_node;
			}
			else {
				t_node<T>* app_node = nullptr;
				app_node = min(pos->_right);
				if (app_node->_right != nullptr) {
					pos->_value = app_node->_value;
					pos->_right = app_node->_right;
				}
				pos->_value = app_node->_value;
				delete app_node;
			}

		}
		else if (pos->_left != 0 || pos->_right != 0) {
			t_node<T>* app_node = nullptr;
			if (pos->_left)
				app_node = pos->_left;
			else
				app_node = pos->_right;
			pos->_left = app_node->_left;
			pos->_right = app_node->_right;
			pos->_value = app_node->_value;
			delete app_node;
		}
	}

}

template <class T> void tree<T>::print_LNR(t_node<T>* pos) {
	if (pos == nullptr) return;
	print_LNR(pos->_left);
	cout << pos->_value <<"\n";
	print_LNR(pos->_right);
}

template <class T> void tree<T>::print_LNR_lvl(t_node<T>* pos, int lvl, const int max_lvl) {
	if (pos == nullptr) return;
	print_LNR_lvl(pos->_left, lvl+1, max_lvl);
	if (lvl == max_lvl)
		cout << pos->_value << "\n";
	print_LNR_lvl(pos->_right, lvl+1, max_lvl);
}

#endif
