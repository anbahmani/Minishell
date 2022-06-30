/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:44:19 by abahmani          #+#    #+#             */
/*   Updated: 2022/06/30 10:14:47 by abahmani         ###   ########.fr       */
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
		splited_prompt[i] = ft_strtrim((const char *)splited_prompt[i], " ");
		free(tmp);
		i++;
	}
	return (splited_prompt);
}

static int	add_redirection_lst(int i, char *str ,t_list **lst)
{
	int				count;
	//t_redirection	redir;
	char			*tmp;
	t_redir_data	*r_data;
	char			*file;

	tmp = ft_substr(str, i, 1 + (str[i + 1] && is_redirection(str[i + 1])));
	//redir = str_to_redir(tmp);
	free(tmp);
	count = 1 + (str[i + 1] && is_redirection(str[i + 1]));
	if (str[i + count]) 
	{
		i = i + count;
		file = get_str_without_quote(str, &i);
		if (file == NULL)
		{
			free_token_lst(lst);
			exit(EXIT_FAILURE);
		}
		r_data = malloc(sizeof(t_redir_data));
		if (!r_data)
		{
			free_token_lst(lst);
			exit (EXIT_FAILURE);
		}
	}
	return (i);
}

//have to modify the loop which manage redirection
static t_token	*into_token(char *str)
{
	int		i;
	//int		j;
	t_token	*tkn;
	t_list	**redir;

	i = 0;
	redir = NULL;
	tkn = malloc(sizeof(t_token));
	if (!tkn)
		return (NULL);
	while (str[i])
	{
		//j = 0;
		if (ft_isalpha(str[i]))
		
		if (is_redirection(str[i]))
		{
			add_redirection_lst(i, str, redir);
		}
		i++;
	}
	tkn->l_redir = redir;
	return (tkn);
}

static t_list	*prompt_to_lst(char **prompt)
{
	t_list	*head;
	t_list	*lst;
	int		i;
	
	if (prompt[0])
	{
		head = ft_lstnew(into_token(prompt[0]));
		lst = head;
		i = 1;
		while (prompt[i])
		{
			lst->next = ft_lstnew(into_token(prompt[i]));
			lst = lst->next;
			i++;
		}
	}
	else
		return (NULL);
	return (head);
}

t_list	*parser(char *prompt, t_list **l_env)
{
	char	**splited_prompt;
	t_list	*output;
	(void)l_env;
	splited_prompt = split_prompt(prompt);
	output = prompt_to_lst(splited_prompt);
	free_char_tab(splited_prompt);
	return (output);
}
