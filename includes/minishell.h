/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:14:29 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/09 10:22:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "utils.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef enum e_identifier{
	PIPE,
	COMMAND,
	LEFT_SIMPLE_REDIRECTION,
	RIGHT_SIMPLE_REDIRECTION,
	RIGHT_DOUBLE_REDIRECTION,
	LEFT_DOUBLE_REDIRECTION,
	SEMICOLON
}	t_identifier;

typedef struct s_token
{
	t_identifier	id;
	char			*option;
	char			**input;
	struct s_token	*next;
}	t_token;

typedef struct s_data t_data;
struct                  s_data{
    char **path;
    char *readline;
    char **split_line;
    char **split_tmp;
    int pipefd[2];
    char    **env_tmp;
};

/*
typedef struct s_pipex t_pipex;
struct                  s_pipex
{
    int pipefd[2];
};
*/

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
int built_env(char **envp);
int built_export(char **split_line, char **envp);
int ft_strlen_split(char **split);
int	exec_cmd(t_data *data, char **envp);
/* -------------------------------------------------------------------------- */
/*                            FILE = ./src/main.c                             */
/* -------------------------------------------------------------------------- */

#endif