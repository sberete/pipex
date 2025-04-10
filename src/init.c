/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:00:44 by sxrimu            #+#    #+#             */
/*   Updated: 2025/04/11 01:20:26 by sxrimu           ###   ########.fr       */
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

char	*command_exist(char **path, char *split_arg)
{
	char	*tmp;
	char *final;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], split_arg);
		if (access(tmp, F_OK) == 0)
		{
			final = tmp;
			break ;
		}
		else
			free(tmp);
		i++;
	}
	return (final);
}

int	parsing(int argc, char **argv, char **env)
{
	char	**path;
	char	*tmp;
	char	**split_arg;
	int 	i;
	
	if (!argv[2][0] || !argv[3][0])
	return 1;
	path = search_path(env);
	split_arg = ft_split(argv[i], ' ');
	i = 3;
	while (i < argc - 1)
	{
		
	}
	
	if (!(tmp = command_exist(path, split_arg[0])));

	return (0);
}

// strace -e access
// strace
