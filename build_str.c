/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:00:40 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/22 18:21:33 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_strbuild	*new_strbuild(size_t buffer_size)
{
	t_strbuild	*sb;

	sb = (t_strbuild *) malloc(sizeof(t_strbuild));
	if (sb)
	{
		sb->buffer = (char *) malloc(sizeof(char) * (buffer_size + 1));
		if (sb->buffer)
		{
			sb->buffer[0] = '\0';
			sb->size = buffer_size;
			sb->next_char = 0;
		}
	}
	return (sb);
}

void	build_str(t_strbuild *sb, char c, size_t buffer_size)
{
	char	*tmp;

	if (!sb || buffer_size == 0)
		return ;
	if (sb->next_char >= sb->size)
	{
		tmp = (char *) malloc(sizeof(char) * (sb->size + buffer_size + 1));
		if (!tmp)
			return ;
		memmove(tmp, sb->buffer, sb->size);
		free(sb->buffer);
		sb->buffer = tmp;
		sb->size += buffer_size;
	}
	sb->buffer[sb->next_char] = c;
	sb->next_char++;
	sb->buffer[sb->next_char] = '\0';
}
