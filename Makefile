CC = gcc  

NAME = minishell

SRC = ./src/main.c

LIBFTPATH = ./libft/

LIBFTNAME = libft.a

OBJ = $(SRC:%.c=%.o)
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

PARSING = ./src/parsing/parsing.c \
			./src/built_in/built_cd.c \
			./src/built_in/built_echo.c \
			./src/built_in/built_in.c  \
			./src/built_in/built_pwd.c \
			./src/built_in/built_env.c \
			./src/built_in/built_export.c \
			./src/built_in/ft_strlen_split.c \
			./src/execution/exec.c \
			./src/list_init.c \
			./src/built_in/built_unset.c \
			./src/execution/dollar.c \
			./src/parsing/double_quote.c \


.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPATH)
	mv $(LIBFTPATH)$(LIBFTNAME) $(LIBFTNAME)
	$(CC) ${CFLAGS} $(SRC) ${PARSING} -I minishell.h $(LIBFTNAME) -lreadline -o $(NAME) 

clean:
	 rm -rf *.o && make -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(LIBFTNAME)  ${OBJS} $(NAME) && make -C $(LIBFTPATH) fclean

re: fclean all