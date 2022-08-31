/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:36:33 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/31 03:29:26 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

void	ft_pwd(t_cmdfinal **cmd_final)
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
			break ;
		}
		i++;
		if (ptr)
			free(ptr);
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
		printf("%s\n", t_global.g_pwd);
		// free(t_global.g_pwd); !!
	}
	else
	{
		printf("%s\n", str);
		free (t_global.g_pwd);
	}
	t_global.state = 0;
	return (1);
}
