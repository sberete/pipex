/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:39:59 by sberete           #+#    #+#             */
/*   Updated: 2025/04/22 00:38:43 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**search_path(char **env)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5))
		{
			tmp = env[i];
			break ;
		}
		i++;
	}
	path = ft_split(tmp + 5, ':');
	return (path);
}

void	dup_2(int new_fd, int old_fd)
{
	dup2(new_fd, old_fd);
	close(new_fd);
}

void	free_and_exit(t_command *command, char *str)
{
	perror(str);
	free_tab(command->path);
	if (command->pids != NULL)
		free(command->pids);
	exit(1);
}
