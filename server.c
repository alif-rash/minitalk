/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:53:52 by raalifa           #+#    #+#             */
/*   Updated: 2025/04/29 19:54:09 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_sig(int signal_c)
{
	static char	c;
	static int	count;

	if (signal_c == SIGUSR1)
		c |= (c << 1);
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
	}
	
}

int main(int ac, char **av)
{
	(void)av;
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, ft_get_sig);
	signal(SIGUSR2, ft_get_sig);
	
}