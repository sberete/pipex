/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:40:18 by sberete           #+#    #+#             */
/*   Updated: 2025/04/22 02:53:48 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "ft_printf.h"
# include "get_next_line.h"
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
	char	**argv;
	pid_t	*pids;

}			t_command;

char		**search_path(char **env);
t_command	init(char **argv, char **env, int argc);
void		children_process(t_command *command);
void		dup_2(int new_fd, int old_fd);
void		handle_heredoc(t_command *command);
void		ft_close(int fd);
void		free_and_exit(t_command *command, char *str);
int			open_input_fd(t_command *command);
int			open_output_fd(t_command *command);
#endif