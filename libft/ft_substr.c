/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:43:22 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:59 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	index_new_s;

	index_new_s = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new_s = malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	if (len != 0)
	{
		while (s[start] && index_new_s < len)
		{
			new_s[index_new_s] = s[start];
			index_new_s++;
			start++;
		}
	}
	new_s[index_new_s] = '\0';
	return (new_s);
}
