#ifndef _MEMORY_LIST_H
#define _MEMORY_LIST_H

#include <stdlib.h>

#include "structs.h"
#include "errors.h"

int list_push(node_t **head, void *element);
//добавление элемента в список
//принимает на вход указатель на голову списка и добавляемый элемент
//возвращает код ошибки

node_t *node_create(void *data);
//создание узла списка
//принимает на вход информационную часть узла
//возвращает указатель на узел

void free_list(node_t **head);
//освобождение памяти из под списка
//принимает на вход указатель на голову списка

#endif 