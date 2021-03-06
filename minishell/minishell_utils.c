#include "minishell.h"

void ft_cpy_tab(char **original, char **copy)
{
    int i;

    i = 0;
    while (original[i])
    {
        copy[i] = ft_strdup(original[i]);
        i++;        
    }
}

char	*ft_strjoin_modif(char *s1, char const s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		dst = malloc(2);
		dst[0] = s2;
		dst[1] = '\0';
		return (dst);
	}
	dst = malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = s2;
	dst[i + 1] = '\0';
	free(s1);
	return (dst);
}