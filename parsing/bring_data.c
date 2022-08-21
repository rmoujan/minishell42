/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:11:11 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/21 17:25:43 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"


//splite cmd by | . 
char **split_pipe(char *input_user)
{
    char **cmds;

    replace_pipe_double(&input_user);
    cmds = ft_split(input_user, '|');
    return_pipes(&cmds);
    return cmds;
}

t_command *ft_bring_data(char *input_user)
{
    t_command *data;
    char **cmds;

    cmds = split_pipe(input_user);
    //in this step there is no leaks
    //each line of cmds will be separate by space :
    //cmds is now ready to separate tokens by space !!!!
    data = split_space(cmds);
    free_lines(cmds);
    return data;
}

