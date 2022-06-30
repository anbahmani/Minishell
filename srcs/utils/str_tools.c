/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:46:45 by abahmani          #+#    #+#             */
/*   Updated: 2022/06/30 12:03:32 by abahmani         ###   ########.fr       */
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
		return ;
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

char	*get_char_without_quote(char *str, int *i)
{
	int		j;
	char	*res;
	char	quote;

	j = *i;
	res = ft_strdup("");
	while (str[j])
	{
		if (str[j] == '\"' || str[j] == '\'')
		{
			if (!find_second_quote(str[j], str, j))
			{
				if (res)
					free(res);
				return (NULL);
			}
			quote = str[j++];
			parse_str_inside_quote(str, &j, &res, quote);
		}
		else 
		{
			add_char(&str, str[j]);
			j++;
		}
	}
	return (str);
}