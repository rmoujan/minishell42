/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_minisheel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:54 by rmoujan           #+#    #+#             */
/*   Updated: 2022/07/23 15:46:23 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// < > << >> space |
#include "minishell.h"
#include "libft/libft.h"


int main(int argc, char *argv[], char *const envp[])
{
  char *input_user;
  char *str;
  t_command *data;
  // t_cmdfinal *cmd;
  t_command *head;
  while (1)
  {
    printf("\033[0;35m");
    // printf("\033[0;35m");
    input_user = readline("$ minishell ");
    add_history(input_user);
    printf("\033[0m");
    if(input_user[0] != '\0')
    {
      // printf("inside if \n");
      // ft_check(input_user);//check errors still not finish
      str = ft_addspace(input_user);
      // printf("===> ARE YOU OK ?\n");
      //printf("input user is %s\n", str);

      // printf("counter front is %d\n", ft_counterspace_front(input_user));
      // printf("counter back is %d\n", ft_counterspace_back(input_user));
      // ft_addspace(input_user);
      // printf("===> ARE YOU OK ?\n");
      data = ft_bring_data(str);//++ still there are some leaks on this fct !!
      // printf("===> ARE YOU OK ?\n");
      ft_output(data); //++ //had ft_output hiya li fiha leaks au niveau de nodes!!! ++
      // printf("===> ARE YOU OK ?\n");
      // free_nodes(data);===> IMPORTAANT !!!
      // cmd = ft_parser(data);
      // ft_executor();
    free(str);
    
    }
    free(input_user);
  }
	return (0);
} 
//this test case is error :  cat -e Makefile >     > outf
//echo 'dhhbhv $USER njkndv'


