/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxrimu <sxrimu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:18:28 by sberete           #+#    #+#             */
/*   Updated: 2025/04/11 00:49:28 by sxrimu           ###   ########.fr       */
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

# define F_OK 0

int	parsing(int argc, char **argv, char **env);
char	**search_path(char **env);
char	*command_exist(char **path, char *split_arg);
void first_child(char *argv, int *fd);
void second_child(char *argv, int *fd);
void parent(pid_t first_child, pid_t second_child, int *fd);
void exec(char *argv, char **env);
#endif