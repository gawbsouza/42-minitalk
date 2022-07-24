/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:00:40 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 20:03:36 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	str_build(t_strbuild *sb, char c)
{
	char	*tmp;

	if (!sb || BUFFER_SIZE == 0)
		return ;
	if (sb->next_char >= sb->size)
	{
		tmp = (char *) malloc(sizeof(char) * (sb->size + BUFFER_SIZE + 1));
		if (!tmp)
			return ;
		ft_memmove(tmp, sb->buffer, sb->size);
		free(sb->buffer);
		sb->buffer = tmp;
		sb->size += BUFFER_SIZE;
	}
	sb->buffer[sb->next_char] = c;
	sb->next_char++;
	sb->buffer[sb->next_char] = '\0';
}
