/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <bahommer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:31:20 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/11 07:25:51 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_no_remove(t_list **prev, t_list **current)
{
	*prev = *current;
	*current = (*current)->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *begin_list;
	while (current)
	{
		if (cmp(current->content, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = current->next;
			else
				prev->next = current->next;
			free_fct(current->content);
			free(current);
			if (!prev)
				current = *begin_list;
			else
				current = prev->next;
		}
		else
			ft_no_remove(&prev, &current);
	}
}
