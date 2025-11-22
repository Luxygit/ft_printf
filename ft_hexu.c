/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:31:33 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/22 20:52:27 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_puthexu(unsigned int n, int *count)
{
	static const char	*hex;
	char				c;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthexu(n / 16, count);
	c = hex[n % 16];
	write(1, &c, 1);
	(*count)++;
}

void	ft_hexu(va_list *args, int *count)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	ft_puthexu(n, count);
}
