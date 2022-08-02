/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:30:12 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/24 18:27:04 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t l)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)first;
	p2 = (unsigned char *)second;
	while ((p1[i] != '\0' || p2[i] != '\0') && (i < l))
	{
		if (p1[i] > p2[i])
			return (p1[i] - p2[i]);
		else if (p1[i] < p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
