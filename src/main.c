#include "pipex.h"

int	main(int argc, char **argv)
{
	int fd[2];
	char buf;
	pipe(fd);
	(void)argc;

	if (fork() < 0)
		return ;
	if (fork() == 0)
	{
		close(fd[1]);
		while (read(fd[0], &buf, 1) > 0)
			write(1, &buf, 1);
		ft_printf("Fils\n");
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		write(fd[1], argv[1], ft_strlen(argv[1]));
		ft_printf("Pere\n");
		close(fd[1]);
	}
}