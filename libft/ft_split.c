/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:08:37 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/01 11:39:39 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_words(char const *s1, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s1[i] && s1[i] == c)
		i++;
	while (s1[i] != '\0')
	{
		if (s1[i] == c && s1[i + 1] != c)
			total++;
		i++;
	}
	if (i != 0)
	{
		if (s1[i - 1] != c)
			total++;
	}
	return (total);
}

static char	*ft_cpy(char const *s1, int k, int j)
{
	int		size;
	int		i;
	char	*p;

	size = (j - k) + 1;
	i = 0;
	p = malloc (size * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (k < j)
	{
		p[i] = s1[k];
		i++;
		k++;
	}
	p[i] = '\0';
	return (p);
}

static void	ft_free(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

static char	**f_str(char const *s1, char c, char **tab)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = -1;
	while (s1[++k] != '\0')
	{
		if (s1[k] != c)
		{
			j = k;
			while (s1[j] != c && s1[j] != '\0')
				j++;
			tab[i] = ft_cpy(s1, k, j);
			if (!(tab[i]))
			{
				ft_free(tab, i);
				return (NULL);
			}
			i++;
			k = j - 1;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s1, char c)
{
	char	**tab;

	if (!s1)
		return (NULL);
	tab = malloc ((c_words(s1, c) + 1) * sizeof(char *));
	if (c_words(s1, c) == 0)
	{
		tab[0] = NULL;
		return (tab);
	}
	if (tab == NULL)
		return (NULL);
	return (f_str(s1, c, tab));
}
