#include <iostream>
#include <windows.h>
#include <string>
#include "matrix_operations.h"
#include "checking_operations.h"
using namespace std;

int main()
{
	//������ �������. ������ �������, 
	int length_of_matrix, high_of_matrix, ordinal_num_in_line_1, ordinal_num_in_line_2, rank = 1;
	setlocale(0, "RUS");
	cout << "������� ����� �������" << endl;
	correct_input_matrix_dimension(length_of_matrix);
	cout << "������� ������ �������" << endl;
	correct_input_matrix_high(length_of_matrix, high_of_matrix);
	double** matrix = input_matrix(length_of_matrix, high_of_matrix);
	double** matrix_minor = create_matrix(length_of_matrix, high_of_matrix);
	first_minor_counter(length_of_matrix, high_of_matrix, matrix, matrix_minor, ordinal_num_in_line_1, ordinal_num_in_line_2, rank);
	if (rank == 1)
		cout << rank;
	else
	    cout << "���� ����� " << minor_counter(length_of_matrix, high_of_matrix, ordinal_num_in_line_1, ordinal_num_in_line_2, matrix_minor, matrix);
	cout << endl;
	cleaning_matrix(high_of_matrix, matrix);
	cleaning_matrix(high_of_matrix, matrix_minor);
	system("pause");
	return 0;
}