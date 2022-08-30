/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:06:31 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/30 02:38:01 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) + 1 * sizeof(char));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '/';
	i++;
	j = 0;
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

char	*serach_path(t_cmdfinal *cmd_final)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd_final->env[i])
	{
		if (ft_strcmp(cmd_final->env[i], "PATH=") == 0)
		{
			while (cmd_final->env[i][j])
			{
				if (cmd_final->env[i][j] == '=')
					return ((char *)&cmd_final->env[i][++j]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

char	*ft_check_path(char **path, char *cmd)
{
	int		i;
	char	*p;

	i = 0;
	while (path[i])
	{
		p = ft_strjoin(path[i], cmd);
		if (access(p, F_OK) == 0)
			return (p);
		free(p);
		p = NULL;
		i++;
	}
	return (cmd);
}
