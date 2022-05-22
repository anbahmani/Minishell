/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 04:40:01 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/22 17:03:42 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_str_inside_double_quote(char *str, int *i, char **res)
{
	char	*tmp;
	char	*env_var_value;
	int		k;

	while (str[(*i)] != "\"")
	{
		if (str[(*i)] == "$" && str[(*i) + 1] != ' '
			&& str[(*i) + 1] != '\"')
		{
			k = i;
			tmp = res;
			env_var_value = get_env_var_in_str(str, &k);
			res = ft_strjoin((const char *)res, (const char *)env_var_value);
			free(tmp);
			free(env_var_value);
		}
		else
		{
			add_char(&res, str[(*i)]);
			(*i)++;
		}
	}
}
