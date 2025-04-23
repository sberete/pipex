/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:26:07 by sberete           #+#    #+#             */
/*   Updated: 2025/04/23 00:15:11 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	init(char **argv, char **env, int argc)
{
	t_command	command;

	if (!env || !env[0])
	{
		perror("Env doesn't exist !");
		exit(EXIT_FAILURE);
	}
	ft_memset(&command, 0, sizeof(t_command));
	command.env = env;
	command.argv = argv;
	command.path = search_path(env);
	if (!command.path)
		exit(0);
	command.len = argc - 3;
	command.pids = malloc(sizeof(pid_t) * command.len);
	command.infile = argv[1];
	command.outfile = argv[argc - 1];
	return (command);
}
