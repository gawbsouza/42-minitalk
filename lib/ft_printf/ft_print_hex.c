/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:46:53 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/25 11:16:20 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int upper)
{
	if (upper)
		return (ft_print_num_base(n, UNSIGNED_INT, BASE_HEX_UPP));
	else
		return (ft_print_num_base(n, UNSIGNED_INT, BASE_HEX_LOW));
}
