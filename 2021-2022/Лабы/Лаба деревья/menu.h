#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "Tree.h"
#include "Student.h"

void write_menu();

void build_tree(tree<student>&);

void build_tree_from_file(tree<student>& tree);

void write_tree(tree<student>&);

void add_tree(tree<student>&);

void delete_node_from_tree(tree<student>& tree);

t_node<student>* find_in_tree(tree<student>& tree);

void change_node(tree<student>& tree);

void good_students(tree<student>& tree, double score);

void students_from_group(tree<student>& tree, int group);

void scan_tree(t_node<student>* pos, double score, bool& flag);

void scan_tree_for_equal(t_node<student>* pos, int group_num, bool& flag);

void menu(tree<student>& my_tree);
#endif
