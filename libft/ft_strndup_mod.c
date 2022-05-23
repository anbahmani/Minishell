/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:52:50 by raaga             #+#    #+#             */
/*   Updated: 2022/05/18 21:34:02 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strndup_mod(char *str, int (*pf)(int), int *y)
{
    int i;
    char    *dest;

    i = 0;
    while ((*pf)(str[i]) == 1)
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while ((*pf)(str[i]) == 1)
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    *y += i;
    return (dest);
}