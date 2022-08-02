/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:31:06 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/17 17:52:31 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)
		|| (c >= 48 && c <= 57))
	{
		return (1);
	}
	else
		return (0);
}
/*
int main()
{
	char k = '5';
	printf(" %d ",isalnum(k));
	return (0);
}*/
