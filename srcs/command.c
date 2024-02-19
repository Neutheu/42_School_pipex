/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:57:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/16 13:39:57 by nsouchal         ###   ########.fr       */
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

	i = -1;
	splited_cmd = ft_split(cmd_with_flags, ' ');
	if (!splited_cmd[0])
		cmd = cmd_with_flags;
	else
		cmd = splited_cmd[0];
	while (all_path[++i])
	{
		path_cmd = ft_strjoin(all_path[i], cmd);
		if (access(path_cmd, X_OK) == 0)
			return (free_two_array(all_path, splited_cmd), path_cmd);
		free(path_cmd);
	}
	free_two_array(all_path, splited_cmd);
	return (cmd_with_flags);
}

void	exec_cmd(char **envp, char *cmd)
{
	char	*path_cmd;
	char	**cmd_array;

	cmd_array = ft_split(cmd, ' ');
	path_cmd = find_valid_path(cmd, find_all_path(envp));
	if (cmd_array[0])
	{
		if (access(cmd_array[0], X_OK) == 0)
			path_cmd = cmd_array[0];
	}
	if (execve(path_cmd, cmd_array, envp) == -1)
	{
		if (ft_strlen(cmd) == 0)
			handle_error("permission denied", "", 2, NULL);
		else
			handle_error(cmd, "command not found", 2, NULL);
		if (ft_strncmp(path_cmd, cmd, ft_strlen(cmd) + 1) != 0)
			free(path_cmd);
	}
	close (0);
	close (1);
	free_double_array(cmd_array);
	exit(127);
}
