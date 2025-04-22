/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_suits_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:23:43 by sberete           #+#    #+#             */
/*   Updated: 2025/04/22 02:58:39 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_input_fd(t_command *command)
{
	int	read_fd;

	if (command->here_doc == true)
		read_fd = command->pipe_heredoc[0];
	else
	{
		read_fd = open(command->infile, O_RDONLY);
		if (read_fd == -1)
		{
			close(command->fd[1]);
			close(command->fd[0]);
			free_and_exit(command, "Infile open failure");
		}
	}
	return (read_fd);
}

int	open_output_fd(t_command *command)
{
	int	write_fd;

	if (command->here_doc == true)
		write_fd = open(command->outfile, O_APPEND | O_WRONLY | O_CREAT, 0644);
	else
		write_fd = open(command->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (write_fd == -1)
	{
		close(command->fd[0]);
		free_and_exit(command, "Outfile open failure");
	}
	return (write_fd);
}
