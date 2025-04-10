#include "pipex.h"

void dup_2(int a, int b)
{
	dup2(a, b);
	close(a);
}

void exec(char *argv, char **env)
{
	char **split;
	char **path;
	char *cmd;
	
	split = ft_split(argv, ' ');
	path = search_path(env);
	cmd = command_exist(path, split[0]);
	//free_tab(split);
	//free_tab(path);
	execve(cmd, split, env);
	//ft_printf("Error with execve\n");
	//exit(1);
}

void first_child(char *argv, int *fd)
{
	int infile;
	
	close(fd[0]);
	infile = open(argv, O_RDONLY);
	if (infile == -1)
		exit(1);
	dup_2(infile, STDIN_FILENO);
	dup_2(fd[1], STDOUT_FILENO);
	//exec(argv, env)
}

void second_child(char *argv, int *fd)
{
	int outfile;
	
	close(fd[1]);
	outfile = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
		exit(1);
	dup_2(fd[0], STDIN_FILENO);
	dup_2(outfile, STDOUT_FILENO);
	//exec(argv, env);
}

void parent(pid_t first_child, pid_t second_child, int *fd)
{
	int status;
	
	close(fd[0]);
	close(fd[1]);
	waitpid(first_child, &status, 0);
	waitpid(second_child, &status, 0);
}