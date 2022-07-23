/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:05:04 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/27 14:48:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc(const char *s, int *number)
{
	int	multiple;

	if (!ft_isdigit(*s))
		return (1);
	multiple = calc(s + 1, number);
	*number += (*s - '0') * multiple;
	return (multiple * 10);
}

int	ft_atoi(const char *s)
{
	int		number;
	int		negative;

	number = 0;
	negative = 0;
	while (ft_strchr("\t\n\v\f\r ", *s))
		s++;
	negative = *s == '-';
	if (*s == '+' || *s == '-')
		s++;
	if (!*s || !ft_isdigit(*s))
		return (0);
	calc(s, &number);
	if (negative)
		return (number * -1);
	return (number);
}
