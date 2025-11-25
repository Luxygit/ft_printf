/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:53:34 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/25 10:58:05 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strings(va_list *args, int *count)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		(*count)++;
		i++;
	}
}
