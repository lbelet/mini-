#include "minishell.h"

char *ft_set_file(char **cmd, int *j, int i)
{
	int start;
	int len;
	char *tmp;
	char *infile;

	if (cmd[i][*j + 1] != '<' && cmd[i][*j + 1])
	{
		*j = *j + 1;
		start = *j;
		len = 0;
		while (cmd[i][*j] != '<' && cmd[i][*j] != '>' && cmd[i][*j])
		{	
			len++;
			*j = *j + 1;
		}
		tmp = ft_substr(cmd[i], start, len);
		infile = ft_strdup(tmp);
		free(tmp);
		return (infile);
	}
	return (NULL);
}

void ft_files(char **cmd, int *fd, int *j, int *i)
{
	if (cmd[*i][*j] == '<')
	{
		if (cmd[*i][*j + 1] != '<' && cmd[*i][*j + 1])
			ft_infile_nosplit(cmd, fd, j, *i);
		else if (cmd[*i][*j + 1] != '<' && !cmd[*i][*j + 1] && cmd[*i + 1])
			ft_infile_split(cmd, fd, i);
	}
	if (cmd[*i][*j] == '>')
	{
		if (cmd[*i][*j + 1] != '>' && cmd[*i][*j + 1])
			ft_outfile_nosplit(cmd, fd, *i, j);
		else if (cmd[*i][*j + 1] && cmd[*i][*j + 1] == '>')
		{
			*j = *j + 1;
			ft_outfile_nosplit_append(cmd, fd, *i, j);
		}
		else if (cmd[*i][*j + 1] != '>' && !cmd[*i][*j + 1] && cmd[*i + 1])
			ft_outfile_split(cmd, fd, i);
	}
}

void ft_exec_in_out(int *fd, char **commande, char **envp)
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
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path, commande, envp);
	}
	ft_free_tab_simple(commande);
	free(path);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	return;
}