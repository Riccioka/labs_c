#ifndef MYSORT_H
#define MYSORT_H
#include <stdlib.h>

void mysort(void *const arr, size_t count, size_t size, int (*comparator)(const void *, const void *));
//void mysort(int count, int **arr, size_t size, int (*comparator)(const void *, const void *));

int comparator(const void *elem_1, const void *elem_2);

#endif // MYSORT_H
