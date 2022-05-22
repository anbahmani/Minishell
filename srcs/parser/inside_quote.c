/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 04:40:01 by abahmani          #+#    #+#             */
/*   Updated: 2022/05/22 06:24:58 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_str_inside_double_quote(char *str, int i)
{
	char	*res;
	int		j;
	
	j = 1;
	res = malloc(sizeof(char) * 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	while(str[i + j] != "\"")
	{
		if (str[i + j] == "$" && str[i + j + 1] != ' '
			&& str[i + j + 1] != '\"')
		{
			// get the env var value and add it in res string
		}
		else
		{
			add_char(&res, str[[i + j]]);
			j++;
		}
	}
}