/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:08:09 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/09 15:46:28 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//I replace each space that inside " " with -2 !!!!!
void	replace_space_double(char **ptr)
{
	int		i;
	int		flag;
	char	*str;

	i = 0;
	flag = 0;
	str = *ptr;
	while (str[i] != '\0')
	{
		if (!flag && (str[i] == '\'' || str[i] == '"'))
			flag = str[i];
		else if (flag && flag == str[i])
			flag = 0;
		if (str[i] == ' ' && flag)
			str[i] = -2;
		i++;
	}
}

//I replace each -2 that inside " " with space !!!!!
void	return_space_double(char **str1)
{
	int		i;
	int		flag;
	char	*str;

	str = *str1;
	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!flag && (str[i] == '\'' || str[i] == '"'))
			flag = str[i];
		else if (flag && flag == str[i])
			flag = 0;
		if (str[i] == -2 && flag)
			str[i] = ' ';
		i++;
	}
}

void	link_node(t_cmdfinal **head, t_cmdfinal **final, t_cmdfinal **p)
{
	if (*head == 0)
	{
		*head = *p;
		*final = *p;
	}
	else
	{
		(*final)->next = *p;
		*final = *p;
	}
}

void	space_linknode(t_command **h, t_command **node, t_command **tmp, int i)
{
	if (i == 0)
	{
		*h = *node;
		*tmp = *node;
	}
	else
	{
		(*tmp)->next = *node;
		(*tmp) = *node;
	}
}

// start creation of the  big node t_command !!!!
t_command	*split_space(char **cmds)
{
	t_command	*head;
	t_command	*tmp;
	t_command	*node;
	char		**data;
	int			i;

	i = 0;
	head = 0;
	tmp = 0;
	while (cmds[i])
	{
		replace_space_double(&cmds[i]);
		data = ft_split(cmds[i], ' ');
		node = create_cmd(data);
		space_linknode(&head, &node, &tmp, i);
		free_lines(data);
		i++;
	}
	tmp->next = NULL;
	return (head);
}
