/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/17 22:54:20 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_command	command;
	pid_t		*pids;

	command = init(&pids, argv, env, argc);
	if (argc >= 5)
		children_process(&command, pids, argv);
	else
	{
		ft_printf("./pipex <file1> <cmd1> <cmd2> <file2>\n");
		return (1);
	}
}
