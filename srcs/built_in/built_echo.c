/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:08:30 by raaga             #+#    #+#             */
/*   Updated: 2022/05/09 10:07:25 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int built_echo(t_data *data)
{
    char *s;
    int i;

    if (data->split_line[1] == NULL)
        return (1);
    if (ft_strcmp(data->split_line[1], "-n") == 0)
    {
        s = data->split_line[2];
        i = 3;
        while (data->split_line[i])
        {
            if (data->split_line[i] != NULL)
                s = ft_strjoin(s , " ");
            s = ft_strjoin(s, data->split_line[i]);
            i++;
        }
        printf("%s", s);
    }
    else
    {
        s = data->split_line[1];
        i = 2;
        while (data->split_line[i])
        {
            if (data->split_line[i] != NULL)
                s = ft_strjoin(s , " ");
            s = ft_strjoin(s ,data->split_line[i]);
            i++;
        }
        printf("%s\n", s);
    }
    return (1);
}