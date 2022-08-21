/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:06:17 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/21 16:36:10 by lelbakna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"
int	ft_search(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return(0);
		i++;
	}
	return(1);
}

void	print_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	if (temp == NULL)
		printf("empty");
	while (temp)
	{
		if (ft_search(temp->data) == 0)
			printf("%s\n", temp->data);
		temp = temp->next;
	}
}

int	my_env(t_cmdfinal **cmd_final)
{
	(void)cmd_final;
	// if ((*cmd_final)->envp)
	print_list((*cmd_final)->envp);
	// printf("done");
	return (0);
}

