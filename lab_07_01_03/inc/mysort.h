#ifndef _MY_SORT_H_
#define _MT_SORT_H_

#include <stdio.h>
#include <stdlib.h>

void mysort(void *arr, size_t len, size_t size, int (*compar)(const void *, const void *)); //сортировка пузырьком 1,

void swap(void *elem_1, void *elem_2, size_t size); //

int comparator(const void *p1, const void *p2); //

#endif
