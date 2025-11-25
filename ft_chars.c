/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:47:04 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/25 10:56:34 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chars(va_list *args, int *count)
{
	char	ch;

	ch = (char)va_arg(*args, int);
	write(1, &ch, 1);
	(*count)++;
}
