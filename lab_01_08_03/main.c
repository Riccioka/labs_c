#include <stdio.h>

int get_bit(unsigned int num, int bit)
{
    return (num >> bit) & 1;
}

unsigned int change_bit(unsigned int num, int bit, int pos)
{
    if (bit)
        num |= (1 << pos);
    else
        num &= ~(1 << pos);
    return num;
}

unsigned int swap_bits(unsigned int num)
{
    int bit1 = 0;
    int bit2 = 0;
    for (int i = 0; i < 32; i += 2)
    {
        bit1 = get_bit(num, i);
        bit2 = get_bit(num, i + 1);
        num = change_bit(num, bit1, i + 1);
        num = change_bit(num, bit2, i);
    }
    return num;
}

void print_bits(unsigned int num)
{
    for (int i = 31; i >= 0; --i)
        printf("%d", get_bit(num, i));
}

int main()
{
    unsigned int num = 0;
    if (scanf("%u", &num) <= 0)
        printf("Error: invalid number.");
    else
    {
        printf("Result: ");
        print_bits(swap_bits(num));
        printf("\n");
    }
    return 0;
}
