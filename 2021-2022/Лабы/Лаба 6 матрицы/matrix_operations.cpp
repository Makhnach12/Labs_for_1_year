#include <iostream>
#include <string>
#include <math.h>
#include "matrix_operations.h"
#include "checking_operations.h"
using namespace std;

//������� ��� �������� �������
double** create_matrix(int m, int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[m];
	return matrix;
}

//������� ��� ����� ���������� ������� A
double** input_square_matrix(int n)
{
	double** matrix = create_matrix(n, n);
	for (int i1 = 0; i1 < n; i1++)
		for (int i2 = 0; i2 < n; i2++)
		{
			cout << "A[" << i1 << "]" << "[" << i2 << "]" << "=";
			correct_input_matrix_members(matrix[i1][i2]);
		}
	return matrix;
}

//������� ��� ����� ������ ������� �
double** input_matrix(int m, int n)
{
	double** matrix = create_matrix(m, n);
	for (int i1 = 0; i1 < n; i1++)
		for (int i2 = 0; i2 < m; i2++)
		{
			cout << "A[" << i1 << "]" << "[" << i2 << "]" << "=";
			correct_input_matrix_members(matrix[i1][i2]);
		}
	return matrix;
}

//������� ������������ ������
double** matrix_multiply(double** matrix1, double** matrix2, int n)
{
	double sum = 0;
	double** increase_of_matrixes = create_matrix(n, n);
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			sum = 0;
			for (int i3 = 0; i3 < n; i3++)
				sum += matrix2[i1][i3] * matrix1[i3][i2];
			increase_of_matrixes[i1][i2] = sum;
		}
	}
	return increase_of_matrixes;
}

//������� ������������ ������
double** sum_of_matrixes(double** matrix1, double** matrix2, int n)
{
	double** sum_of_matrixes = create_matrix(n, n);
	for (int i1 = 0; i1 < n; i1++)
		for (int i2 = 0; i2 < n; i2++)
			sum_of_matrixes[i1][i2] = matrix1[i1][i2] + matrix2[i1][i2];
	return sum_of_matrixes;
}

//������� ������� �������� ������
double** difference_of_matrixes(double** matrix1, double** matrix2, int n)
{
	double** dif_of_matrix = create_matrix(n, n);
	for (int i1 = 0; i1 < n; i1++)
		for (int i2 = 0; i2 < n; i2++)
			dif_of_matrix[i1][i2] = matrix1[i1][i2] - matrix2[i1][i2];
	return dif_of_matrix;
}

//������� ����������� �������
double** copy_matrix(double** matrix1, int n)
{
	double** copied_matrix = create_matrix(n, n);
	for (int i1 = 0; i1 < n; i1++)
		for (int i2 = 0; i2 < n; i2++)
			copied_matrix[i1][i2] = matrix1[i1][i2];
	return copied_matrix;
}

//������� ������������ ������� � ���������� ����� 
double** matrix_plus_free_number(double** matrix, int num, int n)
{
	for (int i1 = 0; i1 < n; i1++)
		matrix[i1][i1] = matrix[i1][i1] + num;
	return matrix;
}

//������� ���������� ������� ������� � ���������� ����� 
double** matrix_minus_free_number(double** matrix, int num, int n)
{
	for (int i1 = 0; i1 < n; i1++)
		matrix[i1][i1] = num - matrix[i1][i1];
	return matrix;
}

//������� ������� ��������� ��������
void cleaning_matrix(int n,double** matrix)
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = 0;
}

//������� ������ ������� �� �����
void cout_matrix(double** matrix, int n)
{
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			cout << " ";
			printf("%.9f", matrix[i1][i2]);
			cout << " ";
		}
	    cout<<endl;
    }
}

//������� ������ ��� ������� f
void output_of_function_f(double** matrix, int n, double** matrix_sum_of_f)
{
	double** matrix_2nd_degree = matrix_multiply(matrix, matrix, n);
	double** matrix_4th_degree = matrix_multiply(matrix_2nd_degree, matrix_2nd_degree, n);
	cout << "A^4:" << endl;
	cout_matrix(matrix_4th_degree, n);
	cout << "A^2:" << endl;
	cout_matrix(matrix_2nd_degree, n);
	matrix_sum_of_f = sum_of_matrixes(matrix_4th_degree, matrix_2nd_degree, n);
	matrix_sum_of_f = matrix_plus_free_number(matrix_sum_of_f, 1, n);
	cout << "A^4+A^2+1=" << endl;
	cout_matrix(matrix_sum_of_f, n);
	cleaning_matrix(n, matrix_2nd_degree);
	cleaning_matrix(n, matrix_4th_degree);
}

