#ifndef PIPEX_H
#define PIPEX_H

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
<<<<<<< HEAD
=======
#include <fcntl.h>
>>>>>>> 88b3781224d77094250275f3ff5ccf771b41c143
#include <stdio.h>
#include <fcntl.h>

#define F_OK 0
#define X_OK 1
// #define W_OK 3
#define R_OK 4

void	pipe_parce(char **argv, char **env);

#endif