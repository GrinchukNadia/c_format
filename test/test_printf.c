#include "strings.h"
#include "test.h"
#include "ft_printf.h"
#include <stdio.h>

int main(void)

{
    int a = ft_printf("%%\n");
    int b = printf("%%");
    
    func_name("ft_printf");
    check("\% sign", a, b);

    a = ft_printf("%d\n", 3);
    b = printf("%d\n", 3);
    check("digit", a, b);

    a = ft_printf("%s\n", "Hello 42");
    b = printf("%s\n", "Hello 42");
    check("string", a, b);
    
    return (test_result());
}