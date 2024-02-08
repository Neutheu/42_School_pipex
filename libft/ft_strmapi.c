/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:41:00 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:49 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	if (!s)
		return (0);
	i = 0;
	new_s = ft_strdup(s);
	if (!new_s)
		return (0);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
