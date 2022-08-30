/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:12:23 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/30 01:35:37 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

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

int	valid_var(char *var)
{
	int	i;

	i = 0;
	while (var[i] != '\0' && var[i] != '=')
	{
		if (!(var[i] >= 'A' && var[i] <= 'Z')
			&& !(var[i] >= 'a' && var[i] <= 'z')
			&& !(var[i] >= '0' && var[i] <= '9')
			&& !(var[i] == '_') && !(var[i] == '=')
			&& !((var[i] == '+') && (var[i + 1] == '=')))
			return (1);
		i++;
	}
	if ((var[0] >= '0' && var[0] <= '9'))
		return (1);
	if (!(var[0] >= 'A' && var[0] <= 'Z')
		&& !(var[0] >= 'a' && var[0] <= 'z')
		&& !(var[0] == '_') && (var[0] == '='))
		return (1);
	return (0);
}

void	ft_exist_var(t_cmdfinal **cmd_final, char *str)
{
	t_cmdfinal	*tmp;
	t_node		*head;
	t_vars		x;
	char		*str1;
	char		*str2;

	x.i = 0;
	x.k = 0;
	tmp = (*cmd_final);
	head = *tmp->envp;
	while (head)
	{
		str1 = ft_ret_var(head->data);
		str2 = ft_ret_var(str);
		if (ft_strcmp(str1, str2) == 0)
		{
			if (ft_search_pluse(str) == 0)
			{
				x.ptr = ft_strdup(my_strchr(str, '='));
				head->data = ft_strjoin(head->data, x.ptr);
				x.k = 1;
				free(str1);
				free(str2);
				break ;
			}
			if (ft_search(str) == 0)
			{
				free(head->data);
				head->data = ft_strdup(str);
				free(str1);
				free(str2);
			}
			x.k = 1;
			break ;
		}
		head = head->next;
		free(str1);
		free(str2);
	}
	if (x.k == 0)
		creat_node((*cmd_final)->envp, str);
}

int	check_var(t_cmdfinal **cmd_final)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if ((*cmd_final)->tab[1])
	{
		while ((*cmd_final)->tab[i])
		{
			if (valid_var((*cmd_final)->tab[i]) == 0)
			{
				ft_exist_var(cmd_final, (*cmd_final)->tab[i]);
			}
			else
			{
				printf("export: `%s': not a valid identifier\n",
					(*cmd_final)->tab[i]);
				t_global.state = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	my_export(t_cmdfinal **cmd_final)
{
	if (check_var(cmd_final) == 0)
	{
		ft_sort_env((*cmd_final)->envp, cmd_final);
		t_global.state = 0;
	}
	if (!((*cmd_final)->tab[1]))
		printlist(*(*cmd_final)->envp);
	return (0);
}