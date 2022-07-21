#include "minishell.h"

int ft_env(char **envp, char **args_in)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
    if (args_in)
    {
        while (args_in[j])
        {
            printf("%s\n", args_in[j]);
            j++;
        }
    }  
    return (0);
}

int ft_env_fd(int fd_out, char **envp, char **args_in)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (envp[i])
    {
        write(fd_out, envp[i], ft_strlen(envp[i]));
        write(fd_out, "\n", 1);
        i++;
    }
    if (args_in)
    {
        while (args_in[j])
        {
            write(fd_out, args_in[j], ft_strlen(args_in[j]));
            write(fd_out, "\n", 1);
            j++;
        }
    }  
    exit (0);
}