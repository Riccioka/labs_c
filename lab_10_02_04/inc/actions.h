#ifndef _ACTION_H
#define _ACTION_H

int action_out(void);
//вызов функции translate_num_in_list и обработка результата
//(читает число из файла, преобразует в список функцией translate_num_in_list и выводит результат)

int action_mul(void);
//вызов функции multiply_lists и обработка результата
//(читает числа из двух файлов, преобразует их в список функцией translate_num_in_list, перемножает с помощью
//multiply_lists и выводит результат)

int action_div(void);
//вызов функции divide_lists и обработка результата
//(читает числа из двух файлов, преобразует их в список функцией translate_num_in_list, делит с помощью
//divide_lists и выводит результат)

int action_sqr(void);
//вызов функции sqr_list и обработка результата
//(читает число из файла, преобразует в список функцией translate_num_in_list, возводит в квадрат
//функцией sqr_list и выводит результат)

#endif