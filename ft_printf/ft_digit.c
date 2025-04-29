/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:30:05 by raalifa           #+#    #+#             */
/*   Updated: 2025/01/03 09:43:25 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrl(int num, int *len)
{
	if (num == -2147483648)
	{
		ft_string("-2147483648", len);
		return ;
	}
	if (num < 0)
	{
		ft_putcharl('-', len);
		num *= -1;
	}
	if (num >= 10)
		ft_putnbrl(num / 10, len);
	ft_putcharl((num % 10) + '0', len);
}

void	ft_hexa(unsigned long long num, int *len, int i)
{
	char	*hexdig;

	hexdig = "0123456789abcdef";
	if (i)
		hexdig = "0123456789ABCDEF";
	if (num >= 16)
		ft_hexa(num / 16, len, i);
	ft_putcharl(hexdig[num % 16], len);
}

void	ft_pointer(unsigned long long ptr, int *len)
{
	if (ptr == 0)
	{
		ft_string("0x0", len);
		return ;
	}
	ft_string("0x", len);
	ft_hexa(ptr, len, 0);
}

void	ft_unsigned_int(unsigned int unum, int *len)
{
	if (unum > 9)
		ft_unsigned_int(unum / 10, len);
	ft_putcharl(unum % 10 + '0', len);
}
