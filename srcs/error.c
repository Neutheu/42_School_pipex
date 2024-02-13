/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:07:18 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/13 13:07:51 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_error(char *str, int exit_type)
{
	perror(str);
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
