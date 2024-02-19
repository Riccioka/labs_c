#ifndef _ARR_AND_FILE_H_
#define _ARR_AND_FILE_H_

#include <stdio.h>
#include <stdlib.h>

int count_nums_in_file(FILE *in_file, size_t *nums_in_file); //поиск кол-ва чисел nums_in_file в файле in_file
int read_from_file_to_arr(FILE *in_file, int *pb, int *pe); //чтение их файла in_file в массив с началом в *pb
int write_array_to_file(FILE *out_file, int *pb, int *pe); //запись из массива с началом в *pb в файл in_file

#endif