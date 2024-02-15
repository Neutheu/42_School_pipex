/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:14:12 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/15 10:37:31 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <sys/wait.h>

void	child_process_1(char **av, char **envp, int *end)
{
	int	f1;

	f1 = open(av[1], O_RDONLY);
	if (f1 == -1)
		handle_error(av[1], strerror(errno), 1, end);
	if (dup2(f1, 0) == -1)
	{
		close(f1);
		handle_error("Error dup2(f1, 0)", strerror(errno), 1, end);
	}
	if (dup2(end[1], 1) == -1)
	{
		close(f1);
		handle_error("Error dup2(end[1], 1)", strerror(errno), 1, end);
	}
	close_pipe(end);
	close (f1);
	exec_cmd(envp, av[2]);
}

void	child_process_2(char **av, char **envp, int *end)
{
	int	f2;

	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f2 == -1)
		handle_error(av[4], strerror(errno), 1, end);
	if (dup2(f2, 1) == -1)
	{
		close(f2);
		handle_error("Error dup2(f2, 1)", strerror(errno), 1, end);
	}
	if (dup2(end[0], 0) == -1)
	{
		close(f2);
		handle_error("Error dup2(end[0], 0)", strerror(errno), 1, end);
	}
	close_pipe(end);
	close (f2);
	exec_cmd(envp, av[3]);
}

int	pipex(char **av, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child_1;
	pid_t	child_2;

	status = 0;
	pipe(end);
	child_1 = fork();
	if (child_1 == -1)
		handle_error("Child_1 fork() Error", strerror(errno), 1, end);
	if (child_1 == 0)
		child_process_1(av, envp, end);
	child_2 = fork();
	if (child_2 == -1)
		handle_error("Child_2 fork() Error", strerror(errno), 1, end);
	if (child_2 == 0)
		child_process_2(av, envp, end);
	close_pipe(end);
	waitpid(child_1, &status, 0);
	waitpid(child_2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	ret;

	ret = 0;
	if (ac != 5)
		return (1);
	ret = pipex(av, envp);
	return (ret);
}
