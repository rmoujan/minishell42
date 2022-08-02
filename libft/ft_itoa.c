/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:32:37 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 00:52:33 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

static char	*ft_zero(void)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc (2 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i++] = 0 + '0';
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_alloue(int i)
{
	char	*ptr;

	ptr = (char *)malloc ((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

static char	*ft_icpy(long long total, int sign, int i)
{
	char	*ptr;
	int		j;
	int		b;

	b = 0;
	j = 0;
	ptr = ft_alloue(i);
	if (ptr == NULL)
		return (NULL);
	while (j < i)
	{
		if (sign == 1 && b == 0)
		{
			ptr[j++] = '-';
			b = 1;
		}
		else
		{
			ptr[j++] = (total % 10) + '0';
			total = total / 10;
		}
	}
	ptr[j] = '\0';
	return (ptr);
}

static long long	ft_negatif(long long nbr, int *sign, int *i)
{
	long long	nbr1;

	*sign = 1;
	nbr1 = (long long)(nbr * -1);
	*i = *i + 1;
	return (nbr1);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	long long	total;
	int			i;
	int			sign;

	sign = 0;
	i = 0;
	total = 0;
	if (n == 0)
		return (ft_zero());
	if (n < 0)
		nbr = ft_negatif(n, &sign, &i);
	if (n > 0)
		nbr = n;
	while (nbr != 0)
	{
		total = (total * 10) + (nbr % 10);
		nbr = nbr / 10;
		i++;
	}
	return (ft_icpy(total, sign, i));
}
