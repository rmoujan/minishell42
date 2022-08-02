/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:13:41 by rmoujan           #+#    #+#             */
/*   Updated: 2022/04/23 05:05:42 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;
	int		src_l;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	src_l = i + 1;
	ptr = (char *)malloc(src_l * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int main()
{
	char *p1="Hallo World this me Im in 1337";
	char *p2="hy mom";
    printf("%s \n",p2);
	p2 = strdup(p1);
	printf("%s \n",p2);
	return (0);
}*/
