/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/05 18:39:07 by sxrimu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**split_arg;
	char	*command;
	int		outfile;
	int		infile;
	char	**path;
	int		status;
	int		fd[2];
	pid_t	pid2;
	pid_t	pid;

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
		split_arg = ft_split(argv[2], ' ');
		printf("Command 1\nsplit_arg = ");
		for(int i = 0; split_arg[i - 1]; i++)
			printf("%s ", split_arg[i]);
		printf("\n");
		command = command_exist(path, split_arg[0]);
		printf("Path = %s\n", command);
		close(fd[0]);
		infile = open(argv[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(command, split_arg, env);
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		split_arg = ft_split(argv[3], ' ');
		printf("Command 2\nsplit_arg = ");
		for(int i = 0; split_arg[i - 1]; i++)
			printf("%s ", split_arg[i]);
		printf("\n");
		command = command_exist(path, split_arg[0]);
		printf("Path = %s\n", command);
		close(fd[1]);
		outfile = open(argv[4], O_CREAT | O_WRONLY);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execve(command, split_arg, env);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		waitpid(pid2, &status, 0);
		close(fd[1]);
		close(fd[0]);
	}
}
