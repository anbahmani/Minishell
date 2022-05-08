/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:30:06 by raaga             #+#    #+#             */
/*   Updated: 2022/05/04 15:34:50 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int built_env(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {    
        write(1, envp[i], ft_strlen(envp[i]));
        write(1, "\n", 1);
        i++;
    }
    return (1);
}