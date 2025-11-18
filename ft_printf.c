/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:29:20 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/18 20:43:31 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && n > 1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	cmp;
	va_start(args, format);
	while (args)
	{
		cmp = ft_strncmp(va_arg(args, const char*));
		if (cmp == 0)
		{	
			write(1, &c, 1);
		}
		if (cmp == "%d")
		{
			write(1, %d, 4);
		}
		va_arg(args, const char*);
	}
	va_end(args);
	return (0);
}

/*
ft_printf function takes a format especifier 
undefined number of times telling us what
will be printed.
As a variadic function it also needs to know
how many arguments it has in this case, by
seeing how many "%..." there are as args.
it initializes the va_list type args 
*/

#include <stdio.h>
int	main(void)
{
	ft_printf("%c %d",'a', 1);
	printf("%c %d", 'a', 1);
	return (0);
}
