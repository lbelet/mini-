#include "minishell.h"

int    ft_pwd(void)
{
    char    *cwd;

    cwd = NULL;
    cwd = getcwd(cwd, 0);
    if (cwd == NULL)
    {
        perror("Error");
        return (EXIT_FAILURE);
    }
    else
        printf("%s\n", cwd);
    return (EXIT_SUCCESS);
}

int    ft_pwd_fd(int fd_out)
{
    char    *cwd;

    cwd = NULL;
    cwd = getcwd(cwd, 0);
    if (cwd == NULL)
    {
        perror("Error");
        exit (1);
    }
    else
        write(fd_out, cwd, ft_strlen(cwd));
        write(fd_out, "\n", 1);
    exit (0);
}