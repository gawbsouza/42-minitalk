/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:56 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 20:53:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_build(t_charbuild *cb, int bit)
{
	if (cb && !cb->done)
	{
		if (cb->next_bit == 0)
			cb->buffer = 0;
		if (bit == BIT_ONE)
			cb->buffer |= (1 << cb->next_bit);
		if (++cb->next_bit > 7)
		{
			cb->next_bit = 0;
			cb->done = 1;
		}
	}
}
