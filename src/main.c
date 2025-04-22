/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:28:02 by sberete           #+#    #+#             */
/*   Updated: 2025/04/22 00:39:52 by sberete          ###   ########.fr       */
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
	{
		ft_printf("./pipex <file1> <cmd1> <cmd2> <file2>\n");
		free_and_exit(&command, "Wrong numbers of arguments");
	}
}
