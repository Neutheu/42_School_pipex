/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:20:23 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:15:58 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static int	length_nb(int nb)
{
	int	result;

	result = 0;
	if (nb == 0)
		result = 1;
	if (nb < 0)
	{
		nb = -nb;
		result += 1;
	}
	while (nb > 0)
	{
		result++;
		nb /= 10;
	}
	return (result);
}

int	printf_d_i(int nb)
{
	int	result;

	if (nb == -2147483648)
	{
		result = 11;
		write(1, "-2147483648", 11);
	}
	else
	{
		result = length_nb(nb);
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			printf_d_i(nb / 10);
			printf_d_i(nb % 10);
		}
		else
			ft_putchar(nb + 48);
	}
	return (result);
}
