/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:56 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/22 19:05:02 by gasouza          ###   ########.fr       */
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
	}
	return (cb);
}

/* Use OR mask to insert a bit at your correct postion on buffer */
char	build_char(t_charbuild *cb, int bit)
{
	if (!cb || (bit != BIT_ONE && bit != BIT_ZERO))
		return (-1);
	if (cb->next_bit > 7)
	{
		cb->buffer = 0;
		cb->next_bit = 0;
	}
	if (bit)
		cb->buffer |= (1 << cb->next_bit);
	cb->next_bit++;
	if (cb->next_bit > 7)
		return (cb->buffer);
	return (-1);
}
