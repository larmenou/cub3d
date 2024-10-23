/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:58:23 by bahommer          #+#    #+#             */
/*   Updated: 2023/05/30 14:10:26 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_classic(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	tmp = lst;
	while (tmp)
	{
		current = ft_lstnew_classic(f(tmp->content));
		if (!current)
		{
			ft_lstclear_classic(&lst, del);
			ft_lstclear_classic(&new, del);
			return (NULL);
		}
		ft_lstadd_back_classic(&new, current);
		tmp = tmp->next;
	}
	ft_lstclear_classic(&lst, del);
	return (new);
}
