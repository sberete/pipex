/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:39:59 by sberete           #+#    #+#             */
/*   Updated: 2025/04/23 04:20:47 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (tmp == NULL)
		return (NULL);
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

void	error_argument(t_command *command)
{
	if (command->path != NULL)
		free_tab(command->path);
	if (command->pids != NULL)
		free(command->pids);
	ft_printf("Wrong numbers of arguments\nTry this :\n");
	ft_printf("./pipex <file1> <cmd1> <cmd2> <cmd3> ... <cmdn> <file2>\n");
	ft_printf("./pipex here_doc LIMITEUR <cmd1> <cmd2> <file2>\n");
	exit(1);
}
