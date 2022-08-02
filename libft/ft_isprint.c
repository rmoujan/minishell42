/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:25:57 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/24 15:08:46 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}	
	else
		return (0);
}
/*
int main()
{
	int a = 32;
	printf("not mine : |%d|  \n",isprint(a));
	printf("********* \n");
	printf("mine : |%d| \n",ft_isprint(a));
	return(0);}*/
