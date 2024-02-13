/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:57:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/13 13:01:03 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**find_all_path(char **envp)
{
	int		i;
	char	*path_str;
	char	**all_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			path_str = envp[i];
		i++;
	}
	path_str = ft_substr(path_str, 5, ft_strlen(path_str));
	all_path = ft_split_modified(path_str, ':');
	free (path_str);
	return (all_path);
}

char	*find_valid_path(char *cmd_with_flags, char **all_path)
{
	char	*cmd;
	char	*path_cmd;
	char	**splited_cmd;
	int		i;

	i = 0;
	splited_cmd = ft_split(cmd_with_flags, ' ');
	cmd = splited_cmd[0];
	while (all_path[i])
	{
		path_cmd = ft_strjoin(all_path[i], cmd);
		if (access(path_cmd, F_OK | X_OK) == 0)
			break ;
		free(path_cmd);
		i++;
	}
	free_double_array(all_path);
	free_double_array(splited_cmd);
	return (path_cmd);
}

void	exec_cmd(char **envp, char *cmd)
{
	char	*path_cmd;
	char	**cmd_array;

	cmd_array = ft_split(cmd, ' ');
	path_cmd = find_valid_path(cmd, find_all_path(envp));
	execve(path_cmd, cmd_array, envp);
}