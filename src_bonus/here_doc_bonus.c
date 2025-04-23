/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:36:27 by sberete           #+#    #+#             */
/*   Updated: 2025/04/24 00:23:24 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static bool	heredoc_limiter_match(const char *line, const char *limiter)
{
	size_t	i;

	if (!line || !limiter)
		return (false);
	i = 0;
	while (limiter[i] && line[i] && line[i] == limiter[i])
		i++;
	if (limiter[i] != '\0')
		return (false);
	if (line[i] != '\n')
		return (false);
	return (true);
}

void	handle_heredoc(t_command *command)
{
	char	*line;

	if (pipe(command->pipe_heredoc) == -1)
		free_and_exit(command, "Error pipe_heredoc");
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (heredoc_limiter_match(line, command->argv[2]))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, command->pipe_heredoc[1]);
		free(line);
	}
	close(command->pipe_heredoc[1]);
}
