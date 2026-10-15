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

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void ft_printf(const    char *format, ...)
{
    int i;
    va_list list;
    va_start(list, format);

    i = 0;
    while(format[i])
    {
        if(format[i] == '%')
        {
            i++;
            //Writes a single character
            if(format[i] == 'c')
            {
                const char ch = va_arg(list, int);
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
                }
            }
            //Writes a pointer
            //The void * pointer argument has to be printed in hexadecimal format
            else if(format[i] == 'p')
            {
                
            }
            //Writes a signed integer in decimal representation
            //Writes a signed integer in decimal representation
            //printf("%.3d", 5) 005
            //printf("%.0d", 0); Force a precision of 0 for the number 0; nothing printed
            // d Prints a decimal (base 10) number.
            // i Prints an integer in base 10.
            else if(format[i] == 'd' || format[i] == 'i')
            {
                int ch = va_arg(list, int) + '0';
                write(1, &ch, 1);
            }
            //Writes an unsigned integer in decimal representation
            //Prints an unsigned decimal (base 10) number
            else if(format[i] == 'u')
            {
                
            }
            //Writes an unsigned integer in hexadecimal representation lowercase
            //Prints a number in hexadecimal (base 16) lowercase format
            else if(format[i] == 'x')
            {
                
            }
            //Writes an unsigned integer in hexadecimal representation uppercase
            //Prints a number in hexadecimal (base 16) uppercase format.
            else if(format[i] == 'X')
            {
                
            }
            //Writes % character
            // Prints a percent sign.
            if(format[i] == '%')
            {
                write(1, "%", 1);
            }
        }
        else
        {
            write(1, &format[i], 1);
        }
        i++;
    }
    va_end(list);
}

// int main()
// {
//     ft_printf("%%");
//     return (0);
// }
