/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:55:18 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/09 10:08:54 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_envp(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->env_tmp = malloc(sizeof(char *) * ft_strlen_split(envp) + 1);
	if (!data)
		return (0);
	while (envp[i])
	{
		data->env_tmp[i] = ft_strdup(envp[i]);
		i++;
	}
	return (1);
}

int main(int argc, char **argv, char **envp)
{
		t_data *data;
		char *prompt;

		(void)argc;
		(void)argv;
		data = malloc(sizeof(t_data));
		dup_envp(data, envp);
		while (1)
		{   
				prompt = readline("minishell$> ");
				add_history(prompt);
				data->readline = prompt;
				if (ft_strcmp(data->readline, "exit") == 0)
					exit(0);
				data->split_line = ft_split(data->readline, ' ');
				
				exec_cmd(data, envp);
				
		}
		return (0);
}
