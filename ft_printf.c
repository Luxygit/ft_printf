/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:29:20 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/22 22:33:02 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_detect(const char **p, va_list *args, int *count)
{
	if (**p == 'c')
		ft_chars(args, count);
	else if (**p == 's')
		ft_strings(args, count);
	else if (**p == 'd' || **p == 'i')
		ft_decimals(args, count);
	else if (**p == 'p')
		ft_pointers(args, count);
	else if (**p == 'u')
		ft_unsigned(args, count);
	else if (**p == 'x')
		ft_hexl(args, count);
	else if (**p == 'X')
		ft_hexu(args, count);
	else
	{
		write(1, "%", 1);
		write(1, *p, 1);
		(*count) += 2;
	}
}

static void	ft_printchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

static void	ft_scan(const char **fmt, va_list *args, int *count)
{
	if (**fmt == '%')
	{
		(*fmt)++;
		if(**fmt == '%')
			ft_printchar('%', count);
		else if (**fmt)
			ft_detect(fmt, args, count);
	}
	else
		ft_printchar(**fmt, count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		ft_scan(&format, &args, &count);
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}

/*
ft_printf function takes a format especifier 
undefined number of times telling us what
will be printed.
As a variadic function it also needs to know
how many arguments it has in this case, by
seeing how many "%..." there are as args.
it initializes the va_list type args and cpy
and va_starts initializes the first argument


*/
/*
#include <stdio.h>
int	main(void)
{
	int	a = ft_printf("ft_printf prints %c %s %d %i %u %p %x %X\n",'a', "hola", -10, -214, 5, "asd", 123, 123);
	int	b = printf("og printf prints %c %s %d %i %u %p %x %X\n", 'a', "hola", -10, -214, 5, "asd", 123, 123);
	printf("ft_printf returns %d chars\nog printf returns %d chars\n", a, b);
	return (0);
}*/
