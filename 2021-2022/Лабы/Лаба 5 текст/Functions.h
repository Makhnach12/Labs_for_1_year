#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//������� ��� ������������� �������������� ������
int decoder_func(const char* fname_orig, const char* fname_code);

//������� ��� ���������� � ������ ��������������� ������
bool coding_and_writing_func(const char* fname_orig, const char* fname_code);

//������� ��� �������� ������������� � ������������
void couter_max_min(int& maxn, int& minn, int symbs[]);

//������� ��� ������ ����� ����� � ����� ����� ������������� ���� �� ����� �����
void couter_letters(int maxn, int minn);

#endif //FUNCTIONS_H

