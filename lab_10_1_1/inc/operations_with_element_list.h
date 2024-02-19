#ifndef _OPERATIONS_WITH_ELEMENT_LIST_H
#define _OPERATIONS_WITH_ELEMENT_LIST_H

#include <stdlib.h>
#include <string.h>
#include "structs.h"

int comparator(const void *f_data, const void *s_data);
//сравнение данных двух узлов
//принимает на вход указатели на данные узлов
//возвращает разность данных первого и второго узлов

int comparator_find_country(void *f_struct, void *s_struct);
//сравнение двух структур
//принимает на вход указатела на две структуры
//возвращает реузльтат сравнения

void *pop_front(node_t **head);
//удаление элемента из головы списка
//принимает на вход указатель на начало списка
//возвращает указатель на данные из удаленного элемента

void *pop_back(node_t **head);
//удаление элемента из хвоста списка
//принимает на вход указатель на начало списка
//возвращает указатель на данные из удаленного элемента

#endif 