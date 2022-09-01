/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdcmd_complement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:43:24 by rmoujan           #+#    #+#             */
/*   Updated: 2022/09/01 18:49:26 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

char	*ft_get_pwd(t_cmdfinal **cmd_final)
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
			return (ptr);
		}
		i++;
		if (ptr)
			free(ptr);
	}
	return (NULL);
}

int	ft_home(t_vars *x, t_cmdfinal **cmd_final)
{
	if (chdir(getenv("HOME")) != 0 || x->k == 0)
	{
		t_global.state = 1;
		ft_putendl_fd("$ minishell: cd: HOME not set", 2);
		return (0);
	}
	if (x->ptr == NULL)
	{
		x->str3 = ft_get_pwd(cmd_final);
		x->ptr = x->str3;
		free(x->str3);
	}
	return (1);
}

void	msg_error(void)
{
	write(2, "cd: error retrieving current directory: getcwd: cannot", 54);
	write(2, " access parent directories: No such file or directory\n", 55);
}
