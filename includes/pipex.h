/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:18:28 by sberete           #+#    #+#             */
/*   Updated: 2025/04/22 00:38:22 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_command
{
	int		fd[2];
	char	**path;
	char	**env;
	int		len;
	char	*infile;
	char	*outfile;
	char	**argv;
	pid_t	*pids;

}			t_command;

t_command	init(char **argv, char **env, int argc);
char		**search_path(char **env);
void		dup_2(int new_fd, int old_fd);
void		children_process(t_command *command);
void		free_and_exit(t_command *command, char *str);

#endif