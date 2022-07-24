/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_build_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:59:18 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 19:59:36 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_charbuild	*char_build_new(void)
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
