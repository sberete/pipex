/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:26:07 by sberete           #+#    #+#             */
/*   Updated: 2025/04/17 21:39:29 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	init(pid_t **pids, char **argv, char **env, int argc)
{
	t_command	command;

	ft_memset(&command, 0, sizeof(t_command));
	command.env = env;
	command.path = search_path(env);
	command.len = argc - 3;
	*pids = malloc(sizeof(pid_t) * command.len);
	command.infile = argv[1];
	command.outfile = argv[argc - 1];
	return (command);
}
