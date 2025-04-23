/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/23 22:21:16 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_command	command;

	command = init(argv, env, argc);
	if (argc == 5)
		children_process(&command);
	else
		error_argument(&command);
}
