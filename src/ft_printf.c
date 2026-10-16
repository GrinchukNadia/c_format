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
	char	chr;

	if (n > 0)
	{
		putnbr_hex(n / 16, x, c);
		chr = "0123456789abcdef"[(n % 16)];
		if (x == 'X')
			chr = ft_toupper(chr);
		(*c)++;
		write(1, &chr, 1);
	}
}

static void	count_num(int i, int *c)
{
	long	n;

	n = i;
	if (n == 0)
		(*c)++;
	else
	{
		if (n < 0)
		{
			n *= -1;
			(*c)++;
		}
		while (n > 0)
		{
			(*c)++;
			n /= 10;
		}
	}
}

static void	put_u_num(unsigned int i, int *c)
{
	if (i > 0)
	{
		put_u_num(i / 10, c);
		i = i % 10 + '0';
		write(1, &i, 1);
		(*c)++;
	}
}

static void	handle_c(va_list list, int *c)
{
	char	ch;

	ch = va_arg(list, int);
	(*c)++;
	write(1, &ch, 1);
}

static void	handle_s(va_list list, int *c)
{
	int		i;
	char	*ch;

	i = 0;
	ch = va_arg(list, char *);
	while (ch[i])
	{
		write(1, &ch[i], 1);
		i++;
		(*c)++;
	}
}

static void	handle_p(va_list list, int *c)
{
	int			i;
	char		buf[19];
	void		*ch;
	uintptr_t	address;

	i = 17;
	buf[18] = '\0';
	ch = va_arg(list, void *);
	if (!ch)
	{
		write(1, "(nil)", 5);
		(*c) += 5;
	}
	else
	{
		address = (uintptr_t)ch;
		while (address > 0)
		{
			buf[i] = "0123456789abcdef"[address % 16];
			address /= 16;
			i--;
		}
		buf[i] = 'x';
		(*c)++;
		write(1, "0", 1);
		while (buf[i])
		{
			write(1, &buf[i], 1);
			i++;
			(*c)++;
		}
	}
}

static void	handle_di(va_list list, int *c)
{
	int	ch;

	ch = va_arg(list, int);
	ft_putnbr_fd(ch, 1);
	count_num(ch, c);
}

static void	handle_u(va_list list, int *c)
{
	unsigned int	ch;

	ch = va_arg(list, unsigned int);
	if (ch == 0)
	{
		write(1, "0", 1);
		(*c)++;
	}
	else
		put_u_num(ch, c);
}

static void	handle_x(va_list list, int *c, char x)
{
	unsigned int	ch;

	ch = va_arg(list, unsigned int);
	if (ch == 0)
	{
		c++;
		write(1, "0", 1);
	}
	else
		putnbr_hex(ch, x, &c);
}

static void	handle_sp(int *c)
{
	(*c)++;
	write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		c;
	va_list	list;

	i = 0;
	c = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				handle_c(list, &c);
			else if (format[i] == 's')
				handle_s(list, &c);
			else if (format[i] == 'p')
				handle_p(list, &c);
			else if (format[i] == 'd' || format[i] == 'i')
				handle_di(list, &c);
			else if (format[i] == 'u')
				handle_u(list, &c);
			else if (format[i] == 'x')
				handle_x(list, &c, format[i]);
			else if (format[i] == 'X')
				handle_x(list, &c, format[i]);
			if (format[i] == '%')
				handle_sp(&c);
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
