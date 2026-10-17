/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:24:19 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/17 10:24:32 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(va_list list, int *c)
{
	char	ch;

	ch = va_arg(list, int);
	(*c)++;
	write(1, &ch, 1);
}

void	handle_sp(int *c)
{
	(*c)++;
	write(1, "%", 1);
}

void	handle_s(va_list list, int *c)
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
