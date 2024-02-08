/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:48:47 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:15:49 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(int c, va_list ap)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = printf_c(va_arg(ap, int));
	else if (c == 's')
		result = printf_s(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		result = printf_d_i(va_arg(ap, int));
	else if (c == 'u')
		result = printf_u(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		result = printf_xlow_xupp(va_arg(ap, unsigned int), c);
	else if (c == '%')
		result = printf_c(c);
	else if (c == 'p')
		result = printf_p((long unsigned int)va_arg(ap, void *));
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	size_t	i;
	int		result;

	if (!s)
		return (-1);
	i = 0;
	result = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			result += check_type(s[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			result++;
		}
		i++;
	}
	va_end(ap);
	return (result);
}
