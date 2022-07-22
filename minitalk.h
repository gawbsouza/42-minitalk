/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/22 19:08:01 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 2
# define BIT_ZERO 0
# define BIT_ONE 1

typedef struct s_charbuild
{
	char	buffer;
	int		next_bit;
}	t_charbuild;

typedef struct s_strbuild
{
	char	*buffer;
	size_t	size;
	size_t	next_char;
}	t_strbuild;

t_charbuild	*new_charbuild(void);
char		build_char(t_charbuild *cb, int bit);
t_strbuild	*new_strbuild(size_t buffer_size);
void		build_str(t_strbuild *sb, char c, size_t buffer_size);

#endif
