/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <bahommer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:00:36 by bahommer          #+#    #+#             */
/*   Updated: 2023/11/11 07:25:17 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*next;
	t_list	*current;
	void	*temp;

	if (!*begin_list)
		return ;
	current = *begin_list;
	next = current->next;
	while (current->next)
	{
		if (cmp(current->content, next->content) > 0)
		{
			temp = current->content;
			current->content = next->content;
			next->content = temp;
			current = *begin_list;
		}
		else
			current = current->next;
		next = current->next;
	}
}	
