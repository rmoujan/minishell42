/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addspace_complement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:48:30 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/31 05:49:19 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

char	*ft_copy1(char *p)
{
	char	*new;
	int		flag;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flag = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(p) + countfront(p) + 1));
	while (p[i] != '\0')
	{
		new[j++] = p[i];
		if (!flag && (p[i] == '\'' || p[i] == '"'))
			flag = p[i];
		else if (flag && p[i] == flag)
			flag = 0;
		if (check_reds(p[i]) && !flag)
		{
			if (p[i + 1] != '\0' && p[i + 1] != ' ' && !check_reds(p[i + 1]))
				new[j++] = ' ';
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}

int	countfront(char *ptr)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (ptr[i] != '\0')
	{
		if (check_reds(ptr[i]))
		{
			if (ptr[i + 1] != '\0' && ptr[i + 1] != ' '
				&& !check_reds(ptr[i + 1]))
			{
				counter++;
			}
		}
		i++;
	}
	return (counter);
}

int	countback(char *ptr)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (ptr[i] != '\0')
	{
		if (check_reds(ptr[i]))
		{
			if (i != 0)
			{
				if (ptr[i - 1] != '\0' && ptr[i - 1] != ' '
					&& !check_reds(ptr[i - 1]))
				{
					counter++;
				}
			}
		}
		i++;
	}
	return (counter);
}
