/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:37:45 by raaga             #+#    #+#             */
/*   Updated: 2022/05/01 17:32:33 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	msg_err_no_file(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (0);
}

char	*get_home(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "HOME=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	if (envp[i][ft_strlen(envp[i]) - 1] != '/')
		envp[i] = ft_strjoin(envp[i], "/");
	return (envp[i] + 5);
}

int	go_home(char **envp, char *home)
{
	home = get_home(envp);
	if (chdir(home) != 0)
		return (msg_err_no_file());
	return (1);
}

int	go_dest(char *tmp, char *str)
{
	char	*home;
	char	buff[PATH_MAX + 1];

	getcwd(buff, sizeof(buff));
	home = ft_strjoin(buff, "/");
	tmp = ft_strjoin(home, str);
	free(home);
	if (access(tmp, F_OK) == 0)
	{
		if (chdir(tmp) != 0)
		{
			free(tmp);
			return (msg_err_no_file());
		}
	}
	else
	{
		free(tmp);
		return (msg_err_no_file());
	}
	free(tmp);
	return (1);
}

int	built_cd(char **envp, char *str)
{
	char	*home;
	char	*tmp;

	home = NULL;
	tmp = NULL;
	if (str == NULL)
		return (go_home(envp, home));
	else
		go_dest(tmp, str);
	free(tmp);
	return (1);
}
