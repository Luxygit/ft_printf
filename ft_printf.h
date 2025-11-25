/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:50:31 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/25 10:55:59 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_chars(va_list *args, int *count);
void	ft_strings(va_list *args, int *count);
void	ft_decimals(va_list *args, int *count);
void	ft_hexu(va_list *args, int *count);
void	ft_hexl(va_list *args, int *count);
void	ft_unsigned(va_list *args, int *count);
void	ft_integers(va_list *args, int *count);
void	ft_pointers(va_list *args, int *count);
#endif
