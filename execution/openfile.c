/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:47:43 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/31 23:08:28 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

void	ft_heredoc(t_cmdfinal *cmd_final)
{
	cmd_final->flag2 = 1;
	if (dup2(cmd_final->fdhere[0], 0) < 0)
		ft_str_error("Failed to redirect stdin\n", NULL);
	t_global.state = 0;
}

int	infile(t_cmdfinal *cmd_final, t_files *file)
{
	cmd_final->infile = open(file->name, O_RDONLY);
	if (cmd_final->infile == -1)
	{
		if (is_builtin((cmd_final)->tab[0]) == 0 && cmd_final->next == NULL)
			ft_errors_red("Failed to redirect stdin.\n", file->name);
		else
			ft_str_error("Failed to redirect stdin.\n", file->name);
		return (1);
	}
		cmd_final->flag2 = 1;
	if (dup2(cmd_final->infile, 0) < 0)
		ft_str_error("Failed to redirect stdin.\n", NULL);
	t_global.state = 0;
	close(cmd_final->infile);
	return (0);
}

int	outfile(t_cmdfinal *cmd_final, t_files *file)
{
	cmd_final->outfile = open(file->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd_final->outfile == -1)
	{
		if (is_builtin((cmd_final)->tab[0]) == 0 && cmd_final->next == NULL)
			ft_errors_red("Failed to redirect stdout.\n", file->name);
		else
			ft_str_error("Failed to redirect stdout.\n", file->name);
		return (1);
	}
		cmd_final->flag1 = 1;
	if (dup2(cmd_final->outfile, 1) < 0)
		ft_str_error("Failed to redirect stdout.\n", NULL);
	t_global.state = 0;
	close(cmd_final->outfile);
	return (0);
}

int	ft_append(t_cmdfinal *cmd_final, t_files *file)
{
	cmd_final->outfile = open(file->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd_final->outfile == -1)
	{
		if (is_builtin((cmd_final)->tab[0]) == 0 && cmd_final->next == NULL)
			ft_errors_red("Failed to redirect stdout.\n", file->name);
		else
			ft_str_error("Failed to redirect stdout.\n", file->name);
		return (1);
	}
	cmd_final->flag1 = 1;
	if (dup2(cmd_final->outfile, 1) < 0)
		ft_str_error("Failed to redirect stdout", NULL);
	t_global.state = 0;
	close(cmd_final->outfile);
	return (0);
}

int	ft_openfile(t_cmdfinal *tmp)
{
	t_cmdfinal	*cmd_final;
	t_files		*file;

	cmd_final = tmp;
	cmd_final->infile = -1;
	cmd_final->outfile = -1;
	cmd_final->flag1 = 0;
	cmd_final->flag2 = 0;
	file = cmd_final->file;
	while (file != NULL)
	{
		if (file->id == 3)
			ft_heredoc(cmd_final);
		else if (file->id == 1)
			infile(cmd_final, file);
		else if (file->id == 2)
		{
			if (outfile(cmd_final, file) == 1)
				return (1);
		}
		else if (file->id == 4)
			ft_append(cmd_final, file);
		file = file->next;
	}
	return (0);
}
