/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:28:21 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 16:10:26 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int check_herdoc(char *str);
void	ft_openfile(t_cmdfinal *tmp)
{
	t_cmdfinal	*cmd_final;
	t_files *file;

	cmd_final = tmp;
	cmd_final->infile = -1;
	cmd_final->outfile = -1;
	cmd_final->flag1 = 0;
	cmd_final->flag2 = 0;
	file = cmd_final->file;
	while (file != NULL)
	{
		if (file->id == 3)
		{
			cmd_final->flag2 = 1;
			if (dup2(t_global.fd[0], 0) < 0)// check  return dup2
				ft_str_error("Failed to redirect stdin\n", NULL);
			// close(cmd_final->fd[0]);
			// close(cmd_final->fd[1]);
		}
		else if (file->id == 1)
		{
			cmd_final->infile = open(file->name, O_RDONLY);
			if (cmd_final->infile == -1)
				ft_str_error("Failed to redirect stdin.\n", file->name);
				cmd_final->flag2 = 1;
			if (dup2(cmd_final->infile, 0) < 0)
				ft_str_error("Failed to redirect stdin.\n", NULL);
			close(cmd_final->infile);
		}
		else if (file->id == 2)
		{
			cmd_final->outfile = open(file->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (cmd_final->outfile == -1)
				ft_str_error("Failed to redirect stdout.\n", file->name);
				cmd_final->flag1 = 1;
			if (dup2(cmd_final->outfile, 1) < 0)
				ft_str_error("Failed to redirect stdout.\n", NULL);
			close(cmd_final->outfile);
		}
		else if (file->id == 4)
		{
			cmd_final->outfile = open(file->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (cmd_final->outfile == -1)
				ft_str_error("Failed to redirect stdout.", file->name);
			cmd_final->flag1 = 1;
			if (dup2(cmd_final->outfile, 1) < 0)
				ft_str_error("Failed to redirect stdout", NULL);
			close(cmd_final->outfile);
		}
		file = file->next;
	}
}

int	ft_read_from_heredoc(t_cmdfinal *tmp, char *name)
{
	char *read_in;
	(void)tmp;
	while (1)
	{
		read_in = readline("> ");
		if (!check_herdoc(read_in))
			return (0);
		if(check_herdoc(read_in) == 1 || !ft_strcmp(read_in, name))
			break;
		ft_putendl_fd(read_in, t_global.fd[1]);
		free(read_in);
	}
	close(t_global.fd[1]);
	//close(t_global.fd[0]);
	//dup2(tmp->save[1], 1);
	// dup2(cmd_final->save[0], 0);
	free(read_in);
	return (1);
}

int	ft_check_heredoc(t_cmdfinal *cmd_final)
{
	t_cmdfinal	*tmp;
	t_files *file;

	tmp = cmd_final;
	while (tmp)
	{
		file = tmp->file;
		while (file != NULL)
		{
			if (file->id == 3)
			{
				t_global.herdoc = 1;
				if (pipe(t_global.fd) < 0)
					perror("pipe");
				if(!ft_read_from_heredoc(tmp, file->name))
					return (0);
			}
			t_global.herdoc = 0;
			file = file->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_dup_file(t_cmdfinal *cmd_final)
{
	ft_openfile(cmd_final);// open file before dupli..
	return ;
}

void	ft_cmd(t_cmdfinal **cmd_final, t_var *exec)
{
	t_cmdfinal	*tmp;
	int		last_fd;
	int		i;
	
	tmp = *cmd_final;
	last_fd = -1;
	i = 0;
	exec->s = ft_split(serach_path(*cmd_final), ':');
	exec->child_pids = malloc(sizeof(int) * (*cmd_final)->number_node);
	while (tmp)
	{
		if (tmp->next != NULL)
			if (pipe(exec->fd) < 0)
				perror("pipe");
		exec->child = fork();
		exec->child_pids[i] = exec->child;
		if (exec->child < 0)
			ft_str_error("Failed Fork", NULL);
		if (exec->child == 0)
		{
			ft_e_signals();
			ft_dup_file(tmp);
			if (last_fd != -1 && tmp->flag2 != 1)
			{
				dup2(last_fd,STDIN_FILENO);
				close(last_fd);
			}
			if (tmp->flag1 != 1 && tmp->next != NULL)
			{
				dup2(exec->fd[1],STDOUT_FILENO);
				close(exec->fd[1]);
				close(exec->fd[0]);
			}
			if (tmp->tab[0] == NULL)// check vide heredoc
				exit(0);
			if (is_builtin(tmp->tab[0]) == 0)
			{
				// fprintf(stderr, "export  %s\n", tmp->tab[0]);
				execute_builtin(&tmp);
				exit(0);
			}
			// close(exec->fd[0]);
			exec->cmd = tmp->tab;
			exec->path = ft_check_path(exec->s, exec->cmd[0]);
			if (execve(exec->path, exec->cmd, tmp->env) == -1) // check env
			{
				// fprintf(stderr,"cmd %s\n", tmp->cmd[0]);
				// fprintf(stderr,"env %s\n", tmp->env[0]);
				// fprintf(stderr,"path %s\n", exec->path);
				error_exe();
			}
			
		}
		else
		{
			if (tmp->next != NULL)
				close(exec->fd[1]);
			if (last_fd != -1)
				close(last_fd);
			last_fd = exec->fd[0];
			// if (tmp->next != NULL)
			// 	close(exec->fd[0]);
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
	
	ft_cmd(cmd_final, &exec);
	// close(0); // check
	i = 0;
	while (i < (*cmd_final)->number_node)
	{
		waitpid(exec.child_pids[i], &status, 0);
				if (WIFEXITED(status))
					t_global.state = WEXITSTATUS(status);
		i++;
	}
	
	return ;
}