NAME        	=   minishell

CC          	=   gcc

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find lib/libft -type d) \

OBJ_DIR			=	obj

LIB_DIR			=	lib/libft

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# library -----------------------------------------------------------

LIB			=	ft

SRC			= 	main.c \
				parsing.c \
				parser.c \
				ft_strcmp.c \
				env_var.c \
				inside_quote.c \
				syntax_error.c \
				char_tools.c \
				free_element.c \
				lst_tools.c \
				str_tools.c \
#				exec.c \
#				built_cd.c \
#				built_echo.c \
#				built_in.c  \
#				built_pwd.c \
#				built_env.c \
#				built_export.c \
#				ft_strlen_split.c \
#				parsing.c \

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=thread

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib))

# main part ---------------------------------------------------------

all:
	@echo "\n___$(NAME) Setting___\n"
	@make  $(NAME)

install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) bonus;)

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@make -C lib/libft fclean

$(NAME): install $(OBJ)
	@echo "-----\nCreating Binary File $@ ... \c"
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME) -lreadline
	@echo "DONE\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $@ ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "DONE"

re:	fclean all

clean:
	@echo "Deleting Objects Directory $(OBJ_DIR) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "DONE\n-----"

fclean:	clean
	@echo "Deleting Binary File $(NAME) ... \c"
	@rm -f $(NAME)
	@echo "DONE\n-----"

.PHONY: all bonus show re clean flcean
