/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:10:33 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 01:44:27 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	f_cpy(char *p1, char *p2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		p1[i] = p2[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t	i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	if (!dst && !src)
		return (0);
	if (p1 <= p2)
	{
		f_cpy(p1, p2, size);
	}
	else
	{
		while (0 < size)
		{
			p1[size - 1] = p2[size - 1];
			size--;
		}
	}
	return (dst);
}
