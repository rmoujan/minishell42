/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:36:33 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/20 16:53:20 by lelbakna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

int	my_pwd(t_cmdfinal **cmd_final)
{
	(void)cmd_final;
	char	pwd[1024];

	printf("%s\n", getcwd(pwd, sizeof(pwd)));
		return (1);
}
// check arg after cmd "pwd" in zsh ==>exit 1