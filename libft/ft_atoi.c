/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:48:24 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 01:16:26 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include<stdlib.h>
#include "libft.h"

static int	ft_space(const char *str, int *sign)
{
	int	j;

	j = 0;
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n'
		|| str[j] == '\f' || str[j] == '\v' || str[j] == '\r')
	{
		j++;
	}
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			*sign = *sign * (-1);
		j++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				i;
	int				sign;

	nb = 0;
	sign = 1;
	i = ft_space(str, &sign);
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		if (nb > LONG_MAX)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (sign * nb);
}
