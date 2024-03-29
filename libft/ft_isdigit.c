/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:43:21 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 18:33:58 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

// from 1 to 9 :
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*
int main()
{
	int a ='6';
	//printf(" %d ",ft_isdigit(a));
	printf(" %d ",isdigit(a));
	return (0);
}*/
