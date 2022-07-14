#include "minishell.h"

int ft_echo(char **cmd_test)
{
    int i;
    int j;
    int k;

    j = 0;
    k = 0;
    i = 1;
    if (!cmd_test[i])
    {
        printf("\n");
        return (0);
    }
    if (ft_strncmp(cmd_test[1], "-n", 2) == 0 && !cmd_test[1][2])
    {
        i = 2;
        if (cmd_test[2])
        {
            while (cmd_test[i] && cmd_test[i + 1])
            {
                printf("%s ", cmd_test[i]);
                i++;
            }
            printf("%s", cmd_test[i]);
        }
    }
    else
    {
        if (cmd_test[1])
        {
            while (cmd_test[i] && cmd_test[i + 1])
            {
                printf("%s ", cmd_test[i]);
                i++;
            }
            printf("%s\n", cmd_test[i]);
        }
    }
    return (EXIT_SUCCESS);
}

int ft_echo_fd(int fd_out, char **cmd_test)
{
    int i;

    if (ft_strncmp(cmd_test[1], "-n", 2) == 0 && !cmd_test[1][2])
    {
        i = 2;
        while (cmd_test[i] && cmd_test[i + 1])
        {
            printf("%s ", cmd_test[i]);
            i++;
        }
        printf("%s", cmd_test[i]);
    }
    else
    {
        i = 1;
        while (cmd_test[i] && cmd_test[i + 1])
        {
            write(fd_out, cmd_test[i], ft_strlen(cmd_test[i]));
            write(fd_out, " ", 1);
            i++;
        }
        write(fd_out, cmd_test[i], ft_strlen(cmd_test[i]));
        write(fd_out, "\n", 1);
    }
    return (0);
}

int ft_write_tmp(int fd_out, char *str)
{
    write(fd_out, &str, ft_strlen(str));
    return (0);
}