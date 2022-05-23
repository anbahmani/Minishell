/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:41:21 by raaga             #+#    #+#             */
/*   Updated: 2021/12/02 17:16:07 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	taille(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		compteur;

	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	if (n == 0)
		return (ft_substr("0", 0, 1));
	compteur = taille(n);
	nb = (char *)malloc(sizeof(char) * (compteur + 1));
	if (!nb)
		return (NULL);
	nb[compteur] = '\0';
	if (n < 0)
	{
		nb[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		nb[--compteur] = (n % 10) + 48;
		n /= 10;
	}
	return (nb);
}
