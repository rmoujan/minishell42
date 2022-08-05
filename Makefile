NAME=minishell
CC=gcc
CFLAGS= -Wall -Wextra -Werror #-lreadline -L
RM = rm -f

SRC=minishell.c\
	ft_output.c\
	ft_parser.c\
	check_syntaxe.c\
	split_space.c\
	free_all.c\
	split_pipe.c\
	create_tokens.c\
	bring_data.c\
	add_space.c\
	new_expand.c\
	remove_quotes.c\
	edit_cmd.c\
	check_redrectionserror.c\
	number_nodefinal.c\
	libft/ft_strjoin.c\
	libft/ft_itoa.c\
	libft/ft_strlen.c\
	libft/ft_strdup.c\
	libft/ft_strcmp.c\
	libft/ft_strncmp.c\
	libft/ft_substr.c\
	libft/ft_isdigit.c\
	libft/ft_split.c\
	libft/ft_isalnum.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -fsanitize=address -lreadline $(CFLAGS) $(OBJ) $(lib) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re: fclean all

# # 000
# $(NAME):$(OBJ)
# 	@make -C libft
# 	@$(CC) -fsanitize=address -lreadline $(OBJ) $(lib) -o $(NAME)
# tools/ft_isdel.c\