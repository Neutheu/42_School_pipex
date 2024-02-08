/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:46:14 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:18:24 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	nbr_length(int n, size_t nbr_len)
{
	if (n < 0 || n == 0)
		nbr_len += 2;
	else
		nbr_len += 1;
	if (n < 0)
		n = -n;
	while (n >= 1)
	{
		n /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	size_t		nbr_len;
	char		*nbr;
	int			index;

	nbr_len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr_len = nbr_length(n, nbr_len);
	nbr = malloc(nbr_len * sizeof(char));
	if (!nbr)
		return (0);
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	index = nbr_len - 2;
	while (index >= 0 && nbr[index] != '-')
	{
		nbr[index] = (n % 10) + 48;
		n /= 10;
		index--;
	}
	nbr[nbr_len - 1] = '\0';
	return (nbr);
}
