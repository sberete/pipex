/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/03/20 01:43:18 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int	main(int argc, char **argv, char **env)
{
	if (argc == 5)
		pipe_init(argv, env);
	else
		return (0);
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