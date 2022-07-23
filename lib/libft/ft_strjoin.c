/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:41:32 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/27 21:30:37 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*new;
	char	*tmp;

	size = ft_strlen(s1);
	size += ft_strlen(s2);
	new = (char *) malloc((size + 1) * sizeof(char));
	if (new != NULL)
	{
		tmp = new;
		while (*s1)
			*tmp++ = *s1++;
		while (*s2)
			*tmp++ = *s2++;
		*tmp = '\0';
	}
	return (new);
}
