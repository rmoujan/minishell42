/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:22:06 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 15:40:39 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

int main()
{
    char *ptr;
    ptr = NULL;
    if (ptr == NULL)
        printf("THE pointer is null \n");
    else
        printf("not null \n");
}