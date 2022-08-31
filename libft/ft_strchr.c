/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:54:37 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/31 03:48:18 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char	cara;
	int		i;
	int		j;
	char	*p1;

	i = 0;
	j = 0;
	p1 = (char *)s;
	cara = (char)c;
	while (p1[i] != '\0')
	{
		if (p1[i] == cara)
			return (&p1[i]);
		i++;
	}
	if (c == '\0')
	{
		while (p1[j] != '\0')
			j++;
		return (&p1[j]);
	}
	return (NULL);
}
/*
int main()
{
	char s[]="hallo";
	char var ='l';
	printf(" mine |%s| \n", ft_strchr(s,var));
	printf("not mine |%s| \n",strchr(s,var));
	return (0);
}*/
