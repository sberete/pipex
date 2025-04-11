/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:00:44 by sxrimu            #+#    #+#             */
/*   Updated: 2025/04/12 01:47:51 by sberete          ###   ########.fr       */
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
	char	*final;
	int		i;

	i = 0;
	final = NULL;
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
	int		i;
	int		j;

	if (!argv[2][0] || !argv[3][0])
		return (1);
	path = search_path(env);
	j = 3;
	split_arg = ft_split(argv[j], ' ');
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			tmp = command_exist(path, split_arg[0]);
			if (!tmp)
			{
				free_tab(path);
				free_tab(split_arg);
				return (1);
			}
			i++;
		}
		j++;
	}
	free_tab(path);
	free_tab(split_arg);
	return (0);
}

// strace -e access
// strace
