/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:21:06 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/17 10:21:09 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	handle_di(va_list list, int *c)
{
	int	ch;

	ch = va_arg(list, int);
	ft_putnbr_fd(ch, 1);
	count_num(ch, c);
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

void	handle_u(va_list list, int *c)
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
