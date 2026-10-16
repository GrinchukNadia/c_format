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
    
// --------------c------------------
    printf("\nActual:     ");
    b = printf("%c\n", 'a');

    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%c\n", 'a');

    check("digit", a, b);
// --------------c------------------

    
// --------------s------------------
    printf("\nActual:     ");
    b = printf("%s\n", "Hello 42");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "Hello 42");
    printf("\n");
    check("string", a, b);
// --------------s------------------
    

// --------------d------------------
    int c = 4;
    printf("\nActual:     ");
    b = printf("%p\n", &c);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%p\n", &c);
    check("pointer", a, b);

    printf("\nActual:     ");
    b = printf("%p\n", NULL);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%p\n", NULL);
    check("pointer address is NULL", a, b);
// --------------d------------------


// --------------d------------------
    printf("\nActual:     ");
    b = printf("%d\n", 0);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", 0);
    check("digit d: 0", a , b);

    printf("\nActual:     ");
    b = printf("%d\n", 3);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", 3);
    check("digit d", a, b);
// --------------d------------------


// --------------i------------------
    printf("\nActual:     ");
    printf("Expected:   ");
    b = printf("%i\n", 4);
    fflush(stdout);
    a = ft_printf("%i\n", 4);
    check("digit i", a, b);
// --------------i------------------


// --------------u------------------
    printf("\nActual:     ");
    b = printf("%u\n", 4294967295U);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%u\n", 4294967295U);
    check("unsigned decimal, max", a, b);

    printf("\nActual:     ");
    b = printf("%u\n", 42);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%u\n", 42);
    check("unsigned decimal", a, b);
// --------------u------------------


// --------------x------------------
    printf("\nActual:     ");
    b = printf("%x\n", 0);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%x\n", 0);
    check("hexadeciaml lowercase: 0", a , b);

    printf("\nActual:     ");
    b = printf("%x\n", 420);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%x\n", 420);
    check("hexadeciaml lowercase", a, b);
// --------------x------------------


// --------------X------------------
    printf("\nActual:     ");
    b = printf("%X\n", 0);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%X\n", 0);
    check("hexadecimal uppercase: 0", a, b);
    
    printf("\nActual:     ");
    b = printf("%X\n", 300);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%X\n", 300);
    check("hexadecimal uppercase", a, b);
// --------------X------------------


// --------------%------------------
    printf("\nActual:     ");
    b = printf("%%\n");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%%\n");
    check("\% sign", a, b);
// --------------%------------------

    return (test_result());
}