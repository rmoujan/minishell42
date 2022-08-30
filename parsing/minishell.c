/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 20:32:47 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// < > << >> space |
#include "../minishell.h"
#include "../libft/libft.h"

void	ft_add_history(char *input_user)
{
	if (input_user[0] != '\0')
		add_history(input_user);
	return ;
}

void	ini_global(int *argc)
{
	t_global.here = 0;
	t_global.herdoc = 0;
	t_global.dup_input = dup(0);
	t_global.signal_s = 0;
	t_global.state = 0;
	*argc = 1;
}

void	chunk0_minishell(t_command *data, t_node *head, char *argv[])
{
	t_cmdfinal	*cmd_final;
	t_cmdfinal	*tmp;

	cmd_final = ft_parser(data);
	tmp = cmd_final;
	while (tmp)
	{
		tmp->envp = &head;
		tmp = tmp->next;
	}
	ft_env(&cmd_final);
	ft_expand(cmd_final, cmd_final->env, argv);
	ft_remove(cmd_final);
	edit_cmd(cmd_final);
	ft_numberofnode(cmd_final);
	cmd_final->save[1] = dup(1);
	cmd_final->save[0] = dup(0);
	exec_builtin(&cmd_final, argv);
	dup2(cmd_final->save[1], 1);
	dup2(cmd_final->save[0], 0);
	free_cmdfinal(cmd_final);
}

void	chunk1_minishell(char *input_user, t_node	*head, char *argv[])
{
	char		*str;
	t_command	*data;

	str = ft_addspace(input_user);
	data = ft_bring_data(str);
	if (ft_checkredrections(data) != -1)
		chunk0_minishell(data, head, argv);
	free(str);
	free_node(data);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*input_user;
	t_node	*head;

	head = get_envp(envp);
	ini_global(&argc);
	while (argc)
	{
		ft_i_signals();
		input_user = readline("$ minishell ");
		end_of_file(input_user);
		ft_add_history(input_user);
		if (input_user[0] != '\0')
		{
			if (ft_check(input_user))
			{
				chunk1_minishell(input_user, head, argv);
			}
		}
		free(input_user);
		system("leaks minishell");
	}
	return (0);
}
