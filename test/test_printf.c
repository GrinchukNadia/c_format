#include "strings.h"
#include "test.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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

    check("char", a, b);
// --------------c------------------

    
// --------------s------------------
    printf("\nActual:     ");
    b = printf("%s\n", "Hello 42");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "Hello 42");
    check("string", a, b);

    printf("\nActual:     ");
    b = printf("%s\n", "");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "");
    check("empty string", a, b);

    printf("\nActual:     ");
    b = printf("%s\n", "Hello\n42");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "Hello\n42");
    check("string with \\n", a, b);

    printf("\nActual:     ");
    b = printf("%s\n", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since 1966, when designers at Letraset and James Mosley, the librarian at St Bride Printing Library in London, took a 1914 Cicero translation and scrambled it to make dummy text for Letraset's Body Type sheets.");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since 1966, when designers at Letraset and James Mosley, the librarian at St Bride Printing Library in London, took a 1914 Cicero translation and scrambled it to make dummy text for Letraset's Body Type sheets.");
    check("long string", a, b);

    printf("\nActual:     ");
    b = printf("%s\n", "\0");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "\0");
    check("only \\0", a, b);

    printf("\nActual:     ");
    b = printf("%s\n", "%");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "%");
    check("% as a string", a, b);
// --------------s------------------
    

// --------------p------------------
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
// --------------p------------------


// --------------d------------------
    printf("\nActual:     ");
    b = printf("%d\n", 3);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", 3);
    check("digit d", a, b);
        
    printf("\nActual:     ");
    b = printf("%d\n", 0);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", 0);
    check("digit d: 0", a , b);

    printf("\nActual:     ");
    b = printf("%d\n", INT_MAX);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", INT_MAX);
    check("digit i: INT_MAX", a, b);
        
    printf("\nActual:     ");
    b = printf("%d\n", -3);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", -3);
    check("negative digit d", a, b);

    printf("\nActual:     ");
    b = printf("%d\n", INT_MIN);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", INT_MIN);
    check("digit i: INT_MIN", a, b);
// --------------d------------------


// --------------i------------------
    printf("\nActual:     ");
    b = printf("%i\n", 4);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%i\n", 4);
    check("digit i", a, b);

    printf("\nActual:     ");
    b = printf("%i\n", 0);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%i\n", 0);
    check("digit d: 0", a , b);

    printf("\nActual:     ");
    b = printf("%i\n", INT_MAX);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%i\n", INT_MAX);
    check("digit i: INT_MAX", a, b);
        
    printf("\nActual:     ");
    b = printf("%d\n", -3);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%d\n", -3);
    check("negative digit d", a, b);

    printf("\nActual:     ");
    b = printf("%i\n", INT_MIN);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%i\n", INT_MIN);
    check("digit i: INT_MIN", a, b);

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

    printf("\nActual:     ");
    b = printf("%u\n", 0U);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%u\n", 0U);
    check("unsigned decimal, 0U", a, b);
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

    printf("\nActual:     ");
    b = printf("%x\n", UINT_MAX);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%x\n", UINT_MAX);
    check("hexadeciaml lowercase: UINT_MAX", a, b);
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
    
    printf("\nActual:     ");
    b = printf("%X\n", UINT_MAX);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%X\n", UINT_MAX);
    check("hexadecimal uppercase: UINT_MAX", a, b);
// --------------X------------------


// --------------%------------------
    printf("\nActual:     ");
    b = printf("%%\n");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%%\n");
    check("\% sign", a, b);
// --------------%------------------


//--------without arguments---------
    printf("\nActual:     ");
    b = printf("Hello 42!\n");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("Hello 42!\n");
    check("\% sign", a, b);

    printf("\nActual:     ");
    b = printf("%%%%%%%%\n");
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%%%%%%%%\n");
    check("\% sign", a, b);
//--------without arguments----------

//---------mixed arguments-----------
    printf("\nActual:     ");
    b = printf("%c %s %p %d %i %u %x %X %%\n", 'n', "hi", &c, 5, 125, 34U, 2983, 3734);
    printf("Expected:   ");
    fflush(stdout);
    a = ft_printf("%c %s %p %d %i %u %x %X %%\n", 'n', "hi", &c, 5, 125, 34U, 2983, 3734);
    check("all in one line", a, b);
//---------mixed arguments-----------
return (test_result());
}
