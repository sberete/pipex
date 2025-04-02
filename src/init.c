<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:00:44 by sxrimu            #+#    #+#             */
/*   Updated: 2025/04/02 13:48:42 by sxrimu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **search_path(char **env)
{
	char **path;
	char *tmp;
	int i;
	
	i = 0;
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
	return path;
}

char *command_exist(char **path, char *split_arg)
{
	char *tmp;
	char *s;
	
	int i;
	
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], split_arg);
		if (access(tmp, F_OK) == 0)
		{
			ft_printf("La commande existe\n");
			break;
		}
		else
			tmp = NULL;
		i++;
	}
	s = tmp;
	return s;
}

void	pipe_init(char **argv, char **env)
{
	char	**path;
	char	*tmp;
	char	*tmp2;
	char	**split_arg;
	char	**split_arg2;
	
	tmp = NULL;
	if (!argv[2][0] || !argv[3][0])
		exit(1);
	path = search_path(env);
	split_arg = ft_split(argv[2], ' ');
	split_arg2 = ft_split(argv[3], ' ');
	if (!(tmp = command_exist(path, split_arg[0])) || !(tmp2 = command_exist(path, split_arg2[0])))
		exit(1);
	printf("%s, %s\n", tmp, tmp2);
} 

//strace -e access
//strace
=======
#include "pipex.h"

void pipe_init();
>>>>>>> 88b3781224d77094250275f3ff5ccf771b41c143
