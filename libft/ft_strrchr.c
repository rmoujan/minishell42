/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:27:17 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 01:38:04 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cara;
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	cara = (char)c;
	p = (char *)s;
	while (p[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (p[i] == cara)
		{
			return (&p[i]);
		}
		i--;
	}
	return (0);
}
/*
int main()
{
	char s[]="hadldkdlo";
	char c='\0';
	printf("%s \n",ft_strrchr(s,c));
	printf("%s \n",strrchr(s,c));
	return (0);
}*/
