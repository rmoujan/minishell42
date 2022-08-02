/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:25:58 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 16:09:29 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t1;

	t1 = (t_list *) malloc(sizeof(t_list));
	if (t1 != NULL)
	{
		t1->content = content;
		t1->next = NULL;
		return (t1);
	}
	return (NULL);
}
