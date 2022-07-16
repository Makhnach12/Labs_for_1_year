#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//функция для декодирования зашифрованного текста
int decoder_func(const char* fname_orig, const char* fname_code);

//функция для шифрования и записи закодированного текста
bool coding_and_writing_func(const char* fname_orig, const char* fname_code);

//функция для подсчета максимального и минимального
void couter_max_min(int& maxn, int& minn, int symbs[]);

//функция для вывода самой часто и самой редко встречающихся букв на конце слова
void couter_letters(int maxn, int minn);

#endif //FUNCTIONS_H

