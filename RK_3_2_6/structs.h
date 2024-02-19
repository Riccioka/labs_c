#ifndef STRUCTS_H
#define STRUCTS_H

struct node_t
{
    int num;
    struct node_t *next;
};

struct list_t
{
    struct node_t *head;
    struct node_t *tail;
};

#endif // STRUCTS_H
