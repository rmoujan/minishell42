/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:28:41 by rmoujan           #+#    #+#             */
/*   Updated: 2022/06/30 19:29:27 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

static char	*ft_copy(char const *s1, char const *s2, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char s2)
{
	unsigned int	total;
	int				i;
	int				j;
	char			*p;

	if (!s1 || !s2)
		return (NULL);
	total = 0;
	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc((total) * sizeof(char));
	if (p == NULL)
		return (NULL);
	p = ft_copy(s1, s2, p);
	free(s1);
	return (p);
}

/*
int main()
{
	char s1[]=" Hallo ";
	char s2[]="World in 1337 this is me";
	printf("%s \n",ft_strjoin(s1,s2));
	return (0);
}*/
