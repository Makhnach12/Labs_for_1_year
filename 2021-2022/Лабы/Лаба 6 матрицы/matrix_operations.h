#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

//������� ��� �������� �������
double** create_matrix(int n, int m);

//������� ��� ����� ������� A
double** input_square_matrix(int n);

//������� ��� �������� ������� n*m
double** input_matrix(int n, int m);

//������� ���������� ������� � �������
double** matrix_multiply(double** matrix1, double** matrix2, int n);

//������� ������������ ������
double** sum_of_matrixes(double** matrix1, double** matrix2, int n);

//������� ������������ ������� � ���������� ����� 
double** matrix_plus_free_number(double** matrix, int num, int n);

//������� ���������� ������� ������� � ���������� ����� 
double** matrix_minus_free_number(double** matrix, int num, int n);

//������� ������� �������� ������   
double** difference_of_matrixes(double** matrix1, double** matrix2, int n);

//������� ������� ��������� ��������
void cleaning_matrix(int n, double** matrix);

//������� ������ ������� �� �����
void cout_matrix(double** matrix, int n);
//������� ������ ��� ������� f
void output_of_function_f(double** matrix, int n, double** matrix_sum_of_f);

//������� ������ ��� ������� g
void output_of_function_g(double** matrix, int n, double** matrix_sum_of_g);

//������� ������ �������� ������� f � g
void difference_of_functions_f_and_g(int n, double** matrix);

//������� ��� �������� ������������
int determinant_counter(int m, double** mas);

//������� ��� ��������� ������
void get_new_smaller_matrix(double** mas, double** p, int i, int j, int m);

//������� ��� ������ ������� ������
double** first_minor_counter(int length_of_matrix, int high_of_matrix, double** matrix_oroginal, double** matrix_minor, int& min1, int& min2, int& rank);

//������� ��� ������ ������� 3-�� ������� � �����
int minor_counter_for_rank(int length_of_matrix, int high_of_matrix, int min1, int min2, double** matrix, double** matrix_original);

//������� �������� �������� �������
double** create_reverse_matrix(double** main_matrix, int matrix_size, double** minors_determinant);

//������� ��� �������� ������������� �������
double** minor_determinant_counter(double** main_matrix, int matrix_size);
#endif //MATRIX_OPERATIONS
