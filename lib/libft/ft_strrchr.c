/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:31:57 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/26 17:10:28 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*end;

	end = ft_strchr(str, '\0');
	while (end > str && *end != (char) c)
		end--;
	if (*end == (char) c)
		return (end);
	return (NULL);
}
