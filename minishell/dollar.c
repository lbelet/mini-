#include "minishell.h"

void ft_increase(int *i, int *len)
{
	*i = *i + 1;
	*len = *len + 1;
}

char *ft_tmp(char **envp, char *tmp_bis, int k)
{
	char **split;
	(void) tmp_bis;

	split = ft_split(envp[k], '=');
	free (tmp_bis);
	return(ft_strdup(split[1]));
}

char *ft_change_value(char *str, char **envp, int start, int len)
{
	char *tmp_bis;
	int k;

	tmp_bis = ft_substr(str, start, len);
	k = 0;
	while (envp[k])
	{
		if (ft_strncmp(envp[k], tmp_bis, ft_strlen(tmp_bis) != 0))
			k++;
		else
			return(ft_tmp(envp, tmp_bis, k));

	}
	return NULL;
}

char *ft_check_dollars(char *str, char **envp, int *code_caractere)
{
	int i;
	int start;
	int len;
	char *tmp;
	char *change;

	i = 0;
	len = 0;
	tmp = malloc(0);
	while (str[i])
	{
		if ((str[i] != '$' && str[i] != '?') || (str[i] == '$' && code_caractere[i] == 8))
			tmp = ft_strjoin_modif(tmp, str[i]);
		else if (str[i] == '$' && code_caractere[i] != 8 && str[i + 1] == '?')
		{
			tmp = ft_strjoin(tmp, ft_itoa(ft_static(5)));
		}
		else if(str[i] == '$' && code_caractere[i] != 8 && str[i + 1] != '?')
		{
			i++;
			start = i;
			while (ft_isalnum(str[i]) == 1)
				ft_increase(&i, &len);
			i--;
			if (ft_change_value(str, envp, start, len) != NULL)
				tmp = ft_strjoin(tmp, ft_change_value(str, envp, start, len));
			else
				tmp = ft_strjoin(tmp, ft_change_value(str, g_nos_variables, start, len));
		}
		i++;
	}
	free (str);
	change = ft_strdup(tmp);
	free(tmp);
	return (change);
}