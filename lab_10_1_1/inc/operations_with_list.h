#ifndef _OPERATIONS_WITH_LIST_H
#define _OPERATIONS_WITH_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "errors.h"
#include "print_countries.h"

int comparator_name_country(void *f_struct, void *s_struct);
//сравнение данных структуры (имен стран)
//принимает на вход указатели на две структуры
//возвращает результат сравнения

int fwrite_countries(char *namefile, node_t *head);
//запись структуры в файл
//принимает на вход имя файла и указатель на структуру
//возвращает код ошибки

void fprint_list(FILE *f, node_t *head);
//запись списка в файл
//принимает на вход указатель на файл и указатель на начало списка

void append(node_t **head_a, node_t **head_b);
//добавление списка b в конец списка а, опустошение списка b
//принимает на вход указатель на списки

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
//добавление элемента в упорядоченный список
//принимает на вход упорядоченный список и элемент

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
//упорядочивание списка по возрастанию
//принимает на вход список

#endif