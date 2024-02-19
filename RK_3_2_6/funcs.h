#ifndef FUNCS_H
#define FUNCS_H

void list_from_file(FILE *f, struct list_t *list);

struct node_t *create_node(int num);

void list_add_tail(struct list_t *list, struct node_t *node);

void free_node(struct node_t *node);

void free_list(struct node_t *head);

int find_min(struct list_t *list);

#endif // FUNCS_H
