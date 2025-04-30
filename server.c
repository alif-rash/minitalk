/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:53:52 by raalifa           #+#    #+#             */
/*   Updated: 2025/04/30 19:12:38 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_sig(int signal_c)
{
	static char	c;
	static int	count;

	if (signal_c == SIGUSR1)
		c |= (1 << count);
	count++;
	if (count == 8)
	{
		ft_printf("%c", c);
		count = 0;
		c = 0;
	}
	
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Error: No arguments needed\n");
		return (1);	
	}
	ft_printf("PID: %d\n", getpid());
	while (ac == 1)
	{
		signal(SIGUSR1, ft_get_sig);
		signal(SIGUSR2, ft_get_sig);
		pause();
	}
}