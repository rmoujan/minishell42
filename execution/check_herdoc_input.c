/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_herdoc_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:00:02 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/27 15:01:59 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int check_herdoc(char *str)
{
    if (!str)
	{
		t_global.herdoc = 0;
		if (t_global.signal_s == 2)
		{
			dup(t_global.dup_input);
			t_global.signal_s = 0;
			free(str);
			return (0);
		}
		else
		{
			free(str);
			return (1);
		}
	}
	return (2);
}