/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:13:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/28 10:20:45 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**resize(char **old, char *str)
{
	char	**new;
	size_t	size;

	size = 0;
	while (old && old[size] != NULL)
		size++;
	new = (char **) malloc((size + 2) * sizeof(char *));
	if (new != NULL)
	{
		new[size] = str;
		new[size + 1] = NULL;
		while (size--)
			new[size] = old[size];
		if (old != NULL)
			free(old);
	}
	return (new);
}

char	**ft_split(const char *s, char c)
{
	char	**new;
	size_t	len;

	new = (char **) malloc(sizeof(char *));
	if (new != NULL)
	{
		*new = NULL;
		while (s && *s)
		{
			while (*s && *s == c)
				s++;
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (len)
			{
				new = resize(new, ft_substr(s, 0, len));
				s += len;
			}
		}	
	}
	return (new);
}
