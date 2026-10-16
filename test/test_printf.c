#include "strings.h"
#include "test.h"
#include "ft_printf.h"
#include "../src/libft/libft.h"
#include <stdio.h>

int main(void)

{
    func_name("ft_printf");
    int a;
    int b;
    
    
    a = ft_printf("\n%c\n", 'a');
    b = printf("\n%c\n", 'a');
    check("digit", a, b);
    
    a = ft_printf("%s\n", "Hello 42");
    b = printf("%s\n", "Hello 42");
    check("string", a, b);
    
    int c = 4;
    a = ft_printf("%p\n", &c);
    b = printf("%p\n", &c);
    check("pointer", a, b);
    
    a = ft_printf("%d\n", 3);
    b = printf("%d\n", 3);
    check("digit d", a, b);
    
    a = ft_printf("%i\n", 4);
    b = printf("%i\n", 4);
    check("digit i", a, b);
    
    a = ft_printf("%u\n", 42);
    b = printf("%u\n", 42);
    check("unsigned decimal", a, b);
    
    b = printf("%x\n", 420);
    a = ft_printf("%x\n", 420);
    check("hexadeciaml lowercase", a, b);
    
    a = ft_printf("%X\n", 300);
    b = printf("%X\n", 300);
    check("hexadecimal uppercase", a, b);
    
    a = ft_printf("%%\n");
    b = printf("%%\n");
    check("\% sign", a, b);
    
    return (test_result());
}