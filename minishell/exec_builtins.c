#include "minishell.h"

int ft_check_builtins(char **cmd)
{
    if (ft_strcmp(cmd[0], "echo") == 0)
        return (1);
    else if (ft_strcmp(cmd[0], "exit") == 0)
        return (1);
    else if (ft_strcmp(cmd[0], "pwd") == 0)
        return (1);
    else if (ft_strcmp(cmd[0], "env") == 0)
        return (1);
    else if (ft_strcmp(cmd[0], "cd") == 0)
        return (1);
    else if (ft_strcmp(cmd[0], "export") == 0)
        return (1);
    else if (ft_strcmp(cmd[0], "unset") == 0)
        return (1);
    return (0);
}

void    ft_execute_inbuilt(char **cmd_test, char **envp)
{
//    static char **args_in = NULL;

    if ((ft_strcmp(cmd_test[0], "echo")) == 0)
        ft_echo(&(cmd_test[0]));
    if (ft_strcmp(cmd_test[0], "export") == 0)
         g_nos_variables = ft_export(cmd_test, envp, g_nos_variables);
    if (strcmp(cmd_test[0], "env") == 0)
        ft_env(envp, &(g_nos_variables[0]));
    if (ft_strcmp(cmd_test[0], "cd") == 0)
        ft_cd(cmd_test, envp);
    if (ft_strcmp(cmd_test[0], "unset") == 0)
        ft_unset(cmd_test, &(g_nos_variables[0]));
    if (ft_strcmp(cmd_test[0], "pwd") == 0)
        ft_pwd();
    if ((ft_strcmp(cmd_test[0], "exit")) == 0)
        ft_exit(&(cmd_test[0]));
}

void ft_execute_inbuilt_fd(int fd_out, char **cmd_test, char **envp)
{
    if ((ft_strcmp(cmd_test[0], "echo")) == 0)
        ft_echo_fd(fd_out, cmd_test);
    if (ft_strcmp(cmd_test[0], "export") == 0)
        g_nos_variables = ft_export_fd(fd_out, cmd_test, envp, g_nos_variables);
    if (strcmp(cmd_test[0], "env") == 0)
        ft_env_fd(fd_out, envp, g_nos_variables);
    if (ft_strcmp(cmd_test[0], "cd") == 0)
        ft_cd(cmd_test, envp);
    if (ft_strcmp(cmd_test[0], "unset") == 0)
        ft_unset(cmd_test, &(g_nos_variables[0]));
    if (ft_strcmp(cmd_test[0], "pwd") == 0)
        ft_pwd_fd(fd_out);
    if (ft_strcmp(cmd_test[0], "exit") == 0)
        ft_exit(&(cmd_test[0]));
//    ft_free_tab_simple(cmd_test);
}