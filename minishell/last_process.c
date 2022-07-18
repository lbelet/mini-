#include "minishell.h"

void  ft_process_last(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp)
{
  dup2(fd_in, STDIN_FILENO);
  close(fd_in);
  close(fd_out);
  execve(path_cmd, cmd, envp);
}

void  ft_process_last_out(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp)
{
  dup2(fd_in, STDIN_FILENO);
  dup2(fd_out, STDOUT_FILENO);
  close(fd_in);
  close(fd_out);
  execve(path_cmd, cmd, envp);
}

void ft_last_process(int k, char **split_pipe, int *fd_redir, int **fd_pipe, char **envp)
{
    char **commande;
    char **split_space;
    char *path_cmd;
    int i;

    if (fd_redir[1] > 0)
    {
        fd_redir[0] = fd_redir[1];
        fd_redir[1] = 0;
    }
    i = ft_nbr_args(split_pipe);
    split_space = ft_split_modif(split_pipe[i], ' ', ft_code_char(split_pipe[i]));
    commande = ft_malloc_tab(split_space);
    ft_check_redir(fd_redir, split_space, commande);
	if (commande[0][0] != '/')
	{
		path_cmd = ft_path(commande[0]);
		if (ft_error(path_cmd, commande) == 0)
		{
			ft_static(1);
			return;
		}
	}
	if (commande[0][0] == '/')
		path_cmd = ft_absolute(commande);
    if (fd_redir[0] == 0 && fd_redir[1] == 0)
	    ft_process_last(fd_pipe[k][0], fd_pipe[k][1], path_cmd, commande, envp);
    else if (fd_redir[0] > 0 && fd_redir[1] == 0)
    {
        close(fd_pipe[k][0]);
        ft_process_last(fd_redir[0], fd_pipe[k][1], path_cmd, commande, envp);
    }
    else if (fd_redir[0] == 0 && fd_redir[1] > 0)
    {
        close(fd_pipe[k][1]);
	    ft_process_last_out(fd_pipe[k][0], fd_redir[1], path_cmd, commande, envp);
    }
    else if (fd_redir[0] > 0 && fd_redir[1] > 1)
    {
        close(fd_pipe[k][0]);
        close(fd_pipe[k][1]);
        ft_process_last_out(fd_redir[0], fd_redir[1], path_cmd, commande, envp);
    }
}