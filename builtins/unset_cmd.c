/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:05:27 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/30 21:03:31 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

int	size_env(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

void	search_first(t_cmdfinal **cmd_final, int i)
{
	t_node	*temp;
	t_node	*tmp;

	tmp = *(*cmd_final)->envp;
	if (tmp == NULL)
		return ;
	if (ft_strncmp(tmp->data, (*cmd_final)->tab[i], size_env(tmp->data)) == 0)
	{
		temp = tmp;
		tmp = tmp->next;
		*(*cmd_final)->envp = tmp;
	}
}
 
int	check_empty_str(char *str)
{
	if (str[0] == '\0')
	{
		printf("bash: unset: `': not a valid identifier\n");
		t_global.state = 1;
		return (1);
	}
	return (0);
}

void	search(t_cmdfinal **cmd_final)
{
	int		i;
	t_node	*tmp;
	t_node	*temp;

	i = 1;
	while ((*cmd_final)->tab[i])
	{
		if (check_empty_str((*cmd_final)->tab[i]))
			return ;
		search_first(cmd_final, i);
		tmp = *(*cmd_final)->envp;
		while (tmp && tmp->next != NULL)
		{
			if (ft_strncmp(tmp->next->data, (*cmd_final)->tab[i],
					size_env(tmp->next->data)) == 0)
			{
				temp = tmp->next->next;
				free(tmp->next->data);
				free(tmp->next);
				tmp->next = temp;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

int	my_unset(t_cmdfinal **cmd_final)
{
	search(cmd_final);
	t_global.state = 0;
	return (0);
}
