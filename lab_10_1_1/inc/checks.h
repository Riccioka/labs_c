#ifndef _CHECKS_H_H
#define _CHECKS_H_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"

int check_file(FILE *f);
//проверка корректности файла
//принимает на вход имя файла
//возвращает код ошибки

int check_argc(int argc, char *action);
//проверка корректности аргументов
//принимает на вход количество аргументов и ключ функции
//возвращает код ошибки

#endif