/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:40 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/27 08:51:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;

	if (!*little)
		return ((char *) big);
	size = ft_strlen(little);
	while (len-- >= size && *big)
	{
		if (ft_strncmp(big, little, size) == 0)
			return ((char *) big);
		big++;
	}
	return (NULL);
}
