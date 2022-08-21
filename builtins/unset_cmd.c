/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:05:27 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/21 16:46:18 by lelbakna         ###   ########.fr       */
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

	tmp = (*cmd_final)->envp;
	if (ft_strncmp(tmp->data, (*cmd_final)->tab[i], size_env(tmp->data)) == 0)
	{
		temp = tmp;
		tmp = tmp->next;
		(*cmd_final)->envp = tmp;
		free(temp);
	}
}

void	search(t_cmdfinal **cmd_final)
{
	int		i;
	t_node	*tmp;
	t_node	*temp;

	i = 1;
	while ((*cmd_final)->tab[i])
	{
		search_first(cmd_final, i);
		tmp = (*cmd_final)->envp;
		while (tmp && tmp->next != NULL)
		{
			if (ft_strncmp(tmp->next->data, (*cmd_final)->tab[i],
					size_env(tmp->next->data)) == 0)
			{
				temp = tmp->next->next;
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
	return (0);
}
//handle case of lowercase
//exit(1); {if (!av[2])}
// //exit(1); {if (!av[2])}