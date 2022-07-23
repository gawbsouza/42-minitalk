/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:27:41 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/28 11:49:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*calc(int n, char *str)
{
	char	digit;

	if (n == 0)
		*str = '0';
	else
	{
		digit = (n % 10);
		n /= 10;
		if (n < 0 || digit < 0)
		{
			*str++ = '-';
			digit *= -1;
			n *= -1;
		}
		if (n > 0)
			str = calc(n, str);
		*str = digit + '0';
	}
	return (str + 1);
}

static size_t	num_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = num_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	calc(n, str);
	str[len] = '\0';
	return (str);
}
