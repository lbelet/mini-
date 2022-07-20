#include "minishell.h"

void ft_infile_nosplit(char **cmd, int *fd, int *j, int i)
{
	char *infile;

	if (fd[0] != 0)
		close(fd[0]);
	infile = ft_set_file(cmd, j, i);
	printf("infile = %s\n", infile);
	ft_check_quote_simple(infile);
	fd[0] = open(infile, O_RDONLY);
	ft_error_fd(fd[0], infile);
	*j += (ft_strlen(infile) + 1);
	free (infile);
}

void ft_infile_split(char **cmd, int *fd, int *i)
{
	char *infile;

	if (fd[0] != 0)
		close(fd[0]);
	*i = *i + 1;
	infile = ft_strdup(cmd[*i]);
	ft_check_quote_simple(infile);
	fd[0] = open(infile, O_RDONLY);
	ft_error_fd(fd[0], infile);
	free (infile);
}

void ft_exec_in(int fd_in, char **commande, char **envp)
{
	char *path;
	int pid;

	path = ft_error_cmd(commande);
	pid = fork();
	if (pid < 0)
		return;
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		execve(path, commande, envp);
	}
	ft_free_tab_simple(commande);
	free(path);
	close(fd_in);
	waitpid(pid, NULL, 0);
	return;
}
