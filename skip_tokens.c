/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:18:44 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/04 20:30:40 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"


//I'm  not working with it
// void skip_token(char *str, int *i)
// {
//     int quots;
    
//     quots = 0;
//     while(str[*i])
//     {
//         if(!quots && (str[*i] == '\'' || str[*i] == '"'))
//             quots = str[*i];
//         else if(quots && str[*i] == quots)
//             quots = 0;
//         if(!quots && check_del(str[*i]))
//         {
//             break;
//         }
//         (*i)++;
//     }
// }

// void add_space(char *str, int *i)
// {
//     while (str[*i] == ' ')
//         (*i)++;
// }

