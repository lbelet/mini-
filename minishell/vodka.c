#include "minishell.h"

char *ft_cmd_path(char **cmd)
{
	char **tmp;
	int i;

	i = 0;
	printf("cmd avant: %s\n", cmd[0]);
	tmp = ft_split(cmd[0], '/');
	free(cmd[0]);
	while (tmp[i])
		i++;
	cmd[0] = ft_strdup(tmp[i - 1]);
	printf("cmd apres: %s\n", cmd[0]);
	ft_free_tab_simple(tmp);
	return (cmd[0]);
}

char *ft_absolute(char **cmd)
{
    char *path_cmd;
    
	path_cmd = ft_strdup(cmd[0]);
//	ft_cmd_path(cmd);
    return (path_cmd);
}