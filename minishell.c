/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/02 13:13:16 by rmoujan          ###   ########.fr       */
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
  while (1)
  {
     printf("\033[0;35m");
    // printf("\033[0;35m");
    input_user = readline("$ minishell ");
    if (input_user[0] != '\0')
      add_history(input_user);
    printf("\033[0m");
    if(input_user[0] != '\0')
    {
      if (ft_check(input_user))//check errors still not finish
      {
            str = ft_addspace(input_user);//!!
            data = ft_bring_data(str);// in this step there is no leaks !!!!
            printf("after bring data\n");
            //printf("BEFORE PARSER\n");;
            cmd_final = ft_parser(data);// in this step there is no leaks !!
            //printf("AFTER PARSER\n");
           // printf("starting expand !!\n");
           ft_expand(cmd_final, envp, argv);//in this step there is no leaks !!
            //printf("END expand !!\n");
            ft_remove(cmd_final);//!!in this step there is no leaks !!
            //printf("after remove\n");
            ft_outputcmdfinal(cmd_final);//!!
            // ft_output(data);//++ had ft_output hiya li fiha leaks au niveau de nodes!!!
            // ft_executor();
            // free_node(data);//
            // free_cmdfinal(cmd_final);//===> IMPORTAANT  !!!00
            free(str);
      }
    }
    free(input_user);
  }
	return (0);
} 
//this test case is error :  cat -e Makefile > > outf
//echo 'dhhbhv $USER njkndv'


