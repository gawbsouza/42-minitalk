/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:56 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 00:53:21 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_charbuild	*new_charbuild(void)
{
	t_charbuild	*cb;

	cb = (t_charbuild *) malloc(sizeof(t_charbuild));
	if (cb)
	{
		cb->buffer = 0;
		cb->next_bit = 0;
		cb->done = 0;
	}
	return (cb);
}

/* Use OR mask to insert a bit at your correct postion on buffer */
void	build_char(t_charbuild *cb, int bit)
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
