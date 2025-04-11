/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/12 01:47:35 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid2;
	pid_t	pid;

	pid2 = 0;
	if (argc == 5 && parsing(argc, argc, env) == 0)
	{
		pipe(fd);
		if (pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			first_child(argv[1], fd);
			exec(argv[2], env);
			ft_printf("Error with execve\n");
			exit(1);
		}
		pid2 = fork();
		if (pid2 == 0)
		{
			second_child(argv[4], fd);
			exec(argv[3], env);
			ft_printf("Error with execve\n");
			exit(1);
		}
		parent(pid, pid2, fd);
	}
	else
		return (1);
}