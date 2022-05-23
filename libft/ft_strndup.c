/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:12:23 by raaga             #+#    #+#             */
/*   Updated: 2022/05/18 20:53:47 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strndup(char *str, char c)
{
    int i;
    char    *dest;

    i = 0;
    if (ft_strchr(str, c) == NULL)
        return (NULL);
    while (str[i] != c)
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while (str[i] != c)
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}