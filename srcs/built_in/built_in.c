/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:39:27 by raaga             #+#    #+#             */
/*   Updated: 2022/05/09 10:07:25 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_built_in(t_data *data, char **envp)
{
    if (ft_strcmp(data->split_line[0], "cd") == 0)
        return (built_cd(envp, data->split_line[1]));
    else if (ft_strcmp(data->split_line[0], "pwd") == 0)
        return (built_pwd());
    else if (ft_strcmp(data->split_line[0], "echo") == 0)
        return (built_echo(data));
    else if (ft_strcmp(data->split_line[0], "env") == 0)
        return (built_env(envp));
    else if (ft_strcmp(data->split_line[0], "export") == 0)
        return (built_export(data->split_line, data->env_tmp));
    return (0);
}