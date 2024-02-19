#ifndef _ACTIONS_H
#define _ACTIONS_H

#include "structs.h"

void action_pf(node_t **head);
//вызов функции pop_front и обработка результата
//принимает на вход указатель на голову списка

void action_pb(node_t **head);
//вызов функции pop_back (pop_end) и обработка результата
//принимает на вход указатель на голову списка

int action_a(node_t **head, char *name_f_in_2, char *name_f_out);
//вызов функции append и обработка результата
//принимает на вход указатель на голову списка и имена двух файлов

#endif