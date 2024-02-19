#ifndef _PRODUCTS_H_
#define _PRODUCTS_H_

#include <stdio.h>

#define OK 0
#define EMPTY_FILE -1
#define ERROR_FILE -2
#define ERROR_NUM -3
#define ERROR_PRICE -4
#define ERROR_READ -5
#define INCORRECT_COUNT_OF_STRUCTS -6
#define INCORRECT_ARG -7
#define TOO_LONG -8
#define INCORRECT_NAME -9
#define MEMORY_ERROR -10

struct products
{
    char *name;
    int price;
};

void print_product(struct products *product);
//вывод одной структуры
//принимает на вход указатель на структуру product

int read_product(FILE *f, struct products *struct_arr, int i);
//чтение одной структуры
//принимает на вход указатель на файл f, указатель на массив структур struct_arr и номер итерации i

#endif
