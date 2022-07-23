/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:37:29 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/27 18:16:40 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	size;

	if (!*s || start > ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	new = (char *) malloc((size + 1) * sizeof(char));
	if (new != NULL)
		ft_strlcpy(new, s + start, size + 1);
	return (new);
}
