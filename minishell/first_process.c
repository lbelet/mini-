#include "minishell.h"

void  ft_no_in_process(int fd_in, int fd_out, char **cmd, char **envp)
{
    char *path_cmd;

	if (cmd[0][0] != '/')
	{
		path_cmd = ft_path(cmd[0]);
		if (ft_error(path_cmd, cmd) == 0)
		{
			ft_static(1);
			return;
		}
	}
	if (cmd[0][0] == '/')
		path_cmd = ft_absolute(cmd);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_in);
    close(fd_out);
    execve(path_cmd, cmd, envp);
}

void  ft_in_process(int fd_in, int fd_out, char **cmd, char **envp)
{
    char *path_cmd;

	if (cmd[0][0] != '/')
	{
		path_cmd = ft_path(cmd[0]);
		if (ft_error(path_cmd, cmd) == 0)
		{
			ft_static(1);
			return;
		}
	}
	if (cmd[0][0] == '/')
		path_cmd = ft_absolute(cmd);
    dup2(fd_out, STDOUT_FILENO);
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
    close(fd_out);
    execve(path_cmd, cmd, envp);
}

void ft_first_process(char **split_pipe, int *fd_redir, int **fd_pipe, char **envp)
{
    char **commande;
    char **split_space;
    int k;
    int i;

    i = 0;
    k = 0;
    if (i < 1)
    {
        split_space = ft_split_modif(split_pipe[i], ' ', ft_code_char(split_pipe[i]));
        commande = ft_malloc_tab(split_space);
        ft_check_redir(fd_redir, split_space, commande);
       	ft_execute_inbuilt(commande, envp);
        if (ft_check_builtins(commande) == 0)
        {
            printf("PAS BUILTIN\n");
            if (fd_redir[0] > 0 && fd_redir[1] > 0)
            {
                close (fd_pipe[k][0]);
                close (fd_pipe[k][1]);
                ft_in_process(fd_redir[0], fd_redir[1], commande, envp);
                fd_redir[0] = 0;
            }
		    else if (fd_redir[0] > 0 && fd_redir[1] == 0)
            {
                close(fd_pipe[k][0]);
    		    ft_in_process(fd_redir[0], fd_pipe[k][1], commande, envp);
                fd_redir[0] = 0;
            }
    	    else if (fd_redir[0] == 0 && fd_redir[1] > 0)
            {
                close(fd_pipe[k][1]);
		        ft_no_in_process(fd_pipe[k][0], fd_redir[1], commande, envp);
            }
	    	else if (fd_redir[0] == 0 && fd_redir[1] == 0)
		        ft_no_in_process(fd_pipe[k][0], fd_pipe[k][1], commande, envp);
        }
    }
}