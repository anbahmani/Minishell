/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:44:19 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/22 17:13:34 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**split_prompt(char *prompt)
{
	char	**splited_prompt;
	int		i;
	char	*tmp;
	
	splited_prompt = ft_split(prompt, '|');
	i = 0;
	while (splited_prompt[i])
	{
		tmp = splited_prompt[i];
		splited_prompt = ft_strtrim((const char *)splited_prompt, ' ');
		free(tmp);
		i++;
	}
	return (splited_prompt);
}

static int	add_redirection_lst(int i, char *str ,t_list **lst)
{
	int				count;
	t_redirection	redir;
	char			*tmp;
	int				start;

	tmp = ft_substr(str, i, 1 + (str[i + 1] && is_redirection(str[i + 1])));
	redir = str_to_redir(tmp);
	free(tmp);
	count = 1 + (str[i + 1] && is_redirection(str[i + 1]));
	while (str[i + count] && str[i + count] == ' ')
		count++;
	start = count;
	while (str[i + count] && str[i + count] != ' ')
		count++;
	if (start != count)
	{
		//get file_name or cmd
	}
}

static t_token	*into_token(char *str)
{
	int		i;
	int		j;
	t_list	**redir;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (is_redirection(str[i]))
		{
			//add redirection to chain list
		}
		i++;
	}
}

static t_list	**prompt_to_lst(char **prompt)
{
	t_list	*lst;
	int		i;
	
	if (prompt[0])
	{
		lst = ft_lstnew(into_token(prompt[0]));
		i = 1;
		while (prompt[i])
		{
			ft_lstnew(into_token(prompt[i]));
			i++;
		}
	}
}

void	parser(char *prompt, t_list **l_env)
{
	char	**splited_prompt;

	splited_prompt = split_prompt(prompt);
	prompt_to_lst(splited_prompt);
	free_char_tab(splited_prompt);
}