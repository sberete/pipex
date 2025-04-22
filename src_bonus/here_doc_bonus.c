/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:36:27 by sberete           #+#    #+#             */
/*   Updated: 2025/04/22 00:54:39 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_heredoc(t_command *command)
{
	char	*line;
	int		len;

	line = NULL;
	len = ft_strlen(command->argv[2]);
	if (pipe(command->pipe_heredoc) == -1)
		free_and_exit(command, "Error pipe_heredoc");
	ft_printf("pipe heredoc> ");
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, command->argv[2], len))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, command->pipe_heredoc[1]);
		free(line);
		ft_printf("pipe heredoc> ");
	}
	close(command->pipe_heredoc[1]);
}
