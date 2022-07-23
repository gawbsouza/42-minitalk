/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:24:06 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/30 23:22:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{	
	void	*ptr;
	size_t	ptr_size;

	ptr_size = nmemb * size;
	if (ptr_size != 0 && ptr_size / nmemb != size)
		return (NULL);
	ptr = malloc(ptr_size);
	if (ptr != NULL)
		ft_bzero(ptr, ptr_size);
	return (ptr);
}
