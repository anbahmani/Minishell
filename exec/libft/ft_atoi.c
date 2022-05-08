/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:58:24 by raaga             #+#    #+#             */
/*   Updated: 2021/12/02 15:49:01 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;
	int	compteur;

	i = 0;
	sign = 1;
	result = 0;
	compteur = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		compteur++;
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (compteur >= 20 && sign != -1)
		return (-1);
	else if (compteur >= 20 && sign == -1)
		return (0);
	return (result * sign);
}
