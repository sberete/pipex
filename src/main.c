/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/07 18:58:22 by sxrimu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec(char *argv, char **env)
{
	char **split;
	char **path;
	char *cmd;
	
	path = search_path(env);
	split = ft_split(argv, ' ');
	cmd = command_exist(path, split[0]);
	execve(path, split, env);
}
int	main(int argc, char **argv, char **env)
{
	char	**split_arg;
	char	*cmd;
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
		printf("Path = %s\n", cmd);
		infile = open(argv[1], O_RDONLY, 0777);
		dup2(fd[1], STDOUT_FILENO);
		dup2(infile, STDIN_FILENO);
		close(fd[0]);
		//close(infile);
		//close(fd[1]);
		execve(cmd, split_arg, env);
		ft_printf("Error with execve\n");
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
		cmd = command_exist(path, split_arg[0]);
		printf("Path = %s\n", cmd);
		outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[1]);
		//close(fd[0]);
		//close(outfile);
		execve(cmd, split_arg, env);
		ft_printf("Error with execve\n");
		exit(1);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, &status, 0);
		waitpid(pid2, &status, 0);
	}
}
