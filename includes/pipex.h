/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:10:31 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/14 13:22:22 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

char	**ft_split_modified(char const *s, char c);
void	free_double_array(char **array);
void	exec_cmd(char **envp, char *cmd);
void	close_pipe(int *end);
void	handle_error(char *str0, char *str1, char *str2, int exit_type);

#endif
