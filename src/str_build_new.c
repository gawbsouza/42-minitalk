/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_build_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:00:00 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 20:02:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_strbuild	*str_build_new(void)
{
	t_strbuild	*sb;

	sb = (t_strbuild *) malloc(sizeof(t_strbuild));
	if (sb)
	{
		sb->buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (sb->buffer)
		{
			sb->buffer[0] = '\0';
			sb->size = BUFFER_SIZE;
			sb->next_char = 0;
		}
	}
	return (sb);
}
