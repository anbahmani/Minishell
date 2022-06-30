/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 04:40:01 by abahmani          #+#    #+#             */
/*   Updated: 2022/06/29 01:33:44 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*get_str_without_quote(char *str, int *i)
{
	int		j;
	char	*res;
	char	quote;

	j = *i;
	res = ft_strdup("");
	while (str[j] && str[j] != ' ')
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
		else {
			add_char(&str, str[j]);
			j++;
		}
	}
	return (str);
}

void	parse_str_inside_quote(char *str, int *i, char **res, char quote)
{
	char	*tmp;
	char	*env_var_value;
	int		k;

	while (str[(*i)] != '\"')
	{
		if (quote == '\"' && str[(*i)] == '$' && str[(*i) + 1] != ' '
			&& str[(*i) + 1] != '\"')
		{
			k = *i;
			tmp = *res;
			env_var_value = get_env_var_in_str(str, &k);
			*res = ft_strjoin((const char *)res, (const char *)env_var_value);
			free(tmp);
			free(env_var_value);
			*i = k;
		}
		else
		{
			add_char(res, str[(*i)]);
			(*i)++;
		}
	}
}
