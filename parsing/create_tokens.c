/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:19:21 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/26 19:38:40 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
//new norm
t_token	*create_token(char *str)
{
	t_token	*node_token;

	node_token = (t_token *) malloc(sizeof(t_token));
	return_space_double (&str);
	node_token->token = ft_strdup (str);
	return (node_token);
}

t_command	*create_cmd(char **data)
{
	t_command	*node_cmd;
	t_token		*node_token;
	t_token		*tmp_token;
	int			i;

	i = 0;
	node_cmd = (t_command *) malloc(sizeof(t_command));
	while (data[i])
	{
		node_token = create_token(data[i]);
		if (i == 0)
		{
			node_cmd->data = node_token;
			tmp_token = node_token;
		}
		else
		{
			tmp_token->next = node_token;
			tmp_token = node_token;
		}
		i++;
	}
	tmp_token->next = NULL;
	return (node_cmd);
}
