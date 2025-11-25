/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:12:18 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/25 10:58:16 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned int n, int *count)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

void	ft_unsigned(va_list *args, int *count)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	ft_putnbr(n, count);
}
