/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:35:23 by raaga             #+#    #+#             */
/*   Updated: 2022/05/09 10:07:25 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int built_pwd(void)
{
    char    buff[PATH_MAX];
    
    getcwd(buff, sizeof(buff));
    printf("%s\n", buff);
    return (1);
}