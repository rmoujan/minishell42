/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:06:17 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/30 23:37:38 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

void	free_tab(t_cmdfinal **cmd_final)
{
	int			i;
	t_cmdfinal	*tmp;

	tmp = *cmd_final;
	while (tmp)
	{
		i = 0;
		while ((tmp)->tab[i] != '\0')
		{
			free((tmp)->tab[i]);
			i++;
		}
		free((tmp)->tab);
		tmp = tmp->next;
	}
}

int	ft_search(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	print_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	if (temp == NULL)
		printf("empty");//**
	while (temp)
	{
		if (ft_search(temp->data) == 0)
			printf("%s\n", temp->data);
		temp = temp->next;
	}
}

int	my_env(t_cmdfinal **cmd_final)
{
	t_node	*out;
	t_vars	x;

	x.i = 0;
	x.k = 1;
	while ((*cmd_final)->env[x.i])
	{
		if (strncmp((*cmd_final)->env[x.i], "PATH", 4) == 0)
			x.k = 1;
		x.i++;
	}
	if (x.k == 0)
	{
		perror("minishell: env");
			t_global.state = 127;
		return (1);
	}
	out = *((*cmd_final)->envp);
	if (!(*cmd_final)->tab[1])
		print_list(out);
	else
		fprintf(stderr, "$ minishell: %s : No such file or directory\n",
			(*cmd_final)->tab[1]);
	t_global.state = 0;
	return (0);
}
