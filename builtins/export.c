/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:39:49 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 02:57:53 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

int	ft_cmp(char *str)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 1;
	while (str[i])
	{
		if (ft_search_pluse(str) == 0)
		{
			if (str[i + 1] == '+')
			{
				break ;
			}
		}
		if (str[i + 1] == '=')
		{
			break ;
		}
			cmp++;
		i++;
	}
	return (cmp);
}

void	ft_sort_env(t_node **head, t_cmdfinal **cmd_final)
{
	t_node	*temp;
	t_node	*tmp;
	char	*max;

	temp = *head;
	tmp = *head;
	while (tmp != NULL)
	{
		temp = *head;
		while (temp->next != NULL)
		{
			if (ft_strcmp(temp->data, temp->next->data) > 0)
			{
				max = temp->data;
				temp->data = temp->next->data;
				temp->next->data = max;
			}
			temp = temp->next;
		}
		tmp = tmp->next;
	}
	*(*cmd_final)->envp = *head;
}
