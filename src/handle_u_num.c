/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 08:37:19 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/25 08:37:23 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
