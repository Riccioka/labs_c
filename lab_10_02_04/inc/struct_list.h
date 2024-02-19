#ifndef _STRUCT_LIST_H
#define _STRUCT_LIST_H

typedef struct node
{
    int data;
    int degree;
    struct node *next;
} node_t;

#endif