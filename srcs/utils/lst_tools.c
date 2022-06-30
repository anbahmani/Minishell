/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:24:47 by abahmani          #+#    #+#             */
/*   Updated: 2022/06/29 01:39:25 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_curr_tab(char	**tab, t_list **lst, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	ft_lstclear(lst, &free);
}

char	**lst_to_tab_str(t_list **lst)
{
	char	**tab;
	int		i;
	t_list	*curr;

	tab = malloc(sizeof(char *) * (ft_lstsize(*lst) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	curr = *lst;
	while (curr)
	{
		tab[i] = malloc(sizeof (char *) * ft_strlen((char *)curr->content));
		if (!tab[i])
		{
			free_curr_tab(tab, lst, i);
			return (NULL);
		}
		tab[i] = ft_strdup((char *)curr->content);
		i++;
	}
	tab[i] = NULL;
	ft_lstclear(lst, &free);
	return (tab);
}
