/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:30:06 by raaga             #+#    #+#             */
/*   Updated: 2022/05/12 17:13:17 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int built_env(t_data *data)
{
    while (data->list_env != NULL)
    {    
        write(1, data->list_env->str, ft_strlen(data->list_env->str));
        write(1, "\n", 1);
        if (data->list_env->next == NULL)
        {
            back_to_start(&data->list_env);
            break ;
        }
        data->list_env = data->list_env->next;
    }
    return (1);
}