/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:45:26 by raalifa           #+#    #+#             */
/*   Updated: 2025/04/30 19:15:55 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = num * 10 + (*str - '0');
		if (sign == -1 && num >= LLONG_MAX)
			return (0);
		if (num >= LLONG_MAX)
			return (-1);
		str++;
	}
	return (num * sign);
} 

int main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid =ft_atoi(av[1]);
		while (av[2][0] != '\0')
		{
			
		}
	}
	else
		ft_printf("Error\n");
}