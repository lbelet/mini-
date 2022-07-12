#include "minishell.h"

void  ft_process_middle_bis(int fd_in, int fd_out, char **cmd, char **envp)
{
    char *path_cmd;

    path_cmd = ft_path(cmd[0]);
    dup2(fd_in, STDIN_FILENO);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_in);
    close(fd_out);
    execve(path_cmd, cmd, envp);
}

void ft_middle_process(int k, int i, char **split_pipe, int *fd_redir, int **fd_pipe, char **envp)
{
    char **split_space;
    char **commande;

    if (fd_redir[1] > 0)
    {
        fd_redir[0] = fd_redir[1];
        fd_redir[1] = 0;
    }
    split_space = ft_split_modif(split_pipe[i], ' ', ft_code_char(split_pipe[i]));
    commande = ft_malloc_tab(split_space);
    ft_check_redir(fd_redir, split_space, commande);
    if (fd_redir[0] > 0 && fd_redir[1] > 0)
    {
        close (fd_pipe[k][0]);
        close (fd_pipe[k + 1][1]);
        ft_process_middle_bis(fd_redir[0], fd_redir[1], commande, envp);
        fd_redir[0] = 0;
    }
    else if (fd_redir[0] > 0 && fd_redir[1] == 0)
    {
        close(fd_pipe[k][0]);
        ft_process_middle_bis(fd_redir[0], fd_pipe[k + 1][1], commande, envp);
        fd_redir[0] = 0;
    }
    else if (fd_redir[0] == 0 && fd_redir[1] > 0)
    {
        close(fd_pipe[k + 1][1]);
	    ft_process_middle_bis(fd_pipe[k][0], fd_redir[1], commande, envp);
    }
	else if (fd_redir[0] == 0 && fd_redir[1] == 0)
	    ft_process_middle_bis(fd_pipe[k][0], fd_pipe[k + 1][1], commande, envp);
}
