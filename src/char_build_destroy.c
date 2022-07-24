/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_build_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:18:57 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/23 21:24:37 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_build_destroy(t_charbuild **cb)
{
	if (!cb || !*cb)
		return ;
	free(*cb);
	*cb = NULL;
}
