#include "minishell.h"

void  ft_process_onlyone_output(int fd_out, char *path_cmd, char **cmd, char **envp)
{
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execve(path_cmd, cmd, envp);
}

void ft_outfile_split(char **cmd, int *fd, int *i)
{
	char *outfile;

	if (fd[1] != 0)
		close(fd[1]);
	*i = *i + 1;
	outfile = ft_strdup(cmd[*i]);
	ft_check_quote_simple(outfile);
	fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	ft_error_fd(fd[1], outfile);
	free (outfile);
}

void ft_outfile_nosplit(char **cmd, int *fd, int i, int *j)
{
	char *outfile;

	if (fd[1] != 0)
		close(fd[1]);
	outfile = ft_set_file(cmd, j, i);
	ft_check_quote_simple(outfile);
	fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	ft_error_fd(fd[1], outfile);
	*j += (ft_strlen(outfile) + 1);
	free (outfile);
}

void ft_outfile_nosplit_append(char **cmd, int *fd, int i, int *j)
{
	char *outfile;

	if (fd[1] != 0)
		close(fd[1]);
	outfile = ft_set_file(cmd, j, i);
	ft_check_quote_simple(outfile);
	printf("outfile: %s\n", outfile);
	fd[1] = open(outfile, O_RDWR | O_APPEND | O_CREAT, 0666);
	ft_error_fd(fd[1], outfile);
	*j += (ft_strlen(outfile) + 1);
	free (outfile);
}

void ft_exec_out(int fd_out, char **commande, char **envp)
{
	char *path;
	int pid;

	path = ft_path(commande[0]);
	if (ft_error(path, commande) == 0)
		return;
	pid = fork();
	if (pid < 0)
		return;
	if (pid == 0)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		execve(path, commande, envp);
	}
	ft_free_tab_simple(commande);
	free(path);
	close(fd_out);
	waitpid(pid, NULL, 0);
	return;
}