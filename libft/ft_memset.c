/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:44:24 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 01:18:21 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t len)
{
	unsigned char	val;
	unsigned char	*chaine;
	size_t			i;

	chaine = (unsigned char *)pointer;
	val = (unsigned char)value;
	i = 0;
	while (i < len)
	{
		chaine[i] = val;
		i++;
	}
	return (chaine);
}
/*
#include <string.h>

int main()
{
	int res[] = {1,2,3};
	ft_memset(res, 1, sizeof(int) * 3);
	for (unsigned int i = 0; i < 3; i++)
		printf ("res --> %i\n", res[i]);
	//char tab[] = "hallo";
	//ft_memset(tab, 'e', 5);
	//printf("%s \n",tab);
	return (0);
}*/
