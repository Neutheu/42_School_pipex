/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:45:09 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:36 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*concat_str(char const *s1, char const *s2, char *new_s)
{
	size_t	index;
	size_t	index_s2;

	index = 0;
	index_s2 = 0;
	while (s1[index])
	{
		new_s[index] = s1[index];
		index++;
	}
	while (s2[index_s2])
	{
		new_s[index] = s2[index_s2];
		index++;
		index_s2++;
	}
	new_s[index] = '\0';
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;

	if (s1 == NULL && s2 == NULL)
		return (malloc(0));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	new_s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
		return (0);
	return (concat_str(s1, s2, new_s));
}
