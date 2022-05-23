/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:11:25 by raaga             #+#    #+#             */
/*   Updated: 2022/05/20 16:14:35 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
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
}*/

int main(int argc, char **argv, char **envp)
{
		t_data *data;
		char *prompt;

		(void)argc;
		(void)argv;
		data = malloc(sizeof(t_data));
		//dup_envp(data, envp);
		data->list = init(envp);
		data->list_env = init(envp);
		while (1)
		{   
				prompt = readline("minishell$> ");
				add_history(prompt);
				data->readline = prompt;
				if (ft_strcmp(data->readline, "exit") == 0)
					exit(0);
				data->split_line = ft_split(data->readline, ' ');
				data->split_line = double_quote(data->split_line);
				int i = 0;
					
					while (data->split_line[i])
					{
						printf("QWEQWE %s\n", data->split_line[i]);
						i++;
					}
				if (prompt && prompt[0] != '\0')
				{
					modif_dollar(&data);
					back_to_start(&data->list_env);
				
					exec_cmd(data, envp);
				}
		}
		return (0);
}
