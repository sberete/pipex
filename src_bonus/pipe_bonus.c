/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:36:11 by sberete           #+#    #+#             */
/*   Updated: 2025/04/19 01:48:22 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_and_exit(t_command *command)
{
	int i;

	i = 0;
	perror("Open failure");
	free_tab(command->path);
	free(command->pids);
	exit(1);
}

static void	exec(t_command *command, char *argv)
{
	char	**cmd;
	char *path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (!cmd)
		exit(1);
	while (command->path[i])
	{
		path = ft_strjoin(command->path[i], cmd[0]);
		if (!path)
			break ;
		execve(path, cmd, command->env);
		free(path);
		i++;
	}
	perror("Command not found");
	free_tab(command->path);
	free_tab(cmd);
	free(command->pids);
	exit(1);
}

int	a(t_command *command)
{
	int	read_fd;

	if (command->here_doc == true)
		read_fd = command->pipe_heredoc[0];
	else
	{
		read_fd = open(command->infile, O_RDONLY);
		if (read_fd == -1)
			free_and_exit(command);
	}
	return (read_fd);
}

int	b(t_command *command)
{
	int	write_fd;

	if (command->here_doc == true)
		write_fd = open(command->outfile, O_APPEND | O_WRONLY | O_CREAT, 0644);
	else
		write_fd = open(command->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (write_fd == -1)
		free_and_exit(command);
	return (write_fd);
}

static void	child_process(t_command *command, char *cmd, int prev_read, int i)
{
	int	read_fd;
	int	write_fd;

	if (i == 0)
		read_fd = a(command);
	else
		read_fd = prev_read;
	if (i == command->len - 1)
		write_fd = b(command);
	else
		write_fd = command->fd[1];
	dup_2(read_fd, STDIN_FILENO);
	dup_2(write_fd, STDOUT_FILENO);
	if (i != command->len - 1)
		close(command->fd[0]);
	close(command->fd[1]);
	exec(command, cmd);
}

static void	parent_process(t_command *command, int prev_read)
{
	int	i;

	i = 0;
	close(command->fd[0]);
	close(command->fd[1]);

	while (i < command->len)
		waitpid(command->pids[i++], NULL, 0);
	if (prev_read != -1)
		close(prev_read);
	free(command->pids);
	free_tab(command->path);
}

void	children_process(t_command *command, char **argv)
{
	int	prev_read;
	int	i;
	int	j;

	j = 2 + (command->here_doc == true);
	prev_read = -1;
	i = 0;
	while (i < command->len)
	{
		if (i != command->len - 1 && pipe(command->fd) == -1)
			exit(1);
		command->pids[i] = fork();
		if (command->pids[i] == -1)
			exit(1);
		if (command->pids[i] == 0)
			child_process(command, argv[i + j], prev_read, i);
		if (prev_read != -1)
			close(prev_read);
		if (i != command->len - 1)
			close(command->fd[1]);
		prev_read = command->fd[0];
		i++;
	}
	parent_process(command, prev_read);
}
