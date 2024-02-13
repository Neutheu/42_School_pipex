/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:14:12 by nsouchal          #+#    #+#             */
/*   Updated: 2024/02/13 13:26:23 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process_1(char **av, char **envp, int *end)
{
	int	f1;

	f1 = open(av[1], O_RDONLY);
	if (f1 == -1)
	{
		close_pipe(end);
		handle_error("Error opening infile", 1);
	}
	if (dup2(f1, 0) == -1)
	{
		close_pipe(end);
		close(f1);
		handle_error("Error dup2(f1, 0)", 1);
	}
	if (dup2(end[1], 1) == -1)
	{
		close_pipe(end);
		close(f1);
		handle_error("Error dup2(end[1], 1)", 1);
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
	{
		close_pipe(end);
		handle_error("Error opening outfile", 1);
	}
	dup2(f2, 1);
	dup2(end[0], 0);
	close_pipe(end);
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
	if (child_1 == -1)
	{
		close_pipe(end);
		handle_error("Child_1 fork() Error", 1);
	}
	if (child_1 == 0)
		child_process_1(av, envp, end);
	child_2 = fork();
	if (child_2 == -1)
	{
		close_pipe(end);
		handle_error("Child_2 fork() Error", 1);
	}
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
