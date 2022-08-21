/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:11:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/21 17:26:36 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"


void	link_nodetokens(t_files **f, t_files **p, t_cmdfinal **head, int j)
{
	if (j == 0)
	{
		(*head)->file = *f;
		*p = *f;
	}
	else
	{
		(*p)->next = (*f);
		*p = *f;
	}
}

void	put_null(t_files **file, t_cmdfinal **head, int i, int j)
{
	if ((*file) != NULL)
	{
		(*file)->next = NULL;
	}
	if (j == 0)
	{
		(*head)->file = NULL;
	}
	(*head)->tab[i] = NULL;
}

void	iterate_tokens(t_token *tmp, t_cmdfinal *head)
{
	t_files	*file;
	t_files	*pointer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	file = NULL;
	while (tmp)
	{
		if (is_redirect(tmp->token) != 0)
		{
			if (tmp->next != NULL)
			{
				file = create_file(tmp->next->token, is_redirect(tmp->token));
				link_nodetokens(&file, &pointer, &head, j);
				tmp = tmp->next;
				j++;
			}
		}
		else
			head->tab[i++] = ft_strdup(tmp->token);
		tmp = tmp->next;
	}
	put_null(&file, &head, i, j);
}

void	parser_linknode(t_cmdfinal **h, t_cmdfinal **final, t_cmdfinal **p)
{
	if (*h == 0)
	{
		*h = *p;
		*final = *p;
	}
	else
	{
		(*final)->next = *p;
		*final = *p;
	}
}

//20 lines max variables declared in fct are 5 vars 
t_cmdfinal	*ft_parser(t_command *node)
{
	t_command	*tmp;
	t_cmdfinal	*head;
	t_cmdfinal	*pointer;
	t_cmdfinal	*final;
	t_token		*save;

	tmp = node;
	head = 0;
	final = 0;
	pointer = 0;
	while (tmp)
	{
		save = tmp->data;
		pointer = create_node_final(tmp);
		parser_linknode(&head, &final, &pointer);
		iterate_tokens(tmp->data, pointer);
		tmp->data = save;
		tmp = tmp->next;
	}
	pointer->next = NULL;
	return (head);
}
