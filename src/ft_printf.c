/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 09:49:18 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/12 09:49:20 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	putnbr_hex(unsigned int n, char x, int *c)
{
    char chr;

	if (n > 0)
    {
        putnbr_hex(n / 16, x, c);
        chr = "0123456789abcdef"[(n % 16)];
        if(x == 'X')
            chr = ft_toupper(chr);
        (*c)++;
        write(1, &chr, 1);
    }
}

static void count_num(int i, int *c)
{
    long n;

    n = i;
    if (n == 0)
        (*c)++;
    else
    {
        if(n < 0)
        {
            n = i * -1;
            (*c)++;
        }
        while(n > 0 )
        {
            (*c)++;
            n /= 10;
        }
    }
}

static void put_u_num(unsigned int i, int *c)
{
    if(i > 0)
    {
        put_u_num(i/10, c);
        i = i % 10 + '0';
        write(1, &i, 1);
        (*c)++;
    }
}

int ft_printf(const    char *format, ...)
{
    int i;
    int c;
    va_list list;
    va_start(list, format);

    i = 0;
    c = 0;
    while(format[i])
    {
        if(format[i] == '%')
        {
            i++;
            //Writes a single character
            if(format[i] == 'c')
            {
                const char ch = va_arg(list, int);
                c++;
                write(1, &ch, 1);
            }
            //Write a string
            else if(format[i] == 's')
            {
                int i;

                i = 0;
                char *ch = va_arg(list, char *);
                while(ch[i])
                {
                    write(1, &ch[i], 1);
                    i++;
                    c++;
                }
            }
            //Writes a pointer
            //The void * pointer argument has to be printed in hexadecimal format
            else if(format[i] == 'p')
            {
                int i;
                char buf[19];
                buf[18] = '\0';
                uintptr_t address;
                
                
                i = 17;
                void *ch = va_arg(list, void *);
                if (!ch)
                {
                    write(1, "(nil)", 5);
                    c += 5;
                }
                else
                {
                    address = (uintptr_t)ch;
                    while(address > 0)
                    {
                        buf[i] = "0123456789abcdef"[address % 16];
                        address /= 16;
                        i--;
                    }
                    buf[i] = 'x';
                    c++;
                    write(1, "0", 1);
                    while(buf[i])
                    {
                        write(1, &buf[i], 1);
                        i++;
                        c++;
                    }
                }
            }
            //Writes a signed integer in decimal representation
            //Writes a signed integer in decimal representation
            //printf("%.3d", 5) 005
            //printf("%.0d", 0); Force a precision of 0 for the number 0; nothing printed
            // d Prints a decimal (base 10) number.
            // i Prints an integer in base 10.
            else if(format[i] == 'd' || format[i] == 'i')
            {
                int ch = va_arg(list, int);
                ft_putnbr_fd(ch, 1);
                count_num(ch, &c);
            }
            //Writes an unsigned integer in decimal representation
            //Prints an unsigned decimal (base 10) number
            else if(format[i] == 'u')
            {
                unsigned int ch;
                ch = va_arg(list, unsigned int);
                put_u_num(ch, &c);
            }
            //Writes an unsigned integer in hexadecimal representation lowercase
            //Prints a number in hexadecimal (base 16) lowercase format
            else if(format[i] == 'x')
            {
                unsigned int ch;
                ch = va_arg(list, unsigned int);
                if (ch == 0)
                {
                    c++;
                    write(1, "0", 1);
                }
                else
                    putnbr_hex(ch, 'x', &c);
            }
            //Writes an unsigned integer in hexadecimal representation uppercase
            //Prints a number in hexadecimal (base 16) uppercase format.
            else if(format[i] == 'X')
            {
                unsigned int    ch;
                ch = va_arg(list, unsigned int);
                if (ch == 0)
                {
                    c++;
                    write(1, "0", 1);
                }
                else
                    putnbr_hex(ch, 'X', &c);
            }
            //Writes % character
            // Prints a percent sign.
            if(format[i] == '%')
            {
                c++;
                write(1, "%", 1);
            }
        }
        else
        {
            c++;
            write(1, &format[i], 1);
        }
        i++;
    }
    va_end(list);
    return (c);
}

// int main()
// {
//     int a;
//     int b;

//     b = printf("%x\n", 420);
//     a = ft_printf("%x\n", 420);
//     printf("%d %d", a, b);

//     unsigned int c = 300;
//     ft_printf("%X\n", c);
//     printf("%X\n", c);
//     return (0);
// }
