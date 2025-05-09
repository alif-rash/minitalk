/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:16:33 by raalifa           #+#    #+#             */
/*   Updated: 2025/05/08 20:00:46 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_sig(int signal_c, siginfo_t *info, void *context)
{
	static char	c;
	static int	count;

	(void)context;
	if (signal_c == SIGUSR1)
		c = c | (1 << count);
	count++;
	if (count == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_printf("%c", c);
		count = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error: No arguments needed\n");
		return (1);
	}
	ft_printf("PID: %d\n", getpid());
	action.sa_sigaction = ft_get_sig;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	while (ac == 1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
