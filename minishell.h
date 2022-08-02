/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:58 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/01 16:07:10 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H 

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int g_state;// global variable 

//that's struct will contains in each node a cmd with its args and options 
//and each node will contains in char *cmd name of cmd its options 
//and its args and IN/OU files
// typedef struct s_command t_command;
// struct s_command{
//     char *cmd;
//     char *ifile;
//     char *ofile;
//     char *ofile_app;
//     t_command *next;
// };

typedef struct s_token t_token;
struct s_token{

    char *token;
    int     id;
    t_token *next;
};

//each node of t_command katmtel liya command
typedef struct s_command t_command;
struct s_command{

    t_token *data;
    t_command *next;
};

//this struct contains all files include heredoc
typedef struct s_files t_files;
struct s_files{
    char *name;
    int id;
    t_files *next;
};

//this struct is especially for parsing 
typedef struct s_cmdfinal t_cmdfinal;
struct s_cmdfinal{
    t_files *file; // will contains all names IN/OUT files and heredoc !!! 
    char **tab;    // will contains name of cmd and its args 
    t_cmdfinal *next;
};

t_command *ft_lexer(t_command *data, char *const envp[], char *argv[]);
int ft_check(char *input_user);
void ft_output(t_command *tmp);
int check_del(char c);
void skip_token(char *str, int *i);
// void check_expand(t_command *node, char *const envp[]);
// char *ft_expand(char *str,char *const envp[], char *argv[]);
char *remove_dq(char *str);
t_command *split_space(char **cmds);
void free_lines(char **cmds);
void free_node(t_command *head);
void output(char **cmds);
void replace_pipe_double(char **ptr);
void replace_pipe_single(char **ptr);
void return_pipe_double(char **str1);
void return_pipe_single(char **str1);
void return_pipes(char ***ptr);
t_command *create_cmd(char **data);
t_token *create_token(char *str);
void return_space_double(char **str1);
void return_space_single(char **str1);
t_command *ft_bring_data(char *input_user);
int ft_counterspace_back(char *ptr);
int ft_counterspace_front(char *ptr);
char *ft_addspace(char *ptr);
t_cmdfinal *ft_parser(t_command *node);
void ft_outputcmdfinal(t_cmdfinal *cmd);
void free_cmdfinal(t_cmdfinal *cmd);
void ft_expand(t_cmdfinal *cmd,char *const envp[], char *argv[]);
void ft_remove(t_cmdfinal *cmd);
void check_emptystr(t_command *data);
//int ft_counterspace_back(char *ptr);
//void add_space(char *str, int *i);
#endif

// cmd{
    
// // name_cmd
// // options
// // args
    
// }

// //this struct is especially for parsing 
// typedef struct s_cmdfinal t_cmdfinal;
// struct s_cmdfinal{
//     // char **fdi;
//     // char **fdout;
//     t_files *file;//will contains all names IN/OUT files and heredoc !!! 
//     char **tab;//will contains name of cmd and its args 
//     t_cmdfinal *next;
// };