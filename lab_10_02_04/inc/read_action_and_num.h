#ifndef _READ_ACTION_AND_NUM_H
#define _READ_ACTION_AND_NUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "memory.h"

#define LIMIT_TRANSLATE 2
#define LEN_ACTION  4
#define OUT         1
#define MUL         2
#define SQR         3
#define DIV         4

int read_action(int *action);
//чтение ключа действия
//принимает на вход переменную действия
//возвращает код ошибки
//(выделяет память под строку с помощью allocate_malloc_string, читает ее из файла с помощью fgets,
//контролируя переполнение buff, а затем сравнивает строку с возможными ключами с помощью strcmp и запоминает нужный ключ)

int read_num(int *num);
//чтение числа
//принимает на вход переменную числа
//возвращает код ошибки
//(читает число из файла, проверяя на положительность)

#endif