/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_build_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:18:19 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 21:24:12 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	str_build_destroy(t_strbuild **sb)
{
	if (!sb || !*sb)
		return ;
	free((*sb)->buffer);
	free(*sb);
	*sb = NULL;
}
