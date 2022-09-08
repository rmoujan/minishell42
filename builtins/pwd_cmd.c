/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:36:33 by lelbakna          #+#    #+#             */
/*   Updated: 2022/09/04 09:01:36 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

int	ft_pwd(t_cmdfinal **cmd_final)
{
	t_cmdfinal	*tmp;
	char		*ptr;
	int			i;

	tmp = *cmd_final;
	ptr = NULL;
	i = 0;
	while (tmp->env[i])
	{
		if (strncmp(tmp->env[i], "PWD=", 4) == 0)
		{
			ptr = ft_strdup(ft_strchr(tmp->env[i], '='));
				ptr = ft_strtrim(ptr, "PWD=");
			t_global.g_pwd = ptr;
			return (0);
		}
		i++;
		if (ptr != NULL)
		{
			free(ptr);
		}
	}
	return (1);
}

void	free_mypwd(char *str)
{
	printf("%s\n", str);
	if (t_global.g_pwd != NULL)
	{
		free (t_global.g_pwd);
		t_global.g_pwd = NULL;
	}
}

int	my_pwd(t_cmdfinal **cmd_final)
{
	char	pwd[1024];
	char	*str;

	ft_pwd(cmd_final);
	str = getcwd(pwd, sizeof(pwd));
	if (!str)
	{
		if (t_global.g_pwd == NULL)
		{
			printf("PWD DOES NOT EXISTE!!\n");
			t_global.state = 0;
			return (0);
		}
		printf("%s\n", t_global.g_pwd);
		if (t_global.g_pwd != NULL)
		{
			free (t_global.g_pwd);
			t_global.g_pwd = NULL;
		}
	}
	else
		free_mypwd(str);
	t_global.state = 0;
	return (1);
}
