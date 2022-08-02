NAME = libft.a

CC = gcc -c 

CFLAGS = -Wall -Wextra -Werror

AR = ar r

RM = rm -f

SRC=ft_isdigit.c\
	ft_putendl_fd.c\
	ft_striteri.c\
	ft_isprint.c\
	ft_putnbr_fd.c\
	ft_strjoin.c\
	ft_strrchr.c\
	ft_atoi.c\
	ft_itoa.c\
	ft_putstr_fd.c\
	ft_strlcat.c\
	ft_strtrim.c\
	ft_bzero.c\
	ft_memchr.c\
	ft_split.c\
	ft_strlcpy.c\
	ft_substr.c\
	ft_calloc.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_isalnum.c\
	ft_memcpy.c\
	ft_strmapi.c\
	ft_isalpha.c\
	ft_memset.c\
	ft_strchr.c\
	ft_strncmp.c\
	ft_tolower.c\
	ft_isascii.c\
	ft_putchar_fd.c\
	ft_strdup.c\
	ft_strnstr.c\
	ft_toupper.c\
	ft_memmove.c\
	ft_strcmp.c

BNS=ft_lstadd_back_bonus.c\
    ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c

OBJ = $(subst .c,.o,$(SRC))
OBJBN = $(subst .c,.o,$(BNS))

all : $(NAME) 

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC)
	@$(AR) $(NAME) $(OBJ)

bonus :$(OBJBN)

$(OBJBN) : $(BNS)
	@$(CC) $(CFLAGS) $(BNS)
	@$(AR) $(NAME) $(OBJBN)

clean :
	$(RM) $(OBJ) ${OBJBN}

fclean: clean
	$(RM) $(NAME) 

re: fclean all 
