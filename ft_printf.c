/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:29:20 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/24 19:19:53 by dievarga         ###   ########.fr       */
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

static void	ft_scan(const char **fmt, va_list *args, int *count)
{
	if (**fmt == '%')
	{
		(*fmt)++;
		if(**fmt == '%')
		{
			write(1, "%", 1);
			(*count)++;
			return ;
		}
		else if (**fmt)
			ft_detect(fmt, args, count);
		return ;
	}
	else
	{
		write(1, *fmt, 1);
		(*count)++;
	}
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
for an undefinedi number of times telling us
what will be printed.
As a variadic function with the va_list args
it can 
it initializes the va_list type args and cpy
and va_starts initializes the first argument


*/

#include <stdio.h>
int	main(void)
{
	int	a = ft_printf("ft_printf prints %% %%j %c %s %d %i %u %p %x %X\n",'a', "hola", -10, -214, 5, "asd", 123, 123);
	int	b = printf("og printf prints %% %%j %c %s %d %i %u %p %x %X\n", 'a', "hola", -10, -214, 5, "asd", 123, 123);
	printf("ft_printf returns %d chars\nog printf returns %d chars\n", a, b);

	ft_printf("pointer test %p\n", (void *)"asd");
	printf("pointer test %p\n", (void *)"asd");
	ft_printf("char test %c\n", '0');
	printf("char test %c\n",'0');
	ft_printf("string test %s\n", "asd");
	printf("string test %s\n", "asd");
	ft_printf("decimal test %d\n", -2147483647);
	printf("decimal test %d\n", -2147483647);
	ft_printf("integer test %i\n", -2147483647);
	printf("integer test %i\n", -2147483647);
	ft_printf("unsigned test %u\n", -1);
	printf("unsigned test %u\n", -1);
	ft_printf("lower hex test %x\n", -224748364);
	printf("lower hex test %x\n", -224748364);
	ft_printf("upper hex test %X\n", -1);
	printf("upper hex test %X\n", -1);
	return (0);
}
