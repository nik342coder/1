#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#define PI 3.14 //объявляем константу пи
#define MAX_INPUT_SIZE 1000
#define MAX_INPUT 1000
#define SIZE 10
#include<stdlib.h>

// Функция для подсчёта слов с подряд идущими одинаковыми буквами
int countWordsWithRepeatedLetters(const char *str);

// Функция для фильтрации слов с подряд идущими одинаковыми буквами
void filter_words_with_doubles(char *str);

// Обнуляет столбцы, где чётных элементов больше, чем нечётных
void zero_columns_with_more_evens(int **matrix, int rows, int cols);

// Функция для нахождения номера пары соседних элементов с максимальной суммой
int find_max_sum_pair(const int *array, int size);

// Вспомогательная функция для создания и освобождения матрицы
int** create_matrix(int rows, int cols);
void free_matrix(int **matrix, int rows);

double cut_cone(double H, double R, double D);

// Объявление функции
void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
void lab6();


#endif // FUNCTIONS_H