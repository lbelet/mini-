#include "minishell.h"

int ft_nbr_args(char **cmd_test)
{
    int i;
    int nbr_args;

    i = 1;
    nbr_args = 0;
    while (cmd_test[i])
    {
        i++;
        nbr_args++;
    }
    return (nbr_args);
}

void    ft_sort_alpha(char **sorted)
{
    int k;
    int j;
    char *tmp;

    k = 0;
    j = 0;
    while (sorted[k])
    {
        j = 0;
        while (sorted[j])
        {
            if (ft_strcmp(sorted[k], sorted[j]) < 0)
            {
                tmp = ft_strdup(sorted[k]);
                free(sorted[k]);
                sorted[k] = ft_strdup(sorted[j]);
                free(sorted[j]);
                sorted[j] = ft_strdup(tmp);
                free(tmp);
            }
            j++;
        }
        k++;
    }
}

void    ft_printf_all(char **sorted)
{
    int i;

    i = 0;
    while (sorted[i])
    {
        printf("declare -x %s\n", sorted[i]);
        i++;
    }  
}

void    ft_write_all(int fd_out, char **sorted)
{
    int i;

    i = 0;
    while (sorted[i])
    {
        write(fd_out, "declare -x ", 11);
        write(fd_out, sorted[i], ft_strlen(sorted[i]));
        write(fd_out, "\n", 1);
        i++;
    }  
}