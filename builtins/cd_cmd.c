/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:29:24 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/20 16:51:23 by lelbakna         ###   ########.fr       */
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
		if (ft_strncmp(tmp->envp->data, "OLDPWD=", 7) == 0)
			tmp->envp->data = ft_strdup(ft_strjoin(ptr2, oldpath));
		if (ft_strncmp(tmp->envp->data, "PWD=", 4) == 0)
			tmp->envp->data = ft_strdup(ft_strjoin(ptr1, path));
		tmp->envp = tmp->envp->next;
	}
}

int	my_cd(t_cmdfinal **cmd_final)
{
	char	*path;
	char	*oldpath;
	char	buff[1024];

	if (!(*cmd_final)->tab[1] || ft_strcmp((*cmd_final)->tab[1], "~") == 0)
	{
		oldpath = ft_strdup(getcwd(buff, sizeof(buff)));
		path =ft_strdup(getenv("HOME"));
		if (chdir(getenv("HOME")) != 0 )
		{
			fprintf(stderr, "$ minishell: cd: %s :", (*cmd_final)->tab[1]);
			ft_putendl_fd("No such file or directory", 2);
		}
		ft_change_pwd(cmd_final, path, oldpath);
	}
	else if (!ft_strcmp((*cmd_final)->tab[1], ".."))
	{
		oldpath = ft_strdup(getcwd(buff, sizeof(buff)));
		if (chdir("..") != 0 )
		{
			fprintf(stderr, "$ minishell: cd: %s :", (*cmd_final)->tab[1]);
			ft_putendl_fd("No such file or directory", 2);
		}
		path = ft_strdup(getcwd(buff, sizeof(buff)));
		ft_change_pwd(cmd_final, path, oldpath);
	}
	else
	{
		oldpath = ft_strdup(getcwd(buff, sizeof(buff)));
		if (chdir((*cmd_final)->tab[1]) != 0 )
		{
			fprintf(stderr, "$ minishell: cd: %s :", (*cmd_final)->tab[1]);
			ft_putendl_fd("No such file or directory", 2);
		}
		path = ft_strdup(getcwd(buff, sizeof(buff)));
		ft_change_pwd(cmd_final, path, oldpath);
	}
	return(0);
}
