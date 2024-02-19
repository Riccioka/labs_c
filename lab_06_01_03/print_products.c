#include "product.h"
#include "print_products.h"

void print_products(product *products, int count, int price)
{
    for (int i = 0; i < count; i++)
        if (products[i].price < price)
            print_product(products[i].name, products[i].price);
//            printf("%s\n%d\n", products[i].name, products[i].price);
}