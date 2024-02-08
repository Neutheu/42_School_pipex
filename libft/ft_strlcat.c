/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:37:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:40 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	intital_dest_size;
	size_t	src_len;
	size_t	index_dest;
	size_t	index_src;

	intital_dest_size = ft_strlen(dst);
	src_len = ft_strlen(src);
	index_dest = 0;
	index_src = 0;
	if (intital_dest_size < size)
	{
		while (dst[index_dest])
			index_dest++;
		while (src[index_src] && index_dest < size - 1)
		{
			dst[index_dest] = src[index_src];
			index_dest++;
			index_src++;
		}
		dst[index_dest] = '\0';
		return (intital_dest_size + src_len);
	}
	return (size + src_len);
}
