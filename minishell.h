/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:22:58 by rmoujan           #+#    #+#             */
/*   Updated: 2022/09/04 10:40:21 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H 
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>

/*global struct*/

struct s_global{
	int				here;
	int				herdoc;
	int				dup_input;
	int				signal_s;
	int				fd[2];
	unsigned long	state;
	char			*g_pwd;
} t_global;

/*I using this on expand !!!*/

typedef struct s_expand		t_expand;
struct s_expand{
	char	*new;
	char	*ptr;
	char	*str;
	char	**env;
	char	*av;
	int		i;
	int		start;
};

typedef struct s_token		t_token;
struct s_token{
	char	*token;
	int		id;
	t_token	*next;
};

typedef struct s_command	t_command;
struct s_command{
	t_token		*data;
	t_command	*next;
};

/*this struct contains all files include heredoc*/

typedef struct s_files		t_files;
struct s_files{
	char	*name;
	int		id;
	t_files	*next;
};

/*this struct is especially for linked liste env*/

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
}				t_node;

/*this struct is especially for parsing*/

typedef struct s_cmdfinal	t_cmdfinal;
struct s_cmdfinal{
	t_files		*file;
	t_cmdfinal	*next;
	t_node		**envp;
	char		**tab;
	char		**env;
	char		**cmd;
	int			flag1;
	int			flag2;
	int			fd[2];
	int			fdhere[2];
	int			save[2];
	int			infile;
	int			outfile;
	int			number_node;
};

/*this structs is especially for execution*/

typedef struct s_var
{
	pid_t	child;
	pid_t	*child_pids;
	char	*path;
	char	**s;
	char	**cmd;
	char	**ptr;
	int		fd[2];
	int		i;
	int		n_cmd;
	int		flag;
}				t_var;

/*this structs is especially for variables*/

typedef struct s_vars
{
	int		i;
	int		j;
	int		k;
	char	*ptr;
	char	*str1;
	char	*str2;
	char	*str3;
	int		flag1;
	int		flag2;
}				t_vars;

/*parsing*/

t_command	*split_space(char **cmds);
t_command	*ft_lexer(t_command *data, char *const envp[], char *argv[]);
t_command	*create_cmd(char **data);
t_command	*ft_bring_data(char *input_user);
t_cmdfinal	*ft_parser(t_command *node);
t_cmdfinal	*create_node_final(t_command *node);
t_token		*create_token(char *str);
t_files		*create_file(char *str, int id);
void		ft_output(t_command *tmp);
void		free_lines(char **cmds);
void		free_node(t_command *head);
void		output(char **cmds);
void		ft_outputcmdfinal(t_cmdfinal *cmd);
void		return_pipe_double(char **str1);
void		replace_pipe_single(char **ptr);
void		return_pipe_single(char **str1);
void		skip_token(char *str, int *i);
void		return_pipes(char ***ptr);
void		return_space_double(char **str1);
void		replace_pipe_double(char **ptr);
void		free_cmdfinal(t_cmdfinal *cmd);
void		return_space_single(char **str1);
void		ft_expand(t_cmdfinal *cmd, char **envp, char *argv[]);
void		ft_remove(t_cmdfinal *cmd);
void		check_emptystr(t_command *data);
void		edit_cmd(t_cmdfinal *cmd);
void		put_flagquotes(int *flag, int *i, int *start, char c);
void		ft_numberofnode(t_cmdfinal *head);
void		chunk0_expand(t_expand *all);
void		chunk1_expand(t_expand *all);
void		chunk2_expand(t_expand *all);
void		chunk3_expand(t_expand *all);
void		chunk4_expand(t_expand *all);
void		initial_expand(t_expand *d, char *s, char **en, char **av);
void		flag_expand(char *str, int i, int *flag);
char		*ft_addspace(char *ptr);
char		*remove_dq(char *str);
char		*get_value(char *ptr, char **envp);
char		*ft_copy1(char *p);
char		*chunk5_expand(t_expand *all);
char		*expand_dollar_heredoc(char *s, char **en, char *av[]);
int			check_del(char c);
int			ft_check(char *input_user);
int			ft_counterspace_back(char *ptr);
int			ft_counterspace_front(char *ptr);
int			compare_redrections(char *str);
int			ft_errno(int code);
int			ft_checkredrections(t_command *head);
int			cheak_pipes(char *str);
int			cheak_redrections(char *str);
int			is_redirect(char *str);
int			check_specialchar(char *str);
int			check_reds(char c);
int			countfront(char *ptr);
int			countback(char *ptr);
char		*expand_dollar(char *s, char **en, char *av[]);
int			check_dollar(char *str);

