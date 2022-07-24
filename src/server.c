/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:24:59 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 21:29:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_builders	g_builders;

static void	sigusr_handle(int sig)
{
	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	if (!g_builders.cb)
		g_builders.cb = char_build_new();
	if (sig == SIGUSR1)
		char_build(g_builders.cb, BIT_ZERO);
	if (sig == SIGUSR2)
		char_build(g_builders.cb, BIT_ONE);
	if (g_builders.cb->done)
	{
		if (!g_builders.sb)
			g_builders.sb = str_build_new();
		str_build(g_builders.sb, g_builders.cb->buffer);
		if (g_builders.cb->buffer == '\0')
		{
			write(1, g_builders.sb->buffer, g_builders.sb->next_char - 1);
			write(1, "\n", 1);
			str_build_destroy(&g_builders.sb);
		}
		char_build_destroy(&g_builders.cb);
	}
}

static void	setup_signals_handle(void)
{
	if (signal(SIGUSR1, sigusr_handle) == SIG_ERR)
	{
		ft_printf("SIGUSR1 setup failure.\n");
		exit(EXIT_FAILURE);
	}
	if (signal(SIGUSR2, sigusr_handle) == SIG_ERR)
	{
		ft_printf("SIGUSR2 setup failure.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	g_builders.cb = NULL;
	g_builders.sb = NULL;
	setup_signals_handle();
	ft_printf(":: MiniTalk [GASOUZA] ::\n");
	ft_printf("Server PID: %d\n\n", getpid());
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
