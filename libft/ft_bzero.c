/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:50:54 by nsouchal          #+#    #+#             */
/*   Updated: 2023/11/23 09:35:25 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	i = 0;
	buffer = s;
	while (i < n)
	{
		buffer[i] = 0;
		i++;
	}
}
