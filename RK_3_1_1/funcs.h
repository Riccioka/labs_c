#ifndef FUNCS_H
#define FUNCS_H


void mtr_free(int **mtr, int n);

int **alloc_mtr(int n, int m);

int find_min(int **mtr, int n, int m);

int read_mtr(FILE *f, int **mtr, int n, int m);

#endif // FUNCS_H
