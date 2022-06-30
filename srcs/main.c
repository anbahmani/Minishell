/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:55:18 by abahmani          #+#    #+#             */
/*   Updated: 2022/06/29 03:27:22 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int	dup_envp(t_data *data, char **envp)
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
} */

static t_list	*env_to_lst(char **env)
{
	int		i;
	t_list	*lst;

	i = 1;
	if (env[0])
	{
		lst = ft_lstnew(ft_strdup(env[0]));
		while (env[i])
		{
			ft_lstadd_back(&lst, ft_lstnew(ft_strdup(env[i])));
			i++;
		}
		return (lst);
	}
	return (NULL);
}

//function to print the output of parsing to test in the parser is ok or not
void	print_parser_output(t_list	**output)
{
	t_list *l_curr_token;
	t_list *l_curr_redir;
	t_token *curr_token;
	t_redir_data *curr_redir;

	l_curr_token = *output;
	while (l_curr_token)
	{
		curr_token = (t_token*)l_curr_token->content;
		printf("cmd : %s\nargs : %s\n", curr_token->cmd, curr_token->args);
		if (curr_token->l_redir)
		{
			l_curr_redir = *curr_token->l_redir;
			while (l_curr_redir)
			{
				curr_redir = (t_redir_data*)l_curr_redir->content;
				printf("file : %s\n", curr_redir->file);
				char *redir_name;
				switch (curr_redir->redir) 
   				{
     				case LEFT_SIMPLE_REDIRECTION: redir_name = "LEFT_SIMPLE_REDIRECTION";
    				case RIGHT_SIMPLE_REDIRECTION: redir_name = "RIGHT_SIMPLE_REDIRECTION";
					case RIGHT_DOUBLE_REDIRECTION: redir_name = "RIGHT_DOUBLE_REDIRECTION";
					case LEFT_DOUBLE_REDIRECTION: redir_name = "LEFT_DOUBLE_REDIRECTION";
					case OTHER: redir_name = "WTF";
  				}
				printf("redir type : %s\n", redir_name);
				l_curr_redir = l_curr_redir->next;
			}
		}
		printf("\n");
		l_curr_token = l_curr_token->next;
	}
}

int main(int argc, char **argv, char **envp)
{
		t_data	*data;
		char 	*prompt;
		t_list	*l_env;
		t_list	*l_output;

		(void)argc;
		(void)argv;
		data = malloc(sizeof(t_data));
		l_env = env_to_lst(envp);
		while (1)
		{   
				prompt = readline("minishell$> ");
				add_history(prompt);
				data->readline = prompt;
				l_output = parser(prompt, &l_env);
				print_parser_output(&l_output);
				//if (ft_strcmp(data->readline, "exit") == 0)
				//	exit(0);
				//data->split_line = ft_split(data->readline, ' ');
				//exec_cmd(data, envp);
				
		}
		return (0);
}
