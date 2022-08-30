/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:13:34 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/29 01:21:48 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
//new norm
void	free_node(t_command *head)
{
	t_command	*tmp;
	t_token		*token;

	while (head)
	{
		tmp = head;
		while (head->data)
		{
			token = head->data->next;
			free(head->data->token);
			free(head->data);
			head->data = token;
		}
		head = tmp->next;
		free(tmp);
	}
}

void	free_lines(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_cmdfinal(t_cmdfinal *cmd)
{
	t_files		*tmp;
	t_cmdfinal	*pointer;
	t_cmdfinal	*fr;

	if (cmd->env)
		free(cmd->env);
	while (cmd != NULL)
	{
		pointer = cmd;
		fr = cmd;
		free_lines(cmd->tab);
		while (cmd->file)
		{
			tmp = cmd->file->next;
			free(cmd->file->name);
			free(cmd->file);
			cmd->file = tmp;
		}
		cmd = pointer->next;
		free(fr);
	}
}
