/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:27:37 by raaga             #+#    #+#             */
/*   Updated: 2021/12/02 15:43:02 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = 0;
	while (dst[i] && i < size)
		i++;
	s = 0;
	if (size > 0)
	{
		while (src[s] && i < size - 1)
		{
			dst[i] = src[s];
			i++;
			s++;
		}
	}
	if (i - s < size)
		dst[i] = '\0';
	return ((i - s) + ft_strlen(src));
}
