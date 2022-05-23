/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:35:23 by raaga             #+#    #+#             */
/*   Updated: 2022/05/01 20:27:46 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int built_pwd(void)
{
    char    buff[PATH_MAX];
    
    getcwd(buff, sizeof(buff));
    printf("%s\n", buff);
    return (1);
}