/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:57:19 by raaga             #+#    #+#             */
/*   Updated: 2021/12/01 14:18:06 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		z;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && n > i)
	{
		if (big[i] == little[0])
		{
			z = 0;
			while (little[z] && big[i + z] && i + z < n
				&& big[i + z] == little[z])
				z++;
			if (little[z] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
