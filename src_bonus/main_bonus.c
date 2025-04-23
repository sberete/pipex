/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/23 19:53:56 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_command	command;

	command = init(argv, env, argc);
	if (argc >= 5)
	{
		if (command.here_doc == 1 && argc != 6)
			error_argument(&command);
		else if (command.here_doc == 1)
			handle_heredoc(&command);
		children_process(&command);
	}
	else
		error_argument(&command);
}
