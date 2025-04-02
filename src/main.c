/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/02 21:18:21 by sxrimu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int fd[2];
//	int infile;
	//int outfile;
	pid_t pid;
	
	if (argc == 5)
		pipe_init(argv, env);
	else
		return (1);
	pipe(fd);
	pid = fork();
	if (pid == -1 || pipe(fd) == -1)
		return 1;
	if (pid == 0)
	{
		close(fd[1]);
	//	infile = open (argv[1], O_CREAT | O_RDONLY);
	//	dup2(infile, STDIN_FILENO);
	//	close(infile);
		close(fd[0]);
		char *arge[] = {"wc -w", NULL};
		execve(argv[1], arge, env);

	}
	else
	{
		close(fd[0]);
	//	outfile = open(argv[4], O_CREAT | O_WRONLY);
		//dup2(outfile, STDOUT_FILENO);
	//	close(fd[1]);
		char *arg[] = {"ls -l", NULL};
		execve(argv[2], arg, env);
	}
}

// int	main(int argc, char **argv)
// {
// 	int fd[2];
// 	char buf;
// 	pipe(fd);
// 	(void)argc;

// 	if (fork() == -1|| pipe(fd) == -1)
// 		return (0);
// 	if (fork() == 0)
// 	{
// 		close(fd[1]);
// 		while (read(fd[0], &buf, 1) > 0)
// 			write(1, &buf, 1);
// 		ft_printf("Fils\n");
// 		close(fd[0]);
// 	}
// 	else
// 	{
// 		close(fd[0]);
// 		write(fd[1], argv[1], ft_strlen(argv[1]));
// 		ft_printf("Pere\n");
// 		close(fd[1]);
// 	}
// }

// int main(int argc, char **argv)
// {
// 	int PversF[2];
// 	int FversP[2];
// 	pipe(PversF);
// 	pipe(FversP);

// }