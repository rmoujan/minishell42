/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:40:21 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/25 01:47:10 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;
	size_t	j;

	dst_l = 0;
	src_l = 0;
	i = 0;
	j = 0;
	if (!dstsize)
		return (ft_strlen(src));
	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	if (dstsize <= dst_l)
		return (dstsize + src_l);
	i = dst_l;
	while (src[j] != '\0' && j < (dstsize - dst_l - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_l + src_l);
}
/*
#include<string.h>
int main()
{
	char *dest;
	memset(dest, 'r', 15);
	//printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	printf("%zu", strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, dest, 15);
	printf("%zu", ft_strlcat(NULL,"",0));

}*/
