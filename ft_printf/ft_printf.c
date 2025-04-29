/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:43:51 by raalifa           #+#    #+#             */
/*   Updated: 2025/01/03 09:44:00 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printfchecker(char c, va_list *args, int *len)
{
	if (*len == -1)
		return ;
	if (c == 'c')
		ft_putcharl(va_arg(*args, int), len);
	else if (c == 's')
		ft_string(va_arg(*args, char *), len);
	else if (c == 'p')
		ft_pointer(va_arg(*args, unsigned long long), len);
	else if (c == 'd' || c == 'i')
		ft_putnbrl(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (c == 'x')
		ft_hexa((unsigned long long)va_arg(*args, unsigned int), len, 0);
	else if (c == 'X')
		ft_hexa((unsigned long long)va_arg(*args, unsigned int), len, 1);
	else if (c == '%')
		ft_putcharl('%', len);
	else
		ft_putcharl(c, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			ft_printfchecker(*format, &args, &length);
		}
		else
			ft_putcharl((int)*format, &length);
		if (length == -1)
			break ;
		format++;
	}
	va_end(args);
	return (length);
}
