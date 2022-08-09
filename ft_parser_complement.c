/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_complement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:13:05 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/09 17:13:02 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int	is_redirect(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (1);
	else if (ft_strcmp(str, ">") == 0)
		return (2);
	else if (ft_strcmp(str, "<<") == 0)
		return (3);
	else if (ft_strcmp(str, ">>") == 0)
		return (4);
	return (0);
}

//21 lines
int	counte_linecmd(t_command *node)
{
	t_command	*tmp;
	t_token		*save;
	int			counter;

	counter = 0;
	tmp = node;
	save = tmp->data;
	while (tmp->data)
	{
		if (is_redirect(tmp->data->token) != 0)
		{
			tmp->data = tmp->data->next;
		}
		else
		{
			counter++;
		}
		tmp->data = tmp->data->next;
	}
	node->data = save;
	return (counter);
}

t_cmdfinal	*create_node_final(t_command *node)
{
	t_cmdfinal	*head;
	int			len;

	head = (t_cmdfinal *)malloc(sizeof(t_cmdfinal));
	if (head == NULL)
	{
		printf("the pointer does not allocated properly\n");
		exit(1);
	}
	len = counte_linecmd(node);
	head->tab = (char **) malloc(sizeof (char *) * (len + 1));
	if (head->tab == NULL)
	{
		printf("the pointer does not allocated properly\n");
		exit(1);
	}
	return (head);
}

//create file of node final :
t_files	*create_file(char *str, int id)
{
	t_files	*node;

	node = (t_files *)malloc(sizeof(t_files));
	if (node == NULL)
	{
		printf("the pointer does not allocated properly\n");
		exit(1);
	}
	node->name = ft_strdup(str);
	node->id = id;
	return (node);
}
