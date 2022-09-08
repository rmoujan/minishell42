NAME=minishell
CC=gcc
CFLAGS= -Wall -Wextra -Werror
RM = rm -f
lib = libft/libft.a
RDF	= -g -lreadline -L /Users/rmoujan/Desktop/brew/opt/readline/lib -I /Users/rmoujan/Desktop/brew/readline/include
SRC=parsing/minishell.c\
	parsing/ft_parser.c\
	parsing/check_syntaxe.c\
	parsing/split_space.c\
	parsing/free_all.c\
	parsing/split_pipe.c\
	parsing/create_tokens.c\
	parsing/bring_data.c\
	parsing/add_space.c\
	parsing/new_expand.c\
	parsing/remove_quotes.c\
	parsing/edit_cmd.c\
	parsing/check_redrectionserror.c\
	parsing/ft_errorpipes.c\
	parsing/ft_errorredrections.c\
	parsing/number_nodefinal.c\
	parsing/ft_parser_complement.c\
	parsing/expand_chunks2.c\
	parsing/expand_chunks1.c\
	parsing/addspace_complement.c\
	parsing/expand_heredoc.c\
	execution/function.c\
	execution/ft_error.c\
	execution/check_herdoc_input.c\
	execution/exec.c\
	execution/builtin.c\
	builtins/echo_cmd.c\
	builtins/pwd_cmd.c\
	builtins/env_cmd.c\
	builtins/export_cmd.c\
	builtins/exit_cmd.c\
	signals/signal.c\
	signals/signal_utils.c\
	builtins/get_envp.c\
	builtins/unset_cmd.c\
	builtins/cd_cmd.c\
	builtins/ft_export.c\
	execution/openfile.c\
	execution/heredoc.c\
	builtins/export.c\
	builtins/cdcmd_complement.c\

OBJ = $(subst .c,.o,$(SRC))
lib = ./libft/libft.a
libobj = ./libft/*.o

all : $(NAME)

$(lib):
	make -C libft

$(NAME): $(lib) ${OBJ} 
	
	$(CC)  $(RDF) $(CFLAGS) $(OBJ) $(lib)  -o $(NAME)

%.o : %.c
	${CC} -c ${CFLAGS} $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean:clean
	$(RM) $(NAME) $(lib)
	make fclean -C libft

re: fclean all