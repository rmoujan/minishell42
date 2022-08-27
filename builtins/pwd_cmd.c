/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:36:33 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 18:54:06 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

void	ft_pwd(t_cmdfinal **cmd_final)
{
	t_cmdfinal *tmp;
	tmp = *cmd_final;
	char *ptr;
	int	i;
	i = 0;
	// if (t_global.c == 0)
	// {
		while (tmp->env[i])
			{
				if (strncmp(tmp->env[i], "PWD=", 4) == 0)
				{
					ptr =ft_strdup(ft_strchr(tmp->env[i], '='));
						ptr = ft_strtrim(ptr, "PWD=");
					t_global.g_pwd = ptr;
					break;
				}
				i++;
			}
	// 	t_global.c = 1;
	// }
}
int	my_pwd(t_cmdfinal **cmd_final)
{
	(void)cmd_final;
	char	pwd[1024];
	char	*str;
	char *tmp ;
	int 	i;
	ft_pwd(cmd_final);
	str = getcwd(pwd, sizeof(pwd));
	if (!str)
	{
		tmp = t_global.g_pwd;
		printf("**%s\n", tmp);// remove **
		free(t_global.g_pwd);
	}
	else
		printf("%s\n", str);
	i = 0;
	while ((*cmd_final)->tab[i] != '\0')
	{
		free((*cmd_final)->tab[i]);
		i++;
	}
	free((*cmd_final)->tab);// check free
	free(t_global.g_pwd);// check free
		return (1);
}
// check arg after cmd "pwd" in zsh ==>exit 1
