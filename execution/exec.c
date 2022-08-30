/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:28:21 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/30 01:20:08 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

void	ft_dup(t_cmdfinal *tmp, t_var *exec, int last_fd)
{
	ft_e_signals();
	ft_dup_file(tmp);
	if (last_fd != -1 && tmp->flag2 != 1)
	{
		dup2(last_fd, STDIN_FILENO);
		close(last_fd);
	}
	if (tmp->flag1 != 1 && tmp->next != NULL)
	{
		dup2(exec->fd[1], STDOUT_FILENO);
		close(exec->fd[1]);
		close(exec->fd[0]);
	}
	if (tmp->tab[0] == NULL)
		exit(0);
	if (is_builtin(tmp->tab[0]) == 0)
	{
		execute_builtin(&tmp);
		exit(t_global.state);
	}
	exec->path = ft_check_path(exec->s, tmp->tab[0]);
	if (execve(exec->path, tmp->tab, tmp->env) == -1)
		error_exe();
}

void	ft_path(t_cmdfinal *tmp, t_var *exec)
{
	if (exec->s == NULL && tmp->tab[0][0] == '/')
	{
		if (execve(tmp->tab[0], tmp->tab, tmp->env) == -1)
			error_exe();
	}
	else if (exec->s == NULL)
		fprintf(stderr, "$ minishell: %s : No such file or directory\n",
			(tmp)->tab[0]);
}

void	ft_save(t_cmdfinal *tmp, t_var *exec, int last_fd,
	t_cmdfinal **cmd_final)
{
	exec->s = ft_split(serach_path(*cmd_final), ':');
	if (exec->s == NULL && tmp->tab[0][0] == '/')
	{
		if (execve(tmp->tab[0], tmp->tab, tmp->env) == -1)
			error_exe();
	}
	else if (exec->s == NULL)
		fprintf(stderr, "$ minishell: %s : No such file or directory\n",
			(tmp)->tab[0]);
	ft_dup(tmp, exec, last_fd);
}

void	ft_cmd(t_cmdfinal **cmd_final, t_var *exec)
{
	t_cmdfinal	*tmp;
	int			last_fd;
	int			i;

	tmp = *cmd_final;
	last_fd = -1;
	i = 0;
	while (tmp)
	{
		if (ft_pipe(tmp, exec, i) == 1)
			return ;
		if (exec->child == 0)
			ft_save(tmp, exec, last_fd, cmd_final);
		else
		{
			if (tmp->next != NULL)
				close(exec->fd[1]);
			if (last_fd != -1)
				close(last_fd);
			last_fd = exec->fd[0];
		}
		i++;
		tmp = tmp->next;
	}
}

void	exec_cmd(t_cmdfinal **cmd_final)
{
	t_var	exec;
	int		i;
	int		status;

	exec.child_pids = malloc(sizeof(int) * (*cmd_final)->number_node);
	ft_cmd(cmd_final, &exec);
	i = 0;
	while (i < (*cmd_final)->number_node)
	{
		waitpid(exec.child_pids[i], &status, 0);
		if (WIFEXITED(status))
			t_global.state = WEXITSTATUS(status);
		if (status == 2)
			t_global.state = 128 + status;
		else if (status == 3)
		{
			printf("Quit: %d\n", status);
			t_global.state = 128 + status;
		}
		i++;
	}
	free(exec.child_pids);
	return ;
}