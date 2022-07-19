#include "minishell.h"

int ft_subopen_code_caractere(char  *str, int i)
{    
    if (str[i] == 34)
        return (1);
    if (str[i] == 39)
        return (3);
    return (0);
}

char	*ft_check_quote_simple(char *tab)
{
	int code_quote;
	int j;
	int k;
	char temp[200] = {0};

	j = 0;
	code_quote = 0;
	k = 0;
	while (tab[j])
	{
        if ((tab[j] == 34 || tab[j] == 39) && code_quote == 0)
       	    code_quote = ft_subopen_code_caractere(tab, j);
       	else if ((tab[j] == 34 && code_quote == 1) || (tab[j] == 39 && code_quote == 3))
           	code_quote = 0;
		else if ((code_quote == 0) || (code_quote == 1 && tab[j] != 34) ||
           	    (code_quote == 3 && tab[j] != 39))
			temp[k++] = tab[j];
		j++;
	}
	temp[k] = '\0';
	free(tab);
    tab = ft_strdup(temp);
	return (tab);
}

/*
char	*ft_check_quote(char **tab, int n)
{
	int code_quote;
	int j;
	int k;
	char temp[200] = {0};

	j = 0;
	code_quote = 0;
	k = 0;
	while (tab[n][j])
	{
        if ((tab[n][j] == 34 || tab[n][j] == 39) && code_quote == 0)
            code_quote = ft_subopen_code_caractere(tab[n], j);
        else if ((tab[n][j] == 34 && code_quote == 1) || (tab[n][j] == 39 && code_quote == 3))
            code_quote = 0;
		else if ((code_quote == 0) || (code_quote == 1 && tab[n][j] != 34) ||
                (code_quote == 3 && tab[n][j] != 39))
			temp[k++] = tab[n][j];
		j++;
	}
	temp[k] = '\0';
	free(tab[n]);
    tab[n] = ft_strdup(temp);
    return (tab[n]);
}*/