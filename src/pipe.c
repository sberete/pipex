/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:36:11 by sberete           #+#    #+#             */
/*   Updated: 2025/04/17 21:33:30 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_and_exit(t_command *command)
{
	perror("Open failure");
	free_tab(command->path);
	exit(1);
}

static void	exec(char **paths, char **env, char *argv)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		exit(1);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd[0]);
		if (!path)
			break ;
		execve(path, cmd, env);
		free(path);
		i++;
	}
	perror("Command not found");
	free_tab(paths);
	exit(1);
}

static void	child_process(t_command *command, char *cmd, int prev_read, int i)
{
	int	read_fd;
	int	write_fd;

	if (i == 0)
	{
		read_fd = open(command->infile, O_RDONLY);
		if (read_fd == -1)
			free_and_exit(command);
	}
	else
		read_fd = prev_read;
	if (i == command->len - 1)
	{
		write_fd = open(command->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (write_fd == -1)
			free_and_exit(command);
	}
	else
		write_fd = command->fd[1];
	dup_2(read_fd, STDIN_FILENO);
	dup_2(write_fd, STDOUT_FILENO);
	if (i != command->len - 1)
		close(command->fd[0]);
	exec(command->path, command->env, cmd);
}

static void	parent_process(t_command *command, pid_t *pids, int prev_read)
{
	int	i;

	i = 0;
	while (i < command->len)
		waitpid(pids[i++], NULL, 0);
	if (prev_read != -1)
		close(prev_read);
	free(pids);
	free_tab(command->path);
}

void	children_process(t_command *command, pid_t *pids, char **argv)
{
	int	prev_read;
	int	i;
	int	j;

	prev_read = -1;
	i = 0;
	j = 2;
	while (i < command->len)
	{
		if (i != command->len - 1 && pipe(command->fd) == -1)
			exit(1);
		pids[i] = fork();
		if (pids[i] == -1)
			exit(1);
		if (pids[i] == 0)
			child_process(command, argv[i + j], prev_read, i);
		if (prev_read != -1)
			close(prev_read);
		if (i != command->len - 1)
			close(command->fd[1]);
		prev_read = command->fd[0];
		i++;
	}
	parent_process(command, pids, prev_read);
}
