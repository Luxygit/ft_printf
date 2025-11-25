/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:24:59 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/25 10:56:48 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexl(unsigned int n, int *count)
{
	static const char	*hex;
	char				c;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthexl(n / 16, count);
	c = hex[n % 16];
	write(1, &c, 1);
	(*count)++;
}

void	ft_hexl(va_list *args, int *count)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	ft_puthexl(n, count);
}
