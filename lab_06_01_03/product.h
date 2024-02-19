#ifndef PRODUCT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_INPUT -1
#define INCORRECT_PRICE -2
#define INCORRECT_COUNT -3
#define NON_EXISTENT_FILE -4
#define EMPTY_FILE -5
#define INCORRECT_STRUCT -6

#define MAX_LEN 25
#define MAX_COUNT 15

typedef struct
{
    char name[MAX_LEN];
    int price;
} product;

void print_product(char *name, int price);

int read_product(FILE* filename, char *name, int *price);

#endif