//������� ������ ��� ������� g
void output_of_function_g(double** matrix, int n, double** matrix_sum_of_g)
{
	double** matrix_3rd_degree = matrix_multiply(matrix, matrix, n);
	matrix_3rd_degree = matrix_multiply(matrix_3rd_degree, matrix, n);
	cout << "A^3:" << endl;
	cout_matrix(matrix_3rd_degree, n);
	cout << "A:" << endl;
	cout_matrix(matrix, n);
	matrix_sum_of_g = sum_of_matrixes(matrix_3rd_degree, matrix, n);
	cout << "A^3+A=" << endl;
	cout_matrix(matrix_sum_of_g, n);
	cleaning_matrix(n, matrix_3rd_degree);
}

//������� ������� �������� ����� ��������� f � g
void difference_of_functions_f_and_g(int n, double** matrix)
{
	double** matrix_sum_of_f = new double*[n];
	double** matrix_sum_of_g = new double*[n];
	output_of_function_f(matrix, n, matrix_sum_of_f);
	output_of_function_g(matrix, n, matrix_sum_of_g);
	double** matrix_dif_of_f_and_g = difference_of_matrixes(matrix_sum_of_f, matrix_sum_of_g, n);
	cout << "f(A)-g(A)=" << endl;
	cout_matrix(matrix_dif_of_f_and_g, n);
	cleaning_matrix(n, matrix_sum_of_f);
	cleaning_matrix(n, matrix_sum_of_g);
	cleaning_matrix(n, matrix_dif_of_f_and_g);
}

// ��������� ������� ��� i-� ������ � 0-�� �������
void get_new_smaller_matrix(double** matrix, double** new_small_matrix, int i, int j, int matrix_size) {
	int new_i, new_j, flag_i, flag_j;
	flag_i = 0;
	for (new_i = 0; new_i < matrix_size - 1; new_i++) { 
		// �������� ������� ������
		if (new_i == i) flag_i = 1;
		flag_j = 0;
		for (new_j = 0; new_j < matrix_size - 1; new_j++) { 
			// �������� ������� �������
			if (new_j == j) flag_j = 1;
			new_small_matrix[new_i][new_j] = matrix[new_i + flag_i][new_j + flag_j];
		}
	}
}

//����������� ���������� ������������
int determinant_counter(int matrix_size, double** matrix) {
	int determinant = 0, dimension_of_new_matrix;
	double** new_smaller_matrix;
	new_smaller_matrix = create_matrix(matrix_size, matrix_size);
	dimension_of_new_matrix = matrix_size - 1;
	if (matrix_size == 1) {
		determinant = matrix[0][0];
		return(determinant);
	}
	if (matrix_size == 2) {
		determinant = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
		return(determinant);
	}
	if (matrix_size > 2) {
		for (int i = 0; i < matrix_size; i++) {
			get_new_smaller_matrix(matrix, new_smaller_matrix, i, 0, matrix_size);
 			determinant = determinant + pow(-1,i) * matrix[i][0] * determinant_counter(dimension_of_new_matrix, new_smaller_matrix);
		}
	}
	cleaning_matrix(dimension_of_new_matrix, new_smaller_matrix);
	return determinant;
}

//������� �������� ��������� ������ ������� � �������
void change_matrix(double** matrix_oroginal, int dem�ntion_of_matrix,  int st, int num)
{
	double member = 0;
	for (int i = 0; i < dem�ntion_of_matrix; i++)
	{
		member = matrix_oroginal[st][i];
		matrix_oroginal[st][i] = matrix_oroginal[num][i];
		matrix_oroginal[num][i] = member;
	}
}

//������� ������������� ������ ����� � �������
double** first_minor_counter(int length_of_matrix, int high_of_matrix, double** matrix_oroginal, double** matrix_minor, int& ordinal_num_in_line_1, int& ordinal_num_in_line_2, int& rank)
{
	ordinal_num_in_line_1 = 0;
	//���� �� �� ����� �� ��������� ������
	while (ordinal_num_in_line_1 != high_of_matrix)
	{
		for (ordinal_num_in_line_2 = ordinal_num_in_line_1 + 1; ordinal_num_in_line_2 < high_of_matrix; ordinal_num_in_line_2++)
			for (int i = 0; i < length_of_matrix; i++)
				for (int j = 0; j < length_of_matrix; j++)
					if (i != j)
					{
						//���������� ���������� ������� ����������� �������� 
						matrix_minor[0][0] = matrix_oroginal[ordinal_num_in_line_1][i];
						matrix_minor[0][1] = matrix_oroginal[ordinal_num_in_line_1][j];
						matrix_minor[1][0] = matrix_oroginal[ordinal_num_in_line_2][i];
						matrix_minor[1][1] = matrix_oroginal[ordinal_num_in_line_2][j];
						if (determinant_counter(2, matrix_minor) != 0)
						{
							rank = 2;
							ordinal_num_in_line_1 = i;
							ordinal_num_in_line_2 = j;
							//����� ������ ������� ���� ������ ����� ������� ��� ����������
							change_matrix(matrix_oroginal, high_of_matrix, ordinal_num_in_line_1, 0);
							change_matrix(matrix_oroginal, high_of_matrix, ordinal_num_in_line_2, 1);
							return matrix_minor;
						}
					}
		ordinal_num_in_line_1++;
	}
	//cout_matrix(matrix_minor, 2);
	cout << endl;
	return 0;
}

