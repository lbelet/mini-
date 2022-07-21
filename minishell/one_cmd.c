#include "minishell.h"

void  ft_process_onlyone(char *path_cmd, char **cmd, char **envp)
{
	execve(path_cmd, cmd, envp);
}

int ft_process_one_classic(char **cmd, char **envp)
{
	int pid;
	char *path_cmd;
	char *check_path;

	if (cmd[0][0] != '/')
	{
		path_cmd = ft_path(cmd[0]);
		if (ft_error(path_cmd, cmd) == 0)
		{
			ft_static(1);
			return (0);
		}
	}
	if (cmd[0][0] == '/')
    {
		path_cmd = ft_absolute(cmd);
		cmd[0] = ft_cmd_path(cmd);
        check_path = ft_path(cmd[0]);
        if (ft_strcmp(path_cmd, check_path) != 0)
        {
			printf("Command %s not found\n", path_cmd);
			free(path_cmd);
            ft_static(1);
            return (1);
        }
    }
   	pid = fork();
    if (pid < 0)
       	return (0);
   	if (pid == 0)
	{
        ft_process_onlyone(path_cmd, cmd, envp);
	}
   	waitpid(pid, NULL, 0);
	ft_static(0);
	free(path_cmd);
	ft_free_tab_simple(cmd);
	return (0);
}

void ft_one(char **split_pipe, char **envp)
{
	char **cmd;
	int *fd;
	char **commande;
	int pid;
	int *code_caractere;

	code_caractere = ft_code_char(split_pipe[0]);
	fd = malloc(2 * sizeof(int));
	fd[0] = 0;
	fd[1] = 0;
    cmd = ft_split_modif(split_pipe[0], ' ', code_caractere);
	free(code_caractere);
//	while (cmd[i])
//	{
//		printf("cmd %d : %s\n", i, cmd[i]);
//		i++;
//	}
//	i = 0;
	commande = ft_malloc_tab(cmd);
	commande = ft_check_redir(fd, cmd, commande);
//	while (commande[i])
//	{
//		printf("commande %d : %s\n", i, commande[i]);
//		i++;
//	}
//	ft_execute_inbuilt_fd(fd[1], commande, envp);
	if (ft_check_builtins(commande) == 0)
	{
//		printf("PAS BUILTIN!!!\n");
		if (fd[0] > 0 && fd[1] > 0)
			ft_exec_in_out(fd, commande, envp);
		else if (fd[0] > 0 && fd[1] == 0)
			ft_exec_in(fd[0], commande, envp);
		else if (fd[0] == 0 && fd[1] > 0)
			ft_exec_out(fd[1], commande, envp);
		else if (fd[0] == 0 && fd[1] == 0)
			ft_process_one_classic(commande, envp);
//		ft_free_tab_simple (commande);
	}
	else
	{
		pid = fork();
		if (pid == 0)
			ft_execute_inbuilt_fd(fd[1], commande, envp);
		ft_free_tab_simple(commande);
		waitpid(pid, NULL, 0);
	}
	ft_free_tab_simple(cmd);
	free(fd);
}