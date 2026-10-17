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

static void	handle_format(char form, va_list list, int *c)
{
	if (form == 'c')
		handle_c(list, c);
	else if (form == 's')
		handle_s(list, c);
	else if (form == 'p')
		handle_p(list, c);
	else if (form == 'd' || form == 'i')
		handle_di(list, c);
	else if (form == 'u')
		handle_u(list, c);
	else if (form == 'x')
		handle_x(list, c, form);
	else if (form == 'X')
		handle_x(list, c, form);
	else if (form == '%')
		handle_sp(c);
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
			handle_format(format[i], list, &c);
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