/*signal*/ //check

void		int_handler(int sig);
void		quit_handler(int sig);
void		ft_i_signals(void);
void		ft_e_signals(void);
void		end_of_file(char *str);

/*builtins*/

t_node		*get_envp(char **env);
t_node		*get_env(t_cmdfinal *cmd_final);
int			my_cd(t_cmdfinal **cmd_final);
int			my_echo(t_cmdfinal **cmd_final);
int			my_pwd(t_cmdfinal **cmd_final);
int			my_exit(t_cmdfinal **cmd_final);
int			my_export(t_cmdfinal **cmd_final);
int			my_unset(t_cmdfinal **cmd_final);
int			my_env(t_cmdfinal **cmd_final);
void		ft_env(t_cmdfinal **cmd_final);
void		creat_node(t_node **head, char *data);
void		print_list(t_node *head);
int			builtin(t_cmdfinal **cmd_final);
void		printlist(t_node *head);
int			is_builtin(char *value);
void		execute_builtin(t_cmdfinal **cmd_final);
int			ft_search(char *str);
int			ft_pwd(t_cmdfinal **cmd_final);
char		*ft_ret_var(char *str);
int			ft_search_pluse(char *str);
void		ft_quote(char *str);
void		printlist(t_node *head);
char		*my_strchr(char *s, int c);
int			ft_cmp(char *str);
void		ft_sort_env(t_node **head, t_cmdfinal **cmd_final);
int			ft_home(t_vars *x, t_cmdfinal **cmd_final);
char		*ft_get_pwd(t_cmdfinal **cmd_final);
void		msg_error(void);
void		ft_close(t_vars *x, t_cmdfinal *tmp);
/*execution*/

// void	ft_chek_cmd_p1(char *str, t_chek *v);

char		*ft_chek_cmd(char *str);
void		does_file_exist(char *filename);
char		*serach_path(t_cmdfinal *cmd_final);
char		*ft_check_path(char **path, char *cmd);
void		error(void);
void		error_exe(char *str);
void		error_file(void);
void		ft_str_error(char *str, char *s);
void		ft_cmd(t_cmdfinal **cmd_final, t_var *exec);
int			ft_pipe(t_cmdfinal *cmd_final, t_var *x, int i);
int			ft_openfile(t_cmdfinal *cmd_final);
void		exec_cmd(t_cmdfinal **cmd_final);
int			exec_builtin(t_cmdfinal **cmd_final, char **av);
int			ft_dup_file(t_cmdfinal *cmd_final);
int			ft_check_heredoc(t_cmdfinal *cmd_final, char **av);
int			check_herdoc(char *str);
int			ft_read_from_heredoc(t_cmdfinal *tmp, char *name, char **av);
int			ft_check_heredoc(t_cmdfinal *cmd_final, char **av);
int			ft_dup_file(t_cmdfinal *cmd_final);
void		ft_heredoc(t_cmdfinal *cmd_final);
int			infile(t_cmdfinal *cmd_final, t_files *file);
int			outfile(t_cmdfinal *cmd_final, t_files *file);
int			ft_append(t_cmdfinal *cmd_final, t_files *file);
int			ft_openfile(t_cmdfinal *tmp);
void		ft_errors_red(char *str, char *s);
void		ret_fork(t_var	*exec);

/*free*/
void		print(t_cmdfinal **cmd_final);
void		free_tab(t_cmdfinal **cmd_final);
void		ft_checkk(t_cmdfinal *cmd_final);
void		rl_replace_line(char *str, int d);
void		free_flag_cmd(t_vars *x, char *path, char *oldpath);
void		free_pwd(char *oldpath, char *path);
#endif