/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:18:28 by sberete           #+#    #+#             */
/*   Updated: 2025/04/03 19:15:55 by sberete          ###   ########.fr       */
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
# define X_OK 1
// #define W_OK 3
# define R_OK 4

void	pipe_init(char **argv, char **env);
char	**search_path(char **env);
char	*command_exist(char **path, char *split_arg);

#endif