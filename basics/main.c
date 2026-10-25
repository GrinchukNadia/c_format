#include "ft_printf.h"

int main()
{
    int a;
    int b;

    b = printf("%x\n", 420);
    a = ft_printf("%x\n", 420);
    printf("%d %d", a, b);

    unsigned int c = 300;
    ft_printf("%X\n", c);
    printf("%X\n", c);
    return (0);
}