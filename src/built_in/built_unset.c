/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:27:35 by raaga             #+#    #+#             */
/*   Updated: 2022/05/20 13:23:00 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	var_comp(t_list *list, char *str)
{
	int	i;

	i = ft_strchr_mod(str, '=');
	if (i == -1)
		i = ft_strlen(str);
	
	while (list)
	{
		if (ft_strncmp(list->str, str, i) == 0)
		{
			free(list->str);
			if (list->prev && list->next)
			{
				list->next->prev = list->prev;
				list->prev->next = list->next;
			}
			else if (list->prev == NULL && list->next != NULL)
				list->next->prev = NULL;
			else if (list->next == NULL && list->prev != NULL)
				list->prev->next = NULL;
			free(list);
			return (1);
		}
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	return (0);
}

int	built_unset(t_data **data)
{
	int	x;

	x = 1;
	while ((*data)->split_line[x])
	{
		while ((*data)->split_line[x])
		{
			var_comp((*data)->list, (*data)->split_line[x]);
			var_comp((*data)->list_env, (*data)->split_line[x]);
			x++;
		}
	}
	return (1);
}