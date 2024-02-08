/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:04:33 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:55 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	charinstr(char const *str, char const c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_trim(char const *s1, char const *set)
{
	size_t	index;
	size_t	count_trim_char;

	index = 0;
	count_trim_char = 0;
	while (s1[index] && charinstr(set, s1[index]) == 1)
	{
		count_trim_char++;
		index++;
	}
	if (index != ft_strlen(s1))
	{
		index = ft_strlen(s1) - 1;
		while (index >= 0 && charinstr(set, s1[index]) == 1)
		{
			count_trim_char++;
			index--;
		}
	}
	return (count_trim_char);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new_s;
	size_t		len_new_s;
	size_t		count_trim_char;
	size_t		index;
	size_t		index_new_s;

	if (!s1)
		return (0);
	index = 0;
	index_new_s = 0;
	count_trim_char = count_trim(s1, set);
	len_new_s = ft_strlen(s1) - count_trim_char + 1;
	new_s = malloc(len_new_s * sizeof(char));
	if (!new_s)
		return (0);
	while (s1[index] && charinstr(set, s1[index]) == 1)
		index++;
	while (s1[index] && index_new_s < len_new_s - 1)
	{
		new_s[index_new_s] = s1[index];
		index++;
		index_new_s++;
	}
	new_s[index_new_s] = '\0';
	return (new_s);
}
