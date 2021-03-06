/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:47:01 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/09 10:05:42 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **find_path(char **envp)
{
	int     i;
	char    **split;
	
	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	split = ft_split(&envp[i][5], ':');
	return (complet_path(split));
}

char    **complet_path(char **split)
{
		int             i;
		char    *tmp;

		i = 0;
		while (split[i])
		{
				tmp = split[i];
				split[i] = ft_strjoin(tmp, "/");
				free(tmp);
				i++;
		}
		split[i] = ft_strjoin(split[i], "");
		return (split);
}

char *get_path(char **path, char *cmd)
{
	int i;
	char *tmp;
	
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		i++;    
	}
	return (NULL);
}

int parser(char **envp, t_data *data, char **split)
{
	int i;
	char *cmd;
	int     res;
	
	data->path = find_path(envp);
	i = 0;
	while (data->split_line[i])
	{
		while ((ft_strcmp(data->split_line[i], "") == 0))
			i++;
		cmd = get_path(data->path, split[0]);
		if (cmd == NULL)
		{
			printf("pas bon\n");
			exit(0);
		}
		res = execve(cmd, split, envp);
		if (res == -1)
		{
			write(2, "bash: ", ft_strlen("bash: "));
			write(2, cmd, ft_strlen(cmd));
			perror("");
		}
	}
	return (1);
}

int pipex(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "|") == 0)
			return (i);
		i++;
	}
	return (0);
}

int ftt_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (i);
}

/*
int verif_char(char **split)
{
	int i;
	int y;
	int tmp;
	
	i = 0;
	while (split[i])
	{
		while (split[i][y])
		{
			if (split[i][y] == 34)
			{
				
			y++;
		}
		i++;
	}
	return (0);
}*/