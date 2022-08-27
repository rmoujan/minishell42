/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:06:17 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 18:51:13 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"
void	free_tab(t_cmdfinal **cmd_final)
{
	int i;
	i = 0;
	while ((*cmd_final)->tab[i] != '\0')
	{
		free((*cmd_final)->tab[i]);
		i++;
	}
	free((*cmd_final)->tab);
}
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
	t_node *out;
	int	i;
	int	k;

	i = 0;
	k = 1;
	// if ((*cmd_final)->envp)
	while ((*cmd_final)->env[i])
	{
		if (strncmp((*cmd_final)->env[i], "PATH", 4) == 0)
			k = 1;
		i++;
	}
	if (k == 0)
	{
		perror("minishell: env");
			t_global.state = 127;
			return(1);
	}
	out = *((*cmd_final)->envp);
	
	if (!(*cmd_final)->tab[1])
		print_list(out);
	else
	{
		fprintf(stderr, "$ minishell: %s : No such file or directory\n", (*cmd_final)->tab[1]);
	}
	// free_tab(cmd_final);
	return (0);
}


