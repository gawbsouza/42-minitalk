/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:58:06 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/25 11:28:26 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num_base(long long int n, int signal, char *base)
{
	char	*str;
	int		out_len;

	out_len = 0;
	str = ft_num_base_str(n, signal, base);
	if (str != NULL)
	{
		out_len = ft_print_str(str);
		free(str);
	}
	return (out_len);
}
