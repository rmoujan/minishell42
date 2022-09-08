/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 08:56:04 by lelbakna          #+#    #+#             */
/*   Updated: 2022/09/04 10:52:22 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

int	ft_check_char(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '\0')
		return (1);
	if (str[1] != 'n')
		return (1);
	while (i < (int)ft_strlen(str) && str[i + 1] != '\0')
	{
		if (str[i] != str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_new_line(void)
{
	ft_putchar_fd('\n', 1);
	t_global.state = 0;
}

int	my_echo(t_cmdfinal **cmd_final)
{
	t_vars	x;

	x.i = 1;
	x.j = 0;
	x.k = 0;
	if ((*cmd_final)->tab[x.j + 1] != NULL)
	{
		while ((*cmd_final)->tab[x.i]
			&& ft_check_char((*cmd_final)->tab[x.i]) == 0)
		{
			x.k++;
			x.i++;
		}
		while ((*cmd_final)->tab[x.i])
		{
			ft_putstr_fd((*cmd_final)->tab[x.i], 1);
			if ((*cmd_final)->tab[x.i + 1] && (*cmd_final)->tab[x.i][0] != '\0')
				ft_putchar_fd(' ', 1);
			x.i++;
		}
		x.j++;
	}
	if (x.k == 0)
		ft_new_line();
	return (0);
}
