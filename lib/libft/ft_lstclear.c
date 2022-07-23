/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 08:37:12 by gasouza           #+#    #+#             */
/*   Updated: 2022/04/23 15:39:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*tmp;

	if (lst == NULL)
		return ;
	tmp = *lst;
	if (tmp->next != NULL)
		ft_lstclear(&tmp->next, del);
	ft_lstdelone(tmp, del);
	*lst = NULL;
}
