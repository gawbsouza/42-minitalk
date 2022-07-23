/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 03:05:18 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/27 15:22:55 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = (char *) malloc(len + 1 * sizeof(char));
	if (new == NULL)
		return (NULL);
	if (len > 0)
		ft_memmove(new, s, len);
	new[len] = '\0';
	return (new);
}
