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
	char *retour;

	split = ft_split(envp[k], '=');
	retour = ft_strdup(split[1]);
	ft_free_tab_simple(split);
	return(retour);
}

char *ft_tmp_cmp(char **envp, char *tmp_bis, int k)
{
	char **split;
	char *retour;
	(void) tmp_bis;

	split = ft_split(envp[k], '=');
	retour = ft_strdup(split[0]);
	ft_free_tab_simple(split);
	return(retour);
}

char *ft_change_value(char *str, char **envp, int start, int len)
{
	char *tmp_bis;
	int k;
	char *tmp_cmp;

//	printf("ici 1B\n");
	tmp_bis = ft_substr(str, start, len);
	k = 0;
//	printf("tmp_bis = %s\n", tmp_bis);
	while (envp[k])
	{
		tmp_cmp = ft_tmp_cmp(envp, tmp_bis, k);
		printf ("tmp_cmp = %s\n", tmp_cmp);
		if (ft_strcmp(tmp_bis, tmp_cmp) != 0)
		{
			free (tmp_cmp);
			k++;
		}
		else
		{
			free (tmp_cmp);
			tmp_cmp = ft_tmp(envp, tmp_bis, k);
			free (tmp_bis);
			return(tmp_cmp);
		}

	}
	free (tmp_bis);
	return NULL;
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
//	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//	if (!dst)
//		return (NULL);
	if (!s1)
	{
		dst = ft_strdup(s2);
		return (dst);
	}
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	free(s1);
	return (dst);
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
	tmp = NULL;
//	tmp[0] = '\0';
	while (str[i])
	{
		if ((str[i] != '$' && str[i] != '?') || (str[i] == '$' && code_caractere[i] == 8) || (str[i] == '?' && str[i - 1] != '$') || (str[i] == '$' && !str[i + 1]))
			tmp = ft_strjoin_modif(tmp, str[i]);
		else if (str[i] == '$' && code_caractere[i] != 8 && str[i + 1] == '?')
			tmp = ft_strjoin(tmp, ft_itoa(ft_static(5)));
		else if(str[i] == '$' && code_caractere[i] != 8 && str[i + 1] != '?')
		{
			printf("ici 1\n");
			i++;
			start = i;
			while (ft_isalnum(str[i]) == 1 || str[i] == '|')
				ft_increase(&i, &len);
			printf("ici 2\n");
			i--;
			change = ft_change_value(str, envp, start, len);
			if (change != NULL){
				printf("ici 3\n");
				tmp = ft_strjoin_free(tmp, change);
				free(change);
			}
			else if (ft_change_value(str, g_nos_variables, start, len) != NULL){
				printf("ici 4\n");
				tmp = ft_strjoin(tmp, ft_change_value(str, g_nos_variables, start, len));
			}
		}
		i++;
	}
	printf("ici 5\n");
	free (str);
	str = ft_strdup(tmp);
	printf("ici 6\n");
	free(tmp);
	return (str);
}