/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:15:56 by raaga             #+#    #+#             */
/*   Updated: 2022/05/20 16:26:33 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	if_quote(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			while (str[++i])
			{
				if (str[i] == 34)
				{
					return (2);
				}
			}
			return (1);
		}
		i++;
	}
	return (0);
}

char *modif_quote(char *str)
{
	int i;
	int t;
	char	*dest;

	i = 0;
	t = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str)));
	if (!dest)
		return NULL;
	while (str[i])
	{
		
		while (str[i] == 34 && str[i])
			i++;
		if (str[i])
			dest[t] = str[i];
		else
			break ;
		i++;
		t++;
	}
	dest[t] = '\0';
	return (dest);
}


char **double_quote(char **split)
{
	int i;
	//int nb_quote;
	int tmp_i;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		if (if_quote(split[i]) == 2)
		{
			split[i] = modif_quote(split[i]);
		}
		else if (if_quote(split[i]) == 1)
		{
			//nb_quote = 1;
			tmp_i = i;
			tmp = ft_strdup(split[tmp_i]);
			while (split[++tmp_i])
			{
				tmp = ft_strjoin(tmp, " ");
				tmp = ft_strjoin(tmp, split[tmp_i]);
				if (if_quote(tmp) == 2)
					break ;
			}
			while (split[tmp_i + 1])
			{
				split[tmp_i] = split[tmp_i + 1];
				tmp_i++;
			}
			split[tmp_i] = 0;
			split[i] = modif_quote(tmp);
		}
		i++;
	}
	return (split);
}