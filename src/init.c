#include "pipex.h"

void	pipe_init(char **argv, char **env)
{
	char	**path;
	char	*tmp;
	int		i;
	char	**split_arg;
	int		x;

	tmp = NULL;
	if (!argv[2][0] || !argv[3][0])
		exit(1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5))
		{
			tmp = env[i];
			break ;
		}
		i++;
	}
	path = ft_split(tmp + 5, ':');
	i = 0;
    printf("%s\n", path[0]);
	split_arg = ft_split_path(argv[2], ' ');
    tmp = ft_strjoin(path[0], split_arg[0]);
    ft_printf("%s\n", tmp);
	while (path[i])
	{
		if ((x = access(tmp, F_OK)) == 0 && X_OK != -1)
		{
			ft_printf("La commande existe\n");
			break ;
		}
		ft_printf("%d\n", x);
		i++;
	}
}

//strace -e access
//strace