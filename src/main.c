/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/03/27 02:39:27 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	int status;
	int infile;
	int outfile;
	char buf;
	if (argc == 5)
		pipe_parce(argv, env);
	else
		return (0);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		close(fd[1]);
		outfile = open(argv[4], O_RDONLY);
		dup2(outfile, 1); 
		close(outfile);
		dup2(fd[0], 0);
		read(fd[0], &buf, 100);
		close(fd[0]);
		// execve(); la cmd 2
		// ft_printf("Fils -> PID : %d, PPID : %d\n", getpid(), getppid());
		// printf("");
	}
	else
	{
		wait(&status);
		close(fd[0]);
		infile = open(argv[1], O_WRONLY);
		dup2(infile, 0);
		close(infile);
		dup2(fd[1], 1);
		// write(fd[1], );
		// ft_printf("Pere -> PID %d, PPID : %d, PID -> Fils : %d\n", getpid(), getppid(), pid);
		close(fd[1]);
		// execve(); la cmd 1
		// ft_printf("Pere -> Le fils %d s'est termine\n", fils);
	}
}
