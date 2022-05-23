/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:21:07 by raaga             #+#    #+#             */
/*   Updated: 2022/05/20 13:57:16 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*verif_var_env(char *str)
{
	int		i;
	int		x;
	char	*dest;
	i = 0;
	x = 0;
	
	while (str[i] != '$')
	{
		if (str[i] == '\0')
			return (NULL) ;
		i++;
	}
	if (i == 0)
		return (NULL);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	while (x < i)
	{	
		dest[x] = str[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}


int	variable_env(t_data	**data, int i)
{
	int		y;
	char	*str;
	char 	*tmp;
	char	*reste;

	str = NULL;
	tmp = NULL;
	while ((*data)->split_line[i])
	{
		y = 0;
		while ((*data)->split_line[i][y] != '\0')
		{
			if ((*data)->split_line[i][y] == '$')
			{
				if (ft_isdigit((*data)->split_line[i][y + 1]) == 1)
				{
					str = ft_strndup_mod(&(*data)->split_line[i][y + 1], &ft_isdigit,&(y));
					reste = ft_strdup(&(*data)->split_line[i][y + 1]);
					break ;
				}
				else if (ft_isalpha((*data)->split_line[i][y + 1]) == 1)
				{
					str = ft_strndup_mod(&(*data)->split_line[i][y + 1], &ft_isalnum,&(y));
					reste = ft_strdup(&(*data)->split_line[i][y + 1]);
					break ;
				}
				else
				{
					str = ft_strdup(&(*data)->split_line[i][y + 1]);
					break ;
				}
			}
			y++;
		}
		if (str)
			break ;
		i++;
	}
	if (str == NULL)
		return (0);
	tmp = verif_var_env((*data)->split_line[i]);
	(*data)->split_line[i] = ft_strdup(tmp);
	while ((*data)->list)
	{
		if (ft_strncmp(str, (*data)->list_env->str, ft_strlen(str)) == 0)
		{
			tmp = ft_strdup(&(*data)->list_env->str[ft_strlen(str) + 1]);
			free(str);
			str = (*data)->split_line[i];
			if (str)
				(*data)->split_line[i] = ft_strjoin(str, tmp);
			else
				(*data)->split_line[i] = ft_strdup(tmp);
			if (reste != NULL)
			{
				str = (*data)->split_line[i];
				(*data)->split_line[i] = ft_strjoin(str, reste);
			}
			free(tmp);
			return (1);
		}
		if ((*data)->list_env->next == NULL)
			break ;
		(*data)->list_env = (*data)->list_env->next;
	}
	free((*data)->split_line[i]);
	(*data)->split_line[i] = ft_strjoin(tmp, reste);
	return (1);
}

int modif_dollar(t_data **data)
{
	int	i;

	i = 0;
	while ((*data)->split_line[i])
	{
		variable_env(data, i);
		i++;
	}
	//back_to_start(data->list_env);
	return (1);
}