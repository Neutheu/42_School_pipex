/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:14:28 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:16:11 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static int	length_nb(unsigned int nb)
{
	int	result;

	result = 0;
	if (nb == 0)
		result = 1;
	while (nb > 0)
	{
		result++;
		nb /= 10;
	}
	return (result);
}

int	printf_u(unsigned int nb)
{
	int	result;

	result = length_nb(nb);
	if (nb >= 10)
	{
		printf_u(nb / 10);
		printf_u(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (result);
}
