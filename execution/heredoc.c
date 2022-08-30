/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:07:55 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 18:26:09 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int	ft_read_from_heredoc(t_cmdfinal *tmp, char *name, char **av)
{
	char	*read_in;

	while (1)
	{
		read_in = readline("> ");
		if (!check_herdoc(read_in))
		{
			free(read_in);
			return (0);
		}
		if (check_herdoc(read_in) == 1 || !ft_strcmp(read_in, name))
		{
			free(read_in);
			break ;
		}
		if (check_dollar(read_in) != 0)
			read_in = expand_dollar(read_in, tmp->env, av);
		ft_putendl_fd(read_in, tmp->fdhere[1]);
		free(read_in);
	}
	close(tmp->fdhere[1]);
	dup2(tmp->save[1], 1);
	return (1);
}

int	ft_check_heredoc(t_cmdfinal *cmd_final, char **av)
{
	t_cmdfinal	*tmp;
	t_files		*file;

	tmp = cmd_final;
	while (tmp)
	{
		file = tmp->file;
		while (file != NULL)
		{
			if (file->id == 3)
			{
				t_global.herdoc = 1;
				if (pipe(tmp->fdhere) < 0)
					perror("pipe");
				if (!ft_read_from_heredoc(tmp, file->name, av))
					return (0);
			}
			t_global.herdoc = 0;
			file = file->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_dup_file(t_cmdfinal *cmd_final)
{
	if (ft_openfile(cmd_final) == 1)
		return (1);
	return (0);
}

int	ft_pipe(t_cmdfinal *tmp, t_var *exec, int i)
{
	if (tmp->next != NULL)
		if (pipe(exec->fd) < 0)
			perror("pipe");
		exec->child = fork();
		exec->child_pids[i] = exec->child;
	if (exec->child < 0)
	{
		write(2, "$ minishell: fork: Resource temporarily unavailable\n", 52);
		return (1);
	}
	return (0);
}
