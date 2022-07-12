#include "minishell.h"

int ft_pipes(int **fd, int nbr_cmd)
{
    int j;

    j = 0;
	while (j < nbr_cmd - 1)
	{
		if (pipe(fd[j]) == -1)
      		return (1);
		j++;
	}
    return (0);
}

// ======== ft_1er =========================================================

// ======== ft_middle ==========================================================

// ========= ft_last ===================================================================

// ====== ft_close =============================================================

// ====== ft_wait ========================================================

void ft_waitpid_all(int nbr_cmd, int *pid)
{
    int j;

    j = 0;
	while (j < nbr_cmd)
	{
		waitpid(pid[j], NULL, 0);
		j++;
	}
}

// ===== ft_principal =====================================================

int ft_pipex_multi(char **split_pipe, int nbr_cmd, char **envp)
{
    int *pid;
    int **fd_pipe;
    int *fd_redir;
    int i;
    int k;

    k = 0;
    i = 0;
    fd_pipe = malloc((nbr_cmd - 1) * sizeof(int*));
    while (i < nbr_cmd -1)
		fd_pipe[i++] = malloc(2 * sizeof(int));
    pid = malloc(nbr_cmd * sizeof(int));
    fd_redir = malloc(2 * sizeof(int));
    fd_redir[0] = 0;
    fd_redir[1] = 0;
    ft_pipes(fd_pipe, nbr_cmd);
    i = 0;
    pid[i] = fork();
    if (pid[i] < 0) 
		return (0);
	if (pid[i] == 0)
    {
        ft_close_fl(k, nbr_cmd, fd_pipe);
        ft_first_process(split_pipe, fd_redir, fd_pipe, envp);
    }
    i++;
    while (i < nbr_cmd - 1)
    {
        pid[i] = fork();
        if (pid[i] < 0)
			return (0);
		if (pid[i] == 0)
        {
            ft_close_middle(k, nbr_cmd, fd_pipe);
            ft_middle_process(k, i, split_pipe, fd_redir, fd_pipe, envp);
        }  
        i++;
        k++;
    }
    if (i < nbr_cmd)
    {
		pid[i] = fork();
		if (pid[i] < 0)
			return (0);
		if (pid[i] == 0)
		{	        
            ft_close_fl(k, nbr_cmd, fd_pipe);
            ft_last_process(k, split_pipe, fd_redir, fd_pipe, envp);
		}
    }
    ft_close_all(nbr_cmd, fd_pipe);
    ft_waitpid_all(nbr_cmd, pid);
    ft_free_tab_int(fd_pipe, pid, nbr_cmd);
    free(fd_redir);
    return (0);
}