/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 15:51:19 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// < > << >> space |
#include "../minishell.h"
#include "../libft/libft.h"

void ft_add_history(char *input_user)
{
	  if (input_user[0] != '\0')
      	add_history(input_user);
	return ;
}

void ini_global(int *argc)
{
  t_global.here = 0;
  t_global.herdoc = 0;
  t_global.dup_input = dup(0);//for save the input standard 
  t_global.signal_s = 0;
  t_global.state = 0;
  *argc = 1;
}

void	free_arr(char		**env)
{
	int i;
	i = 0;
	while (env[i] != '\0')
	{
		free(env[i]);
		i++;;
	}
	free(env);
}

void	free_file(t_cmdfinal **cmd_final)
{
	int i;
  t_files *file;
	i = 0;
  file = (*cmd_final)->file;
	while (file)
	{
		free(file->name);
		file = file->next;
	}
	free(file);
}

int main(int argc, char *argv[], char *envp[])
{
  char *input_user;
  char *str;
  t_node	*head;
  t_command *data;
  t_cmdfinal *cmd_final;
  t_cmdfinal  *tmp;
  
  head = get_envp(envp);
  ini_global(&argc);
  while (argc)
  {
    ft_i_signals();
    input_user = readline("$ minishell ");
    end_of_file(input_user);
    ft_add_history(input_user);
    if(input_user[0] != '\0')
    {
      if (ft_check(input_user))
      {
            str = ft_addspace(input_user);
            data = ft_bring_data(str);
            if (ft_checkredrections(data) != -1)
            {
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
            free(str);
            free_node(data);
      }
    }
    free(input_user);
    // system("leaks minishell");
}
	return (0);
}