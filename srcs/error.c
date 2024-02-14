/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:07:18 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/14 13:31:00 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_error(char *str0, char *str1, char *str2, int exit_type)
{
	write(2, str0, ft_strlen(str0));
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	write(2, "\n'", 1);
	if (exit_type == 0)
		exit(EXIT_SUCCESS);
	if (exit_type == 1)
		exit(EXIT_FAILURE);
}

void	close_pipe(int *end)
{
	close(end[0]);
	close(end[1]);
}
