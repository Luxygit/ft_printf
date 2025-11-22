/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:53:34 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/21 19:13:25 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strings(va_list *args, int *count)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = NULL;
	while (str[i])
	{
		write(1, &str[i], 1);
		(*count)++;
		i++;
	}
}
