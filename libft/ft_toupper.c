/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:34:02 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/17 18:44:33 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	else
		return (c);
	return (c);
}
/*
int main()
{
	char c = '=';
	//printf(" %c ",ft_toupper(c));
	printf(" %c ",toupper(c));
	return (0);
}*/
