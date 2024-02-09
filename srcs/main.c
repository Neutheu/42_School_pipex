/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:14:12 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/09 11:57:44 by nsouchal         ###   ########.fr       */
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

void	child_process_1(char **av, char **envp, int *end)
{
	int	f1;

	f1 = open(av[1], O_RDONLY);
	dup2(f1, 0);
	dup2(end[1], 1);
	close (end[0]);
	close (end[1]);
	close (f1);
	exec_cmd(envp, av[2]);
}

void	child_process_2(char **av, char **envp, int *end)
{
	int	f2;

	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(f2, 1);
	dup2(end[0], 0);
	close (end[0]);
	close (end[1]);
	close (f2);
	exec_cmd(envp, av[3]);
}

void	pipex(char **av, char **envp)
{
	int		end[2];
	pid_t	child_1;
	pid_t	child_2;

	pipe(end);
	child_1 = fork();
	// if (child[0] == -1)
	// 	return ()
	if (child_1 == 0)
		child_process_1(av, envp, end);
	child_2 = fork();
	if (child_2 == 0)
		child_process_2(av, envp, end);
	close(end[0]);
	close(end[1]);
	waitpid(child_1, NULL, 0);
	waitpid(child_2, NULL, 0);
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	pipex(av, envp);
	return (0);
}
