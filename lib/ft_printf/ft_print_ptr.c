/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:24:19 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/25 11:23:04 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	out_len;

	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	out_len = ft_print_str("0x");
	out_len += ft_print_num_base((long int) ptr, UNSIGNED_INT, BASE_HEX_LOW);
	return (out_len);
}
