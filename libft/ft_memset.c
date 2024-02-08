/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:36:19 by nsouchal          #+#    #+#             */
/*   Updated: 2023/11/23 09:44:50 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	i = 0;
	buffer = s;
	while (i < n)
	{
		buffer[i] = c;
		i++;
	}
	return (buffer);
}
