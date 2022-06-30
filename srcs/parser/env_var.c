/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 05:56:45 by abahmani          #+#    #+#             */
/*   Updated: 2022/06/29 08:51:05 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int g_last_return_code;
char	*get_env_var_in_str(char *str, int *i)
{
	char	*env_var;
	char	*env_var_value;

	if (str[*i + 1] == '?')
	{
		(*i)++;
		return (ft_itoa(g_last_return_code));
	}
	env_var = ft_strdup("");
	while (str[(*i)] && str[(*i)] != '\"' && str[(*i)] != '\'' 
			&& str[(*i)] != ' ')
	{
		add_char(&env_var, str[(*i)]);
		(*i)++;
	}
	env_var_value = getenv((const char *)env_var);
	free(env_var);
	return (env_var_value);
}
