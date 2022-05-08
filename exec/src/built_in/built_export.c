/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramsy <ramsy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:25:04 by raaga             #+#    #+#             */
/*   Updated: 2022/05/08 15:47:54 by ramsy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


int built_export(char **split_line, char **envp)
{
    int i;
    int x;
    char    *tmp;

    i = 0;
    
    while (envp[i])
    {
        x = i + 1;
        while (envp[x])
        {
            if (ft_strcmp(envp[i], envp[x]) > 0)
            {
                tmp = ft_strdup(envp[i]);
                envp[i] = ft_strdup(envp[x]);
                envp[x] = ft_strdup(tmp);
            }
            x++;
        }
        i++;
    }
    
    if (ft_strlen_split(split_line) == 1)
    {
        i = 0;
        while (envp[i])
        {
            write(1, "export ", ft_strlen("export "));
            write(1, envp[i], ft_strlen(envp[i]));
            write(1, "\n", 1);
            i++;
        }
    }
    else
    {
        x = 1;
        while (split_line[x])
        {
            if (ft_isalpha(split_line[x][0]) == 1)
            {
                break ;
            }
        }
    }
    return (1);
}