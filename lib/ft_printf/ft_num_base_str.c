/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_base_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:17:36 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/25 10:59:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*build_str(const char *buff)
{
	char	*str;
	size_t	len;
	size_t	pos;

	len = ft_strlen(buff);
	pos = 0;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str != NULL)
	{
		while (len--)
			str[pos++] = buff[len];
		str[pos] = '\0';
	}
	return (str);
}

char	*ft_num_base_str(long long int n, int signal, char *base)
{
	unsigned long long int	num;
	char					buff[32];
	int						negative;
	size_t					radix;
	size_t					pos;

	radix = ft_strlen(base);
	if (radix == 0)
		return (NULL);
	pos = 0;
	num = n;
	negative = (signal && n < 0);
	if (negative)
		num = -n;
	while (num)
	{
		buff[pos++] = base[num % radix];
		num /= radix;
	}
	if (pos == 0)
		buff[pos++] = base[0];
	if (negative)
		buff[pos++] = '-';
	buff[pos] = '\0';
	return (build_str(buff));
}
