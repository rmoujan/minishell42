/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:00:23 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/24 18:48:37 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*process(char *p1, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (p1[i + j] == needle[j] && needle[j] != '\0' && (i + j) < len)
		{
			if (needle[j + 1] == '\0' && (i + j) < len)
				return (&p1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p1;

	p1 = (char *)haystack;
	if (len >= ft_strlen(p1))
		len = ft_strlen(p1);
	if (needle[0] == '\0')
		return (p1);
	return (process(p1, needle, len));
}
