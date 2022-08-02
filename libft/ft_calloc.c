/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:57:35 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 01:19:23 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	total;
	size_t	i;

	i = 0;
	total = count * size;
	p = malloc(total);
	if (p == NULL)
	{
		return (NULL);
	}
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
/*
int main()
{
	char *test;
	char *test1;
	size_t count = 5;
	test = ft_calloc(count,sizeof(char));
	test1 = ft_calloc(count,sizeof(char));
	printf("|%s|\n",test);
	printf("|%s|\n",test1);
	return (0);
}*/
