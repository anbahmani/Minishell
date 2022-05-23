/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:25:04 by raaga             #+#    #+#             */
/*   Updated: 2022/05/20 13:58:28 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**range_tab(char **tab)
{
	int	i;
	int	x;
	char *tmp;

	i = 0;
	while (tab[i])
    {
        x = i + 1;
        while (tab[x])
        {
            if (ft_strcmp(tab[i], tab[x]) > 0)
            {
                tmp = ft_strdup(tab[i]);
                tab[i] = ft_strdup(tab[x]);
                tab[x] = ft_strdup(tmp);
            }
            x++;
        }
        i++;
    }
	return (tab);
}

void	tri_env(t_list **list)
{
	char	**tab;
	int 	i;

	i = 0;
	back_to_start(list);
	tab = (char **)malloc(sizeof(char **) * (ft_strlen_list((*list)) + 1));
	while ((*list))
	{
		tab[i] = ft_strdup((*list)->str);
		i++;
		if ((*list)->next == NULL)
			break ;
		(*list) = (*list)->next;
	}	
	back_to_start(list);
	tab[i] = 0;
	tab = range_tab(tab);
	/*int q = 0;
	while (tab[q])
	{
		printf("lalalal %s\n", tab[q]);
		q++;
	}*/
	i = 0;
	while (tab[i])
	{
		free((*list)->str);
		(*list)->str = ft_strdup(tab[i]);
		if ((*list)->next == NULL)
			break ;
		(*list) = (*list)->next;
		i++;
	}
	back_to_start(list);
}

void	affiche_list(t_list *list)
{
	int	i;
	i = 0;
	while (list)
	{
		write(1, "export ", ft_strlen("export "));
		write(1, list->str, ft_strlen(list->str));
		write(1, "\n", 1);
		if (list->next == NULL)
			break ;
		list = list->next;
		i++;
	}back_to_start(&list);
}


char	*decoupe(char *str)
{
	int	i;
	char	*tmp;
	
	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '=')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = str[i];
	tmp[i + 1] = '\0';
	return (tmp);
}

int	doublon(t_list *list, char *str, char *tmp, int x)
{
	int i;

	i = ft_strchr_mod(str, '=') + 1;
	if (i == 0)
		i = ft_strlen(str);
	back_to_start(&list);
	while (list)
	{
		if (ft_strncmp(list->str, str, i) == 0)
		{
			if (x == 1)
			{
				free(list->str);
				list->str = ft_strdup(tmp);
			}
			else
			{
				free(list->str);
				list->str = ft_strdup(str);
			}
			return (2);
		}
		else if (ft_strcmp(list->str, str) == 0)
			return (1);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	return (0);
}

int	verif_name(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '=' && str[i])
	{
		if (ft_isalnum(str[i]) != 1)
		{
			if (str[i] == '+' && str[i + 1] == '=')
			{
				return (2);
			}
			return (0);
		}
		i++;
	}
	return (1);
	
}


int join_list(t_list **list, char *name, char *ajout)
{
	int i;
	char	str[100];
	//char	tmp[500];
	
	i = 0;
	while (name[i] != '+')
	{
		str[i] = name[i];
		i++;
	}
	str[i] = '\0';
	back_to_start(list);
	while (*list)
	{
		if (ft_strncmp(str, (*list)->str, ft_strlen(str)) == 0)
		{
			i = ft_strlen((*list)->str) - 1;
			(*list)->str[i] = '\0';
			(*list)->str = ft_strjoin((*list)->str, ajout + 1);
			(*list)->str = ft_strjoin((*list)->str, "\"");
			return (1);
		}
		if ((*list)->next == NULL)
			break ;
		(*list) = (*list)->next;
	}
	back_to_start(list);
	return (1);
}


int built_export(char **split_line, t_list **list, t_list **list_env)
{
	int		x;
	char	*tmp;
	char	*tmp2;
	
	tri_env(list);
	if (ft_strlen_split(split_line) == 1)
	{
		affiche_list(*list);
		return (1);
	}
	else
	{
		x = 1;
		while (split_line[x])
		{
			if (ft_isalpha(split_line[x][0]) != 1 || verif_name(split_line[x]) == 0)
				return (0);
			if (verif_name(split_line[x]) == 1)	
			{
				if (ft_strchr(split_line[x], '=') == NULL )
				{
					if (ft_isalpha(split_line[x][0]) == 1 && doublon(*list, split_line[x], split_line[x], 1) == 0)

						ajout_list(list, split_line[x]);
				}
				else
				{
					if (ft_strcmp(ft_strchr(split_line[x], '='), "=\0") == 0)
					{
						tmp = ft_strjoin(split_line[x], "\"\"");
						if (doublon(*list, split_line[x], tmp, 1) == 0)
							ajout_list(list, tmp);
						if (doublon(*list_env, split_line[x], tmp, 2) == 0)
							ajout_list(list_env, split_line[x]);
					}
					else
					{	
						tmp2 = decoupe(split_line[x]);
						tmp = ft_strjoin(tmp2, "\"");
						tmp2 = ft_strchr(split_line[x], '=');
						tmp2++;
						tmp = ft_strjoin(tmp, tmp2);
						tmp = ft_strjoin(tmp, "\"");
						if (doublon(*list, split_line[x], tmp, 1) == 0)
							ajout_list(list, tmp);
						if (doublon(*list_env, split_line[x], tmp, 2) == 0)
							ajout_list(list_env, split_line[x]);
					}
				}
			}
			else if (verif_name(split_line[x]) == 2)
			{
				join_list(list, split_line[x],ft_strchr(split_line[x], '='));
			}
			x++;
		}
	}
	back_to_start(list);
	back_to_start(list_env);
	return (1);
}


