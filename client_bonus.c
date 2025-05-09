/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:16:12 by raalifa           #+#    #+#             */
/*   Updated: 2025/05/08 20:40:24 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void msg_received(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Message received\n");
}
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

void	ft_send_sig(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
		{
			ft_printf("Error: Invalid PID\n");
			return (1);
		}
		str = av[2];
		i = 0;
		while (str[i])
		{
			ft_send_sig(pid, str[i]);
			i++;
		}
		signal(SIGUSR2, msg_received);
		ft_send_sig(pid, '\0');
	}
	else
		ft_printf("Error\n");
}
