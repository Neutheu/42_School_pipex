/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_xlow_xupp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:28:14 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:16:15 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static int	length_nb(long unsigned int nb)
{
	int	result;

	result = 0;
	if (nb == 0)
		result = 1;
	while (nb > 0)
	{
		result++;
		nb /= 16;
	}
	return (result);
}

int	printf_xlow_xupp(long unsigned int nb, int c)
{
	char	*base;
	int		result;

	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	result = length_nb(nb);
	if (nb >= 16)
	{
		printf_xlow_xupp(nb / 16, c);
		printf_xlow_xupp(nb % 16, c);
	}
	else
	{
		ft_putchar(base[nb]);
	}
	return (result);
}
