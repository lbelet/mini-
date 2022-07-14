#include "minishell.h"

char *ft_set_cmd(char **cmd, int *j, int i, int *code_caractere)
{
	int start;
	int len;
	char *tmp;
	char *commande;

	start = *j;
	len = 0;
	while (((cmd[i][*j] != '<' && cmd[i][*j] != '>') || code_caractere[*j] != 6) && cmd[i][*j])
	{	
		len++;
		*j = *j + 1;
	}
	tmp = ft_substr(cmd[i], start, len);
	commande = ft_strdup(tmp);
	free(tmp);
	return (commande);
}

void ft_check_redir(int *fd, char **cmd, char **commande)
{
	int *caractere;
	int i;
	int j;
	int k;
    (void) fd;

	j = 0;
	i = 0;
	k = 0;
	while (cmd[i])
	{	
		caractere = ft_code_char(cmd[i]);
		j = 0;
		while (cmd[i][j])
		{
			if (((cmd[i][j] != '<' && cmd[i][j] != '>') || caractere[j] != 6) && cmd[i][j])
			{
				commande[k] = ft_set_cmd(cmd, &j, i, caractere);
				k++;
			}
			if ((cmd[i][j] == '<' || cmd[i][j] == '>') && caractere[j] == 6)
			{
				ft_files(cmd, fd, &j, &i);
				break;
			}
			j++;	
		}
		free(caractere);
		i++;
	}
	commande[k] = NULL;
	i = 0;
	while (commande[i])
	{
		ft_check_quote_simple(commande[i]);
	//	printf("%s\n", commande[i]);
		i++;
	}
}