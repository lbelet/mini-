#include "minishell.h"

char *ft_set_magic_word(char **cmd, int *j, int i)
{
	int start;
	int len;
	char *tmp;
	char *infile;

	if (cmd[i][*j + 1] != '<' && cmd[i][*j + 1])
	{
		*j = *j + 1;
		start = *j;
		len = 0;
		while (cmd[i][*j] != '<' && cmd[i][*j] != '>' && cmd[i][*j])
		{	
			len++;
			*j = *j + 1;
		}
		tmp = ft_substr(cmd[i], start, len);
		infile = ft_strdup(tmp);
		free(tmp);
		return (infile);
	}
	if (cmd[i][*j + 1] != '<' && !cmd[i][*j + 1])
	{
		
	}
	return (NULL);
}

void ft_infile_tmp(char **cmd, int *fd, int i, int *j)
{
	int fd_tmp;
	char *magic_word;
	char *str_tmp;
	char *str_final;
	char *infile;

	infile = ".tmp_file";
	str_final = NULL;
	magic_word = ft_set_magic_word(cmd, j, i);
//	printf("magic: %s\n", magic_word);
	fd_tmp = open(infile, O_RDWR | O_TRUNC | O_CREAT, 0666);
	while(1)
	{
		str_tmp = readline("> ");
		if (ft_strcmp(str_tmp, magic_word) != 0)
		{
		//	char *tmp;
			str_final = ft_strjoin_free(str_final, str_tmp);
			str_final = ft_strjoin_free(str_final, "\n");
//			free(tmp);
//			printf("str_tmp: %s\n", str_tmp);
//			printf("str_final:\n%s", str_final);
		}
		else if (ft_strncmp(str_tmp, magic_word, ft_strlen(magic_word)) == 0)
		{
			fd_tmp = open(infile, O_RDWR | O_TRUNC | O_CREAT, 0666);
			write(fd_tmp, str_final, ft_strlen(str_final));
			close (fd_tmp);
			break;
		}
		free (str_tmp);
	}
	free(str_tmp);
	if (fd[0] != 0)
		close(fd[0]);
	fd[0] = open(infile, O_RDONLY);
	*j += (ft_strlen(magic_word) + 1);
	free(magic_word);
	free(str_final);
}