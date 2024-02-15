/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:07:18 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/15 09:44:18 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_error(char *str1, char *str2, int exit_type, int *end)
{
	write(2, str1, ft_strlen(str1));
	write(2, ": ", 2);
	write(2, str2, ft_strlen(str2));
	write(2, "\n'", 1);
	if (end)
		close_pipe(end);
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
