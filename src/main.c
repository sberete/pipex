/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/04 20:58:16 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		infile;
	int		outfile;
	char	**path;
	char	**split_arg;
	char	*command;
	pid_t	pid;
	pid_t	pid2;
	int		status;

	pid2 = 0;
	if (argc == 5)
		pipe_init(argv, env);
	else
		return (1);
	path = search_path(env);
	pipe(fd);
	pid = fork();
	if (pid == -1 || pipe(fd) == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[0]);
		infile = open(argv[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		split_arg = ft_split(argv[2], ' ');
		command = command_exist(path, split_arg[0]);
		execve(command, split_arg, env);
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		outfile = open(argv[4], O_CREAT | O_WRONLY);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		split_arg = ft_split(argv[3], ' ');
		command = command_exist(path, split_arg[0]);
		execve(command, split_arg, env);
		exit(1);
	}
	else
	{
		// close(fd[1]);
		// close(fd[0]);
		waitpid(pid, &status, 0);
		waitpid(pid2, &status, 0);
	}
}
