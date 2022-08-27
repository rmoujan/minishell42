/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/27 19:12:52 by rmoujan          ###   ########.fr       */
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

void ini_global()
{
  t_global.here = 0;
  t_global.herdoc = 0;
  t_global.dup_input = dup(0);//for save the input standard 
  t_global.signal_s = 0;
  t_global.state = 0;
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
  ini_global();
  while (argc)
  {
    ft_i_signals();
  //  printf("\033[32;1m");
    input_user = readline("$ minishell ");
    // if(!input_user)
    //     exit(1);
    // printf("\033[0m");
    end_of_file(input_user);
    ft_add_history(input_user);
    if(input_user[0] != '\0')
    {
      if (ft_check(input_user))//check errors still not finish
      {
            str = ft_addspace(input_user);
            data = ft_bring_data(str);
            //printf("befor check red \n");
            //ft_output(data);
            if (ft_checkredrections(data) != -1)
            {
            //  printf("after check red \n");
              cmd_final = ft_parser(data);
              tmp = cmd_final;
              while (tmp)
              {
                tmp->envp = &head;
                tmp = tmp->next;
              }
              ft_env(&cmd_final);// fill tab of env
              //ft_checkk(cmd_final);
              // cmd_final->env = envp;
              ft_expand(cmd_final, cmd_final->env, argv);
              ft_remove(cmd_final);
              edit_cmd(cmd_final);
              ft_numberofnode(cmd_final);
              // cmd_final->save[1] = dup(1);new commented
              // cmd_final->save[0] = dup(0);new commented
              exec_builtin(&cmd_final, argv);
              //free_cmdfinal(cmd_final);//===> IMPORTAANT  !!!00
            }
            free(str);
           // printf("test 2\n");
            free_node(data);
           // printf("test 1\n");
            // dup2(cmd_final->save[1], 1);// new commented
            // dup2(cmd_final->save[0], 0);//new commented
      }
    }
    free(input_user);
    // system("leaks minishell");
}
	return (0);
}