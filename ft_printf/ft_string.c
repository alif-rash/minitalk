/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:44:12 by raalifa           #+#    #+#             */
/*   Updated: 2025/01/03 09:44:11 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharl(int ch, int *len)
{
	if (*len == -1)
		return ;
	if (write(1, &ch, 1) == -1)
	{
		*len = -1;
		return ;
	}
	(*len)++;
}

void	ft_string(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str && *len != -1)
	{
		ft_putcharl(*str, len);
		str++;
	}
}
