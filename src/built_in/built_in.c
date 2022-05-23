/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:39:27 by raaga             #+#    #+#             */
/*   Updated: 2022/05/16 16:03:57 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int is_built_in(t_data *data, char **envp)
{
    if (ft_strcmp(data->split_line[0], "cd") == 0)
        return (built_cd(envp, data->split_line[1]));
    else if (ft_strcmp(data->split_line[0], "pwd") == 0)
        return (built_pwd());
    else if (ft_strcmp(data->split_line[0], "echo") == 0)
        return (built_echo(data));
    else if (ft_strcmp(data->split_line[0], "env") == 0)
        return (built_env(data));
    else if (ft_strcmp(data->split_line[0], "export") == 0)
        return (built_export(data->split_line, &data->list, &data->list_env));
    else if (ft_strcmp(data->split_line[0], "unset") == 0)
        return (built_unset(&data));
    return (0);
}