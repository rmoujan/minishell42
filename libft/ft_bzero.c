/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:48:06 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/24 15:55:13 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p1;
	size_t	i;

	i = 0;
	p1 = (char *)s;
	if (n != 0)
	{
		while (i < n)
		{
			p1[i] = 0;
			i++;
		}
	}
}
/*
#include <string.h>
int main()
{
	char s[]="jjbjbd";
	ft_bzero(s,5);
	//bzero(s,3);
	printf("%s \n",s);
	//printf("%s \n", bzero(s,5));
	return (0);
}*/
