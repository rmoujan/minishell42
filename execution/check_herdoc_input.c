/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_herdoc_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:00:02 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/29 23:52:49 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int	check_herdoc(char *str)
{
	if (!str)
	{
		t_global.herdoc = 0;
		if (t_global.signal_s == 2)
		{
			dup(t_global.dup_input);
			t_global.signal_s = 0;
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (2);
}