/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:28:10 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/01 11:18:55 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actual;

	if (!lst)
		return (0);
	actual = lst;
	while (actual)
	{
		if (!actual->next)
			return (actual);
		actual = actual->next;
	}
	return (actual);
}
