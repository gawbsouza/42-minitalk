/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:03:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/28 17:45:20 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new != NULL && lst->next != NULL)
	{
		new->next = ft_lstmap(lst->next, f, del);
		if (!new->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
	}
	return (new);
}
