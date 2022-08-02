/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:29:17 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 15:55:16 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void ft_del(void *elm)
{
	free(elm);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*var;

	var = *lst;
	if (!lst)
		return ;
	if (!*lst || !del)
		return ;
	while (var != NULL)
	{
		del(var->content);
		tmp = var->next;
		free(var);
		var = tmp;
	}
	*lst = NULL;
}
