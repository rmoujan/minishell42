/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:29:24 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 18:46:24 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

void ft_change_pwd(t_cmdfinal **cmd_final, char *path, char *oldpath)
{
	t_cmdfinal	*tmp;
	char		*ptr1;
	char		*ptr2;

	tmp = (*cmd_final);
	ptr1 = ft_strdup("PWD=");
	ptr2 = ft_strdup("OLDPWD=");
	while (tmp->envp)
	{
		if (ft_strncmp((*tmp->envp)->data, "OLDPWD=", 7) == 0)
			(*tmp->envp)->data = ft_strdup(ft_strjoin(ptr2, oldpath));
		if (ft_strncmp((*tmp->envp)->data, "PWD=", 4) == 0)
			(*tmp->envp)->data = ft_strdup(ft_strjoin(ptr1, path));
		*tmp->envp = (*tmp->envp)->next;
	}
}

int	my_cd(t_cmdfinal **cmd_final)
{
	char	*path;
	char	*oldpath;
	char	buff[1024];
	char	*str;
	if (!(*cmd_final)->tab[1] || ft_strcmp((*cmd_final)->tab[1], "~") == 0)
	{
		if (chdir(getenv("HOME")) != 0 )
		{
			fprintf(stderr, "$ minishell: cd: %s :", (*cmd_final)->tab[1]);
			ft_putendl_fd("No such file or directory", 2);
		}
		oldpath = ft_strdup(getcwd(buff, sizeof(buff)));
		path =ft_strdup(getenv("HOME"));
		ft_change_pwd(cmd_final, path, oldpath);
	}
	else if (!ft_strcmp((*cmd_final)->tab[1], ".."))
	{
		str = getcwd(buff, sizeof(buff));
		if (chdir("..") != 0 )
		{
			fprintf(stderr, "$ minishell: cd: %s :", (*cmd_final)->tab[1]);
			ft_putendl_fd("No such file or directory", 2);
		}
		if (str == NULL)
		{
			write(2, "cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n", 108);
			return(0);
		}
		oldpath = ft_strdup(str);
		path = ft_strdup(getcwd(buff, sizeof(buff)));
		ft_change_pwd(cmd_final, path, oldpath);
	}
	else
	{
		str = getcwd(buff, sizeof(buff));
		if (chdir((*cmd_final)->tab[1]) != 0 )
		{
			fprintf(stderr, "$ minishell: cd: %s :", (*cmd_final)->tab[1]);
			ft_putendl_fd("No such file or directory", 2);
		}
		if (str == NULL)
		{
			write(2, "cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n", 108);
			return(0);
		}
		oldpath = ft_strdup(str);
		path = ft_strdup(getcwd(buff, sizeof(buff)));
		ft_change_pwd(cmd_final, path, oldpath);
	}
	return(0);
}