/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/21 20:29:01 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//0 < > << >> space |
#include "../minishell.h"
#include "../libft/libft.h"

void ft_add_history(char *input_user)
{
	  if (input_user[0] != '\0')
      	add_history(input_user);
	return ;
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
  argc = 1;
  g_state = 0;
  while (argc)
  {
    ft_i_signals();
   printf("\033[32;1m");
    input_user = readline("$ minishell ");
    printf("\033[0m");
    end_of_file(input_user);
    ft_add_history(input_user);
    if(input_user[0] != '\0')
    {
      if (ft_check(input_user))//check errors still not finish
      {
            str = ft_addspace(input_user);
            data = ft_bring_data(str);
            if (ft_checkredrections(data) != -1)
            {
              cmd_final = ft_parser(data);
              tmp = cmd_final;
              while (tmp)
              {
                tmp->envp = head;
                tmp = tmp->next;
              }
              ft_env(cmd_final);// fill tab of env
              //ft_checkk(cmd_final);
              ft_expand(cmd_final, cmd_final->env, argv);
              ft_remove(cmd_final);
              edit_cmd(cmd_final);
              ft_numberofnode(cmd_final);
              cmd_final->save[1] = dup(1);
              cmd_final->save[0] = dup(0);
              exec_builtin(&cmd_final);
              free_cmdfinal(cmd_final);//===> IMPORTAANT  !!!00
            }
            free(str);
            free_node(data);
    dup2(cmd_final->save[1], 1);// check
    dup2(cmd_final->save[0], 0);
      }
    }
    free(input_user);
            // system("leaks minishell");
}
	return (0);
}