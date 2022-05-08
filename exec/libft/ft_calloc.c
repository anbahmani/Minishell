/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:29:22 by raaga             #+#    #+#             */
/*   Updated: 2021/12/02 15:37:33 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t octet)
{
	void	*tab;

	tab = malloc(octet * nmemb);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, octet * nmemb);
	return (tab);
}
