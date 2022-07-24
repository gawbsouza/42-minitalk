/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 20:55:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

# define USLEEP_TIME 500
# define BUFFER_SIZE 1024
# define BIT_ZERO 0
# define BIT_ONE 1

typedef struct s_charbuild
{
	char	buffer;
	int		next_bit;
	int		done;
}	t_charbuild;

typedef struct s_strbuild
{
	char	*buffer;
	size_t	size;
	size_t	next_char;
}	t_strbuild;

typedef struct s_builders
{
	t_charbuild	*cb;
	t_strbuild	*sb;
}	t_builders;

t_strbuild	*str_build_new(void);
void		str_build(t_strbuild *sb, char c);
void		str_build_destroy(t_strbuild **sb);

t_charbuild	*char_build_new(void);
void		char_build(t_charbuild *cb, int bit);
void		char_build_destroy(t_charbuild **cb);

#endif
