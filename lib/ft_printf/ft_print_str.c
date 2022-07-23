/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:57:59 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/25 10:38:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

int	ft_print_str(const char *str)
{
	int	out_len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	out_len = ft_strlen(str);
	write(1, str, out_len);
	return (out_len);
}
