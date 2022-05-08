/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramsy <ramsy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:53:20 by raaga             #+#    #+#             */
/*   Updated: 2022/05/08 16:38:00 by ramsy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_cmd(t_data *data, char **envp)
{
	int tmp;
	pid_t pid;
	pid_t pid2;
	int		i;
	

	tmp = pipex(data->split_line);
	pipe(data->pipefd);
	if (is_built_in(data, data->env_tmp) == 1)
		return (1); 
	else if (tmp > 0)
	{
		
		pid = fork();
		if (pid == 0)
		{
			dup2(data->pipefd[1], 1);
			close(data->pipefd[1]);
			data->split_tmp = data->split_line;
   			if (tmp > 0)
   			{
				i = 0;
   			    data->split_tmp = (char **)malloc(sizeof(char **) * tmp);
   			    while (i < tmp)
   			    {
   			        data->split_tmp[i] = ft_strdup(data->split_line[i]);
   			        i++;
   			    }   
   			}
			parser(envp, data, data->split_tmp);
		}
		
		pid2 = fork();
		if (pid2 == 0)
		{
			i = 0;
			data->split_tmp = (char **)malloc(sizeof(char **) * tmp);
			dup2(data->pipefd[0], 0);
			close(data->pipefd[1]);
    		close(data->pipefd[0]);
			while (i < tmp)
			{
				data->split_tmp[i] = ft_strdup(data->split_line[tmp + i + 1]);
				i++;
			}
			parser(envp, data, data->split_tmp);
			
		}
		close(data->pipefd[1]);
		close(data->pipefd[0]);
		waitpid(pid2, NULL, 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			data->split_tmp = data->split_line;
			parser(envp, data, data->split_tmp);
		}
		waitpid(pid, NULL, 0);
	}
	return (0);
}