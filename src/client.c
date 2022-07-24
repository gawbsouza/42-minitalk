/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:22:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 21:33:27 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			if (tmp_char & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(USLEEP_TIME);
			tmp_char >>= 1;
		}
		pos_char++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: client <PID> <Message>\n");
		return (1);
	}
	transmit(argv[2], ft_atoi(argv[1]));
	ft_printf("Message sent.\n");
	return (0);
}
