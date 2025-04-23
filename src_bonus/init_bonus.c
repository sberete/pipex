/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:00:44 by sxrimu            #+#    #+#             */
/*   Updated: 2025/04/24 01:11:26 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	command.path = search_path(env);
	if (!command.path)
		exit(1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		command.here_doc = true;
	else
		command.here_doc = false;
	command.argv = argv;
	command.len = argc - 3 - (command.here_doc == true);
	command.pids = malloc(sizeof(pid_t) * command.len);
	command.infile = command.argv[1];
	command.outfile = command.argv[argc - 1];
	return (command);
}
