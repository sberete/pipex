/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:00:44 by sxrimu            #+#    #+#             */
/*   Updated: 2025/03/22 01:28:43 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_parce(char **argv, char **env)
{
	char	**split_arg;
	char	**path;
	char	*tmp;
	int		i;
	int		x;

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
		if ((x = access(tmp, F_OK)) == 0)
		{
			ft_printf("La commande existe\n");
			break ;
		}
		ft_printf("Pour : %s, access vaut : %d\n", tmp, x);
		i++;
	}
	split_arg = ft_split(argv[3], ' ');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], split_arg[0]);
		if ((x = access(tmp, F_OK)) == 0)
		{
			ft_printf("La commande existe\n");
			break ;
		}
		ft_printf("Pour : %s, access vaut : %d\n", tmp, x);
		i++;
	}
}

// strace -e access
// strace