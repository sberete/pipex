#ifndef PIPEX_H
#define PIPEX_H

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define F_OK 0
#define X_OK 1
// #define W_OK 3
#define R_OK 4

void	pipe_init(char **argv, char **env);

#endif