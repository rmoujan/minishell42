/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:05:41 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/17 18:45:24 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	else
	{
		return (c);
	}
	return (c);
}
/*
int main()
{
	char c = '%';
	printf(" %c \n ",ft_tolower(c));
	printf(" %c ",tolower(c));
	return (0);
}*/
