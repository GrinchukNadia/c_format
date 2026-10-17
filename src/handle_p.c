/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:57:37 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/17 09:57:38 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(uintptr_t address, char *buf)
{
	int	i;

	i = 17;
	buf[18] = '\0';
	if (address == 0)
	{
		buf[i] = '0';
		i--;
	}
	while (address > 0)
	{
		buf[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		i--;
	}
	buf[i] = 'x';
	return (i);
}

void	handle_p(va_list list, int *c)
{
	int			i;
	char		buf[19];
	void		*ch;
	uintptr_t	address;

	ch = va_arg(list, void *);
	if (!ch)
	{
		write(1, "(nil)", 5);
		(*c) += 5;
		return ;
	}
	address = (uintptr_t)ch;
	i = convert_hex(address, buf);
	(*c)++;
	write(1, "0", 1);
	while (buf[i])
	{
		write(1, &buf[i], 1);
		i++;
		(*c)++;
	}
}
