/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:14:23 by bahommer          #+#    #+#             */
/*   Updated: 2023/05/30 14:11:26 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_classic(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	else if (!*lst)
		*lst = new;
	else
		new->next = *lst;
	*lst = new;
}
