/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:29:24 by lelbakna          #+#    #+#             */
/*   Updated: 2022/09/04 10:39:36 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

void	ft_change_pwd(t_cmdfinal **cmd_final, char *path, char *oldpath)
{
	t_node		*tmp;
	t_vars		x;

	x.flag1 = 0;
	x.flag2 = 0;
	tmp = *(*cmd_final)->envp;
	x.str1 = ft_strdup("PWD=");
	x.str2 = ft_strdup("OLDPWD=");
	while (tmp)
	{
		if (ft_strncmp((tmp)->data, "OLDPWD=", 7) == 0)
		{
			free((tmp)->data);
			(tmp)->data = (ft_strjoin(x.str2, oldpath));
			x.flag1 = 1;
		}
		if (ft_strncmp((tmp)->data, "PWD=", 4) == 0)
		{
			free((tmp)->data);
			(tmp)->data = (ft_strjoin(x.str1, path));
			x.flag2 = 1;
		}
		tmp = (tmp)->next;
	}
	free_flag_cmd(&x, path, oldpath);
}

void	ft_change_to_home(t_cmdfinal **cmd_final)
{
	char		*path;
	char		*oldpath;
	char		buff[1024];
	t_vars		x;

	x.i = 0;
	x.k = 0;
	x.ptr = getcwd(buff, sizeof(buff));
	while ((*cmd_final)->env[x.i])
	{
		if (strncmp((*cmd_final)->env[x.i], "HOME=", 5) == 0)
			x.k = 1;
		x.i++;
	}
	if (ft_home(&x, cmd_final) == 0)
		return ;
	oldpath = ft_strdup(x.ptr);
	path = ft_strdup(getenv("HOME"));
	ft_change_pwd(cmd_final, path, oldpath);
	t_global.state = 0;
}

int	ft_change_directory(t_cmdfinal **cmd_final)
{
	char	*path;
	char	*oldpath;
	char	buff[1024];
	char	*str;

	str = getcwd(buff, sizeof(buff));
	if (chdir("..") != 0)
	{
		ft_putstr_fd("$ minishell: cd: ", 2);
		write(2, (*cmd_final)->tab[1], ft_strlen((*cmd_final)->tab[1]));
		ft_putendl_fd("No such file or directory", 2);
		t_global.state = 1;
		return (1);
	}
	if (str == NULL)
		return (1);
	oldpath = ft_strdup(str);
	path = ft_strdup(getcwd(buff, sizeof(buff)));
	ft_change_pwd(cmd_final, path, oldpath);
	t_global.state = 0;
	return (0);
}

int	change_directory(t_cmdfinal **cmd_final)
{
	char	*path;
	char	*oldpath;
	char	buff[1024];
	char	*str;

	str = getcwd(buff, sizeof(buff));
	if (chdir((*cmd_final)->tab[1]) != 0)
	{
		ft_putstr_fd("$ minishell: cd: ", 2);
		write(2, (*cmd_final)->tab[1], ft_strlen((*cmd_final)->tab[1]));
		ft_putendl_fd("No such file or directory", 2);
		t_global.state = 1;
		return (1);
	}
	if (str == NULL)
	{
		msg_error();
		return (1);
	}
	oldpath = ft_strdup(str);
	path = ft_strdup(getcwd(buff, sizeof(buff)));
	ft_change_pwd(cmd_final, path, oldpath);
	t_global.state = 0;
	return (0);
}

int	my_cd(t_cmdfinal **cmd_final)
{
	if (!(*cmd_final)->tab[1] || ft_strcmp((*cmd_final)->tab[1], "~") == 0)
		ft_change_to_home(cmd_final);
	else if (!ft_strcmp((*cmd_final)->tab[1], ".."))
	{
		if (ft_change_directory(cmd_final) == 1)
			return (0);
	}
	else
	{
		if (change_directory(cmd_final) == 1)
			return (0);
	}
	return (0);
}
