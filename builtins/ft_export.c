/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:09:06 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/30 23:38:01 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

char	*ft_ret_var(char *str)
{
	int		i;
	int		cmp;
	char	*ptr;
	char	*tmp;

	i = 0;
	cmp = ft_cmp(str);
	ptr = malloc(sizeof(char) * cmp + 1);
	while (cmp > 0)
	{
		ptr[i] = str[i];
		i++;
		cmp--;
	}
	ptr[i] = '\0';
	tmp = ptr;
	return (ptr);
}

int	ft_search_pluse(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			if (str[i - 1] == '+')
				return (0);
		i++;
	}
	return (1);
}

void	ft_quote(char *str)
{
	int	i;
	int	k;
	int	c;

	i = 0;
	k = 0;
	c = 0;
	write(1, "declare -x ", 11);
	while (str[i])
	{
		write(1, &str[i], 1);
		if (str[i] == '=' && c == 0)
		{
			k = 1;
			c = 1;
			write(1, "\"", 1);
		}
		i++;
	}
	if (k == 1)
		write(1, "\"", 1);
	write(1, "\n", 1);
}

void	printlist(t_node *head)
{
	t_node	*temp;

	temp = head;
	if (temp == NULL)
		printf("empty");//**
	while (temp != NULL)
	{
		ft_quote(temp->data);
		temp = temp->next;
	}
}

char	*my_strchr(char *s, int c)
{
	char	cara;
	int		i;
	int		j;
	char	*p1;

	i = 0;
	j = 0;
	p1 = (char *)s;
	cara = (char)c;
	while (p1[i] != '\0')
	{
		if (p1[i] == cara)
		{
			i++;
			return (&p1[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		while (p1[j] != '\0')
			j++;
		return (&p1[j]);
	}
	return (NULL);
}
