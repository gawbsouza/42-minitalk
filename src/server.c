/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:24:59 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/24 01:14:29 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_charmaker	g_charmaker;

static void	sigusr_handle(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_charmaker.calls > 7)
	{
		g_charmaker.calls = 0;
		g_charmaker.buff = 0;
	}
	usleep(USLEEP_TIME);
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	if (sig == SIGUSR2)
	{
		g_charmaker.buff |= 1 << g_charmaker.calls;
		kill(info->si_pid, SIGUSR2);
	}
	if (g_charmaker.calls == 7)
	{
		if (g_charmaker.buff == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_charmaker.buff, 1);
	}
	g_charmaker.calls++;
}

static void	setup_signals_handle(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigusr_handle;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("SIGUSR1 setup failure.\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("SIGUSR2 setup failure.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	setup_signals_handle();
	ft_printf(":: MiniTalk [GASOUZA] ::\n");
	ft_printf("Server PID: %d\n\n", getpid());
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
