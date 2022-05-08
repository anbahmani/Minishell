/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:49:11 by raaga             #+#    #+#             */
/*   Updated: 2021/12/02 15:49:43 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int nb)
{
	if ((nb >= 'A' && nb <= 'Z') || (nb >= 'a' && nb <= 'z'))
		return (1);
	return (0);
}
