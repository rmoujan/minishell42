/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:11:11 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/03 10:24:06 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//splite cmd by | . 
char **split_pipe(char *input_user)
{
    char **cmds;
    // int i = 0;
    replace_pipe_double(&input_user);
    // replace_pipe_single(&input_user);00
    // printf("from split pipe , inputuser is %s\n", input_user);
    cmds = ft_split(input_user, '|');
    // while (cmds[i])
    // {
    //     printf("====> |%s|\n", cmds[i]);
    //     i++;
    // }
    return_pipes(&cmds);
    return cmds;
}

t_command *ft_bring_data(char *input_user)
{
    t_command *data;
    char **cmds;
    
    cmds = split_pipe(input_user);//leaks kaynin hena !!
    //in this step there is no leaks 
    //each line of cmds will be separate by space :
    //cmds is now ready to separate tokens by space !!!!
    data = split_space(cmds);//leaks are on this step !!!!!
    // ft_output(data);
    // while (1);
    // output(cmds);
    free_lines(cmds);
    return data;
}

//example :
// $ minishell ls -la | cat -e >> out | echo "test hallo">> outfile2
// [ls -la ]--->ls is first token and -la is second token !!
// [ cat -e >> out ]
// [ echo "test hallo">> outfile2]
// $ minishell 