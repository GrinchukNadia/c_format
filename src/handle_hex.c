/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:36:00 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/17 10:36:04 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

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

void	handle_x(va_list list, int *c, char x)
{
	unsigned int	ch;

	ch = va_arg(list, unsigned int);
	if (ch == 0)
	{
		(*c)++;
		write(1, "0", 1);
	}
	else
		putnbr_hex(ch, x, c);
}
