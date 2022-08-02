/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:52:29 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 01:44:47 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int main()
{
	char s1[10] = "hallo";
	char *s2 = "world 1337";

	char s3[10] = "hallo";
	char *s4 = "world 1337";

	printf("%zu \n",ft_strlcpy(s1, s2, 5));
	printf("%zu \n", strlcpy(s3, s4, 5));


}
*/
