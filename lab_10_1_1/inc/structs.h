#ifndef _STRUCT_LIST_H
#define _STRUCT_LIST_H

#define COUNT_STRING_STRUCT 3

typedef struct country
{
    char *name_country;
    char *name_capital;
    long population;
} country_t;

typedef struct array_countries
{
    country_t *array;
    int size;
}countries_t;

typedef struct node
{
    void *data;
    struct node *next;
} node_t;


#endif