//������� ������������� ������ 3-�� � ������ ��������
int minor_counter_for_rank(int length_of_matrix, int high_of_matrix, int ordinal_num_in_line_1, int ordinal_num_in_line_2, double** matrix_minor, double** matrix_original)
{
	int rank = 2, element_in_line = 0, flag = 0, matrix_size = 3, num=0;
	int* first_line_elements = new int[length_of_matrix];
	first_line_elements[ordinal_num_in_line_1] = 1;
	first_line_elements[ordinal_num_in_line_2] = 1;
	for (int i = 0; i < length_of_matrix; i++)
		if (first_line_elements[i] != 1)
		first_line_elements[i] = 0;
	int count_of_steps = 1;
	if (length_of_matrix == high_of_matrix)
		num = high_of_matrix;
	else 
		num = high_of_matrix - 1;
	//���� �� ������ �� ��������� ������� �������
	while (count_of_steps != num)
	{
		//���� �� ������ ������
		for (int i = 0; i < length_of_matrix; i++)
			if (first_line_elements[i] != 1)
			{
				//��������� ��� ���� ������� �� ������ ����������� ������
				for (int j = 0; j < matrix_size - 1; j++)
					matrix_minor[j][matrix_size - 1] = matrix_original[j][i];
				//���� �� ������� � ��������� ������ ������ ������
				for (int i2 = matrix_size - 1; i2 < high_of_matrix; i2++)
				{
					//� ���� ����� ��������� ������ ����� ������ �� ������ ���������� ��������� ������ �����
					for (int i3 = 0; i3 < length_of_matrix; i3++)
						if (first_line_elements[i3] == 1)
						{
							matrix_minor[matrix_size - 1][element_in_line] = matrix_original[i2][i3];
							element_in_line++;
						}
					//��������� �������� ���������� ��������(������ ������� � ������ �������) ������� ������ 
					matrix_minor[matrix_size - 1][matrix_size - 1] = matrix_original[i2][i];
					element_in_line = 0;
					if (determinant_counter(matrix_size, matrix_minor) != 0)
					{
						rank++;
						change_matrix(matrix_original, high_of_matrix, i2, matrix_size - 1);
						first_line_elements[i] = 1;
						flag = 1;
						break;
					}
				}
				if (determinant_counter(matrix_size, matrix_minor) != 0)
					break;
			}
		//cout_matrix(matrix_minor, matrix_size - 1);
		cout << endl;
		count_of_steps++;
		matrix_size++;
		if (flag == 0)
		{
			delete[]first_line_elements;
			return rank;
		}
		flag = 0;
	}
	delete[]first_line_elements;
	return rank;
}

//������� ��� �������� ������������� �������
double** minor_determinant_counter(double** main_matrix, int matrix_size)
{
	double** minors_determinant = create_matrix(matrix_size, matrix_size);
	double** new_smaller_matrix = create_matrix(matrix_size - 1, matrix_size - 1);
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			get_new_smaller_matrix(main_matrix, new_smaller_matrix, i, j, matrix_size);
			minors_determinant[i][j] = determinant_counter(matrix_size - 1, new_smaller_matrix);
		}
	}
	return minors_determinant;
}

//������� ��� �������� �������� �������
double** create_reverse_matrix(double** main_matrix, int matrix_size, double** minors_determinant)
{
	double determinant_of_main_matr = determinant_counter(matrix_size, main_matrix);
	double** reverse_matrix = create_matrix(matrix_size, matrix_size);
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++)
			reverse_matrix[i][j] =  (pow(-1, i + j) * minors_determinant[j][i])/ determinant_of_main_matr;
	cout_matrix(reverse_matrix, matrix_size);
	return reverse_matrix;
}
