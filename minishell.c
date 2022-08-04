/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/04 20:40:30 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//0 < > << >> space |
#include "minishell.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char *const envp[])
{
  char *input_user;
  char *str;
  
  t_command *data;
  t_cmdfinal *cmd_final;
  
  argc = 1;
  while (argc)
  {
    printf("\033[32;1m");
    //printf("\033[0;35m");
    input_user = readline("$ minishell ");
    printf("\033[0m");
    if (input_user[0] != '\0')
      add_history(input_user);
    if(input_user[0] != '\0')
    {
      if (ft_check(input_user))//check errors still not finish
      {
            str = ft_addspace(input_user);//!!
            data = ft_bring_data(str);// in this step there is no leaks !!!!
            //printf("after bring data\n");
            // ft_output(data);
            if (ft_checkredrections(data) != -1)
            {
              printf("INSIDE IF result\n");
              //ft_output(data);
              //printf("BEFORE PARSER\n");;
              cmd_final = ft_parser(data);// in this step there is no leaks !!
              //printf("AFTER PARSER\n");
              // printf("starting expand !!\n");
              ft_expand(cmd_final, envp, argv);//in this step there is no leaks !!
              //printf("END expand !!\n");
              ft_remove(cmd_final);//!!in this step there is no leaks !!
              //printf("after remove\n");
              edit_cmd(cmd_final);
              ft_numberofnode(cmd_final);
              // ft_outputcmdfinal(cmd_final);//!!
              //  ft_output(data);//++ had ft_output hiya li fiha leaks au niveau de nodes!!!
              // ft_executor();
              
              free_cmdfinal(cmd_final);//===> IMPORTAANT  !!!00
            }
            free(str);
            free_node(data);
      }
    }
    free(input_user);
}
	return (0);
} 

//this test case is error :  cat -e Makefile > > outf
//echo 'dhhbhv $USER njkndv'
// "" "'''" '' "" '' "'" '"""' ::  not working in check syntaxe error !!!!