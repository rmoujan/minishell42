/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:42:59 by rmoujan           #+#    #+#             */
/*   Updated: 2022/09/04 10:22:54 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int	check_reds(char c)
{
	if (c == '<' || c == '>')
	{
		return (1);
	}
	return (0);
}

void	putflag_copy2(int *flag, char c)
{
	if (!*flag && (c == '\'' || c == '"'))
		*flag = c;
	else if (*flag && c == *flag)
		*flag = 0;
}

void	ft_copy2(char **str, char *ptr)
{
	char	*new;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	new = *str;
	while (ptr[i] != '\0')
	{
		putflag_copy2(&flag, ptr[i]);
		if (check_reds(ptr[i]) && !flag)
		{
			if (i != 0)
			{
				if (ptr[i - 1] != '\0' && ptr[i - 1] != ' '
					&& !check_reds(ptr[i - 1]))
					new[j++] = ' ';
			}
		}
		new[j++] = ptr[i];
		i++;
	}
	new[j] = '\0';
}

int	isredirect_exist(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (check_reds(ptr[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_addspace(char *ptr)
{
	int		i;
	int		len;
	char	*new;
	char	*str;

	i = 0;
	len = 0;
	if (isredirect_exist(ptr) == 1)
	{
		len = countfront(ptr) + countback(ptr);
		new = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + len + 1));
		if (!new)
			return (NULL);
		str = ft_copy1(ptr);
		ft_copy2(&new, str);
		free(str);
		return (new);
	}
	return (ft_strdup(ptr));
}
