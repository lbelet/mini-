#include "minishell.h"

char    **ft_malloc_tab(char **original)
{
    int i;
    char **sorted;

    i = 0;
    while (original[i])
        i++;
    sorted = malloc((i + 1) *sizeof(char *));
    sorted[i] = NULL;
    return (sorted);
}

char    **ft_malloc_var(char **original)
{
    int i;
    char **sorted;

    i = 1;
    while (original[i])
        i++;
    sorted = malloc(i *sizeof(char *));
    sorted[i - 1] = NULL;
    return (sorted);
}

/*void ft_malloc_pipe(int **fd_pipe, int *pid, int nbr_cmd)
{
    int i;

    i = 0;
    fd_pipe = malloc((nbr_cmd - 1) * sizeof(int*));
    while (i < nbr_cmd -1)
	{
		fd_pipe[i] = malloc(2 * sizeof(int));
		i++;
	}
    pid = malloc(nbr_cmd * sizeof(int));
}*/