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

static void	write_nbr(long n, int fd)
{
	char	c;

	if (n > 9)
		write_nbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	nc;

	nc = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nc *= -1;
	}
	write_nbr(nc, fd);
}

void	handle_di(va_list list, int *c)
{
	int	ch;

	ch = va_arg(list, int);
	ft_putnbr_fd(ch, 1);
	count_num(ch, c);
}
