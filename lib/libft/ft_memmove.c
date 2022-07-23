/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:07:56 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/28 17:46:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*tmp;

	tmp = dst;
	while (n--)
	{
		if (dst < src)
			*(char *) tmp++ = *(char *) src++;
		else
			*(char *)(dst + n) = *(char *)(src + n);
	}
	return (dst);
}
