/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:25:27 by rmoujan           #+#    #+#             */
/*   Updated: 2022/07/22 22:30:52 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == 0x0)
		return (0x0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
int main()
{
	char tab[]="hallocnjbjbdvjnf";
	printf("la laongeur est % \n " ,ft_strlen(tab));
	printf("la laonguer est %lu " ,strlen(tab));
	return (0);
}*/
