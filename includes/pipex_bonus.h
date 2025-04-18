/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:40:18 by sberete           #+#    #+#             */
/*   Updated: 2025/04/18 22:02:06 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		pipe_heredoc[2];
	int		fd[2];
	char	**path;
	char	**env;
	bool	here_doc;
	int		len;
	char	*infile;
	char	*outfile;
	pid_t		*pids;

}			t_command;

char		**search_path(char **env);
t_command	init(char **argv, char **env, int argc);
void		children_process(t_command *command, char **argv);
void		dup_2(int new_fd, int old_fd);

#endif