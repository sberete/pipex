/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:00:44 by sxrimu            #+#    #+#             */
/*   Updated: 2025/04/18 22:01:52 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_command	init(char **argv, char **env, int argc)
{
	t_command	command;

	ft_memset(&command, 0, sizeof(t_command));
	command.env = env;
	command.path = search_path(env);
	if (ft_strncmp(argv[1], "here_doc", 8))
		command.here_doc = true;
	else
		command.here_doc = false;
	command.len = (size_t)argc - 3 + (command.here_doc == true);
	command.pids = malloc(sizeof(pid_t) * command.len);
	command.infile = argv[1];
	command.outfile = argv[argc - 1];
	return (command);
}
