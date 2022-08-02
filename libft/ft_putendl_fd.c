/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:02:07 by rmoujan           #+#    #+#             */
/*   Updated: 2021/11/24 21:51:30 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, "\n", 1);
}
/*
int main()
{
    char str[] = "hallo world this is me from in.txt";
    int fd = open("in.txt", O_RDWR | O_CREAT);
    ft_putendl_fd(str, fd);
    printf("[%d]", fd);
    //printf("[%d]", fdi);
    //printf("[%d]", fdo);
    return 0;
}*/