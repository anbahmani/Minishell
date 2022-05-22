/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:46:45 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/22 05:59:29 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection	str_to_redir(char *str)
{
	if (!ft_strcmp(str, ">"))
		return (RIGHT_SIMPLE_REDIRECTION);
	if (!ft_strcmp(str, "<"))
		return (LEFT_SIMPLE_REDIRECTION);
	if (!ft_strcmp(str, ">>"))
		return (RIGHT_DOUBLE_REDIRECTION);
	if (!ft_strcmp(str, "<<"))
		return (LEFT_DOUBLE_REDIRECTION);
	return (OTHER);
}

void	add_char(char **str, char c)
{
	char	*new;
	int		i;
	char	*tmp;

	new = malloc(sizeof(char) * (ft_strlen(*str) + 1));
	i = 0;
	if (!new)
		return (NULL);
	while (*str[i])
	{
		new[i] = *str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	tmp = *str;
	*str = new;
	free(tmp);
}

static bool	find_second_quote(char quote, char *str, int i)
{
	while (str[i])
	{
		if (str[i] == quote)
			return (true);
		i++;
	}
	return (false);
}

char	*get_char_without_quote(char *str)
{
	int		i;
	int		j;
	char	*res;
	char	quote;

	i = 0;
	j = 0;
	res = NULL;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			if (!find_second_quote(str[i], str, i))
			{
				if (res)
					free(res);
				return (NULL);
			}
			quote = str[i];
			while (str[++i] != quote)
				//get str between simple or double quotes
		}
		else {
			add_char(&str, str[i]);
			i++;
		}
	}
}