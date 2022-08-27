/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:11:11 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/26 19:37:06 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
//new norm
char	**split_pipe(char *input_user)
{
	char	**cmds;

	replace_pipe_double(&input_user);
	cmds = ft_split(input_user, '|');
	return_pipes(&cmds);
	return (cmds);
}

t_command	*ft_bring_data(char *input_user)
{
	t_command	*data;
	char		**cmds;

	cmds = split_pipe(input_user);
	data = split_space(cmds);
	free_lines(cmds);
	return (data);
}
