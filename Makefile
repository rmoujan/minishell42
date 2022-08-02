NAME=minishell
CC=gcc
 CFLAGS= #-Wall -Wextra -Werror #-lreadline #-L  
RM = rm -f

SRC=minishell.c\
	ft_output.c\
	ft_delete.c\
	check_cmd.c\
	ft_parser.c\
	syntax_analyser.c\
	check_syntaxe.c\
	tools/ft_isdel.c\
	skip_tokens.c\
	ft_remove.c\
	split_space.c\
	free_all.c\
	split_pipe.c\
	create_tokens.c\
	bring_data.c\
	ft_lexer.c\
	add_space.c\
	new_expand.c\
	remove_quotes.c\
	edit_cmd.c\
	
OBJ = $(subst .c,.o,$(SRC))
lib = ./libft/libft.a
libobj = ./libft/*.o

all : $(NAME)

$(NAME):${OBJ}
	@make -C libft
	$(CC) -lreadline $(OBJ) $(lib) -o $(NAME)

%.o : %.c
	@${CC} -c ${CFLAGS} $< -o $@

clean:
	$(RM) $(OBJ) $(libobj)

fclean:clean
	$(RM) $(NAME) $(lib)

re: fclean all
# l'igno 2020
#  a okk <
#  knkn_

# $(NAME):${OBJ}
# 	@make -C libft
# 	$(CC) -fsanitize=address -g -lreadline $(OBJ) $(lib) -o $(NAME)