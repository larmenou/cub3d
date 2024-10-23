/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:52:37 by bahommer          #+#    #+#             */
/*   Updated: 2023/05/30 14:09:39 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_classic(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	else if (!*lst)
		*lst = new;
	else
		ft_lstlast_classic(*lst)->next = new;
}
