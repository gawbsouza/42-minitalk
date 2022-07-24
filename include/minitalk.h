/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/24 01:15:04 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

# define USLEEP_TIME 500

typedef struct s_charmaker
{
	int	calls;
	int	buff;
}	t_charmaker;

#endif
