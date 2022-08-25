/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redrectionserror.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:25:35 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/25 09:33:51 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"


int	compare_redrections(char *str)
{
	if (strcmp(str, "<") == 0 || strcmp(str, ">") == 0
		|| strcmp(str, "<<") == 0 || strcmp(str, ">>") == 0
		|| strcmp(str, "><") == 0 || strcmp(str, "<>") == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_red(char *str1, char *str2)
{
	if (compare_redrections(str1) == 1)
	{
		if (compare_redrections(str2) == 1)
			return (1);
	}
	if (strcmp(str1, "<>") == 0 || strcmp(str1, "><") == 0)
	{
		return (1);
	}
	return (0);
}

int	chunk_checkredrections(t_token *save, t_command *tmp)
{
	if (tmp->data->next != NULL)
	{
		if (ft_red(tmp->data->token, tmp->data->next->token) == 1)
		{
			tmp->data = save;
			ft_errno(3);
			return (-1);
		}
	}
	else if (compare_redrections(tmp->data->token) == 1)
	{
		tmp->data = save;
		ft_errno(3);
		return (-1);
	}
	return (0);
}

//17lines !!!
int	ft_checkredrections(t_command *head)
{
	t_command	*tmp;
	t_token		*save;

	tmp = head;
	while (tmp)
	{
		save = tmp->data;
		while (tmp->data)
		{
			if (chunk_checkredrections(save, tmp) == -1)
				return (-1);
			tmp->data = tmp->data->next;
		}
		tmp->data = save;
		tmp = tmp->next;
	}
	return (0);
}
