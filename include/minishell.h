/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:51:20 by raaga             #+#    #+#             */
/*   Updated: 2022/05/20 17:31:40 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>


typedef struct s_list t_list;
struct                  s_list{
    t_list  *prev;
    t_list  *next;
    char    *str;
};

typedef struct s_data t_data;
struct                  s_data{
    char **path;
    char *readline;
    char **split_line;
    char **split_tmp;
    int pipefd[2];
    char    **env_tmp;
    t_list  *list;
    t_list *list_env;
};





/* -------------------------------------------------------------------------- */
/*                       FILE = ./src/parsing/parsing.c                       */
/* -------------------------------------------------------------------------- */
int     pipex(char **str);
int     parser(char **envp, t_data *data, char **split);
char    **find_path(char **envp);
char    **complet_path(char **split);
int ftt_strchr(const char *s, int c);
int verif_char(char **split);
int    built_cd(char **envp, char *str);
int built_echo(t_data *data);
int is_built_in(t_data *data, char **envp);
int built_pwd(void);
int built_env(t_data *data);
int built_export(char **split_line, t_list **list, t_list **list_env);
int ft_strlen_split(char **split);
int	exec_cmd(t_data *data, char **envp);


/* file = ./src/list_init.c */

t_list *init(char **envp);
void    ajout_list(t_list **list, char *str);
void	back_to_start(t_list **a);
int     ft_strlen_list(t_list *list);

/* file = ./src/built_in/export.c */

int	built_unset(t_data **data);

/* file = ./src/execution/dollar.c */

int	variable_env(t_data	**data, int i);
int modif_dollar(t_data **data);

/* file =./src/parsing/double_quote.c */
char **double_quote(char **split);

#endif
