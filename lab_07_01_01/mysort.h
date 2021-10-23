#ifndef MYSORT_H
#define MYSORT_H

void mysort(int new_count, int **new_arr, int (*comparator)(const void *, const void *));

int comparator(const void *elem_1, const void *elem_2);

#endif // MYSORT_H
