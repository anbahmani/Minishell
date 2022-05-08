/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramsy <ramsy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:51:20 by raaga             #+#    #+#             */
/*   Updated: 2022/05/08 15:39:50 by ramsy            ###   ########.fr       */
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
