/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:10:00 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/22 20:52:17 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_puthexp(unsigned long n, int *count)
{
	static const char	*hex;
	char				c;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthexp(n / 16, count);
	c = hex[n % 16];
	write(1, &c, 1);
	(*count)++;
}

void	ft_pointers(va_list *args, int *count)
{
	unsigned long	address;

	address = (unsigned long)va_arg(*args, void *);
	if (address == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*count) += 2;
	ft_puthexp(address, count);
}
