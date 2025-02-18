/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeugeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:57:03 by gdeugeni          #+#    #+#             */
/*   Updated: 2025/02/18 18:57:09 by gdeugeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char *s, int *count)
{
	size_t	len;

	if (!s)
		ft_print_str("(null)", count);
	else
	{
		len = ft_strlen(s);
		write(1, s, len);
		*count += len;
	}
}
