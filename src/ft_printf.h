/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:16:22 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/16 16:16:23 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	handle_p(va_list list, int *c);
void	handle_di(va_list list, int *c);
void	handle_u(va_list list, int *c);
void	handle_c(va_list list, int *c);
void	handle_sp(int *c);
void	handle_s(va_list list, int *c);
void	handle_x(va_list list, int *c, char x);

#endif
