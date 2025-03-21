/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:00:44 by sxrimu            #+#    #+#             */
/*   Updated: 2025/03/21 20:45:37 by sxrimu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_init(char **argv, char **env)
{
	char	**path;
	char	*tmp;
	int		i;
	char	**split_arg;
	int x;
	tmp = NULL;
	if (!argv[2][0] || !argv[3][0])
		exit(1);
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
	split_arg = ft_split(argv[2], ' ');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], split_arg[0]);
		if ((x = access(tmp, F_OK)) == 0 && X_OK != -1)
		{
			ft_printf("La commande existe\n");
			break ;
		}
		ft_printf("Pour : %s, access vaut : %d\n", tmp, x);
		i++;
	}
} 

//strace -e acddddcess
//strace