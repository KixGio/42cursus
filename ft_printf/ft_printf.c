/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeugeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:54:06 by gdeugeni          #+#    #+#             */
/*   Updated: 2025/02/18 18:54:11 by gdeugeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifiers(const char c, int*count, va_list args)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(args, int), count);
	else if (c == 'u')
		ft_print_uns_int(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_print_low_hex(va_arg(args, unsigned int), count);
	else if (c == 'X')
		ft_print_up_hex(va_arg(args, unsigned int), count);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, void *), count);
	else if (c == '%')
		ft_print_char('%', count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s)
				ft_specifiers(*s, &count, args);
		}
		else
			ft_print_char(*s, &count);
		s++;
	}
	va_end(args);
	return (count);
}
