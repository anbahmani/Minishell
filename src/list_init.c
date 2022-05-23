/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:35:30 by raaga             #+#    #+#             */
/*   Updated: 2022/05/19 20:38:51 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int     ft_strlen_list(t_list *list)
{
    int i;

    i = 0;
    while (list != NULL)
    {
        i++;
        if(list->next == NULL)
            break ;
        list = list->next;
    }
    return (i);
}

void	back_to_start(t_list **a)
{
	while (*a != NULL)
	{
		if ((*a)->prev == NULL)
			break ;
		*a = (*a)->prev;
	}
}

void	go_to_end(t_list **a)
{
	while (*a != NULL)
	{
		if ((*a)->next == NULL)
			break ;
		*a = (*a)->next;
	}
}

t_list *ft_lstnew(char *str)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    new->str = ft_strdup(str);
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

void    ajout_list(t_list **list, char *str)
{
    t_list *tmp;
    
    go_to_end(list);
    
    (*list)->next = ft_lstnew(str);
    tmp = (*list);
    (*list) = (*list)->next;
    (*list)->prev = tmp;
    (*list)->next = NULL;
    back_to_start(list);
}

t_list *init(char **envp)
{
    t_list  *list;
    t_list  *tmp;
    int     i;
    int     size;

    i = 0;
    size = ft_strlen_split(envp);
    while (i < size)
    {
        list = ft_lstnew(envp[i]);
        if (i > 0)
        {
            list->prev = tmp;
            list->prev->next = list;
            if (i == size - 1)
            {
                break ;
            }
        }
        tmp = list;
        i++;
        list = list->next;
    }
    back_to_start(&list);
    return (list);
}