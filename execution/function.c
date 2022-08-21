/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:06:31 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/07 17:55:55 by lelbakna         ###   ########.fr       */
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
char	*ft_strchr(const char *s, int c)
{
	size_t	i ;

	if (!s)
		return ((char *)ft_strlen(s));
	if (c == '\0')
		return ((char *)(&s[ft_strlen(s)]));
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
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


// void	ft_chek_cmd_p1(char *str, t_chek *v)
// {
// 	v->i = 0;
// 	v->j = 0;
// 	v->tmp = 0;
// 	v->k = 0;
// 	v->g = 0;
// 	while (str[v->i])
// 	{
// 		if (str[v->i] == '\'' && v->k == 0)
// 		{
// 			v->j++;
// 			v->tmp = v->j;
// 		}
// 		if (str[v->i] != '\'' && v->j != 0)
// 			v->k = 1;
// 		if (str[v->i] == '\'' && v->k == 1)
// 			v->j--;
// 		v->i++;
// 	}
// }

// char	*ft_chek_cmd(char *str)
// {
// 	t_chek	v;

// 	v.g = 0;
// 	ft_chek_cmd_p1(str, &v);
// 	if (v.tmp == 0)
// 		return (str);
// 	if (v.j != 0)
// 		exit(1);
// 	else
// 	{
// 		v.g = (((ft_strlen(str)) - (2 * v.tmp)) + 1);
// 		v.ptr = malloc ((sizeof(char) * v.g));
// 		if (!v.ptr)
// 			return (NULL);
// 		v.i = 0;
// 		v.j = 0;
// 		while (str[v.i])
// 		{
// 			if (str[v.i] != 39)
// 				v.ptr[v.j++] = str[v.i];
// 			v.i++;
// 		}
// 		v.ptr[v.j] = '\0';
// 	}
// 	return (v.ptr);
// }

// void	does_file_exist(char *filename)
// {
// 	int	file;

// 	file = open(filename, O_RDONLY);
// 	if (file == -1)
// 	{
// 		perror("Error file");
// 		exit(1);
// 	}
// 	close(file);
// }

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
	error();
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
