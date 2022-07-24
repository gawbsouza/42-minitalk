/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:22:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/24 06:48:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_received;

static void	transmit(const char *msg, int pid)
{
	char		tmp_char;
	size_t		bit;
	size_t		pos_char;

	pos_char = 0;
	while (msg && pos_char <= ft_strlen(msg))
	{
		tmp_char = msg[pos_char];
		bit = 0;
		while (bit++ < 8)
		{
			usleep(USLEEP_TIME);
			if (tmp_char & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			g_received = 0;
			while (!g_received)
				;
			tmp_char >>= 1;
		}
		pos_char++;
	}
}

static void	confirm_received(int sig)
{
	if (sig == SIGUSR1)
	{
		g_received = 1;
		ft_putstr_fd("Confirm received from bit: 0\n", 1);
	}
	if (sig == SIGUSR2)
	{
		g_received = 1;
		ft_putstr_fd("Confirm received from bit: 1\n", 1);
	}
}

static void	setup_signals_handle(void)
{
	if (signal(SIGUSR1, confirm_received) == SIG_ERR)
	{
		ft_printf("SIGUSR1 setup failure.\n");
		exit(EXIT_FAILURE);
	}
	if (signal(SIGUSR2, confirm_received) == SIG_ERR)
	{
		ft_printf("SIGUSR2 setup failure.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: client <PID> <Message>\n");
		return (EXIT_FAILURE);
	}
	g_received = 0;
	setup_signals_handle();
	transmit(argv[2], ft_atoi(argv[1]));
	ft_printf("Message sent.\n");
	exit(EXIT_SUCCESS);
}
