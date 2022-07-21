#include "minishell.h"

int ft_static(int i)
{
    static int return_val = 0;

    if (i != 5)
        return_val = i;
    
    return (return_val);
}

void ft_exec_cmd(char *str, char **envp)
{
	int *code_caractere;
	char **split_pipe;
	int nbr_cmd;

	nbr_cmd = 0;
    code_caractere = ft_code_char(str);
    printf("Avant: %s\n", str);
    str = ft_check_dollars(str, envp, code_caractere);
    printf("Apres: %s\n", str);
    free(code_caractere);
	code_caractere = ft_code_char(str);
    split_pipe = ft_split_modif(str, '|', code_caractere);
    while (split_pipe[nbr_cmd])
    	nbr_cmd++;
    if (nbr_cmd == 1)
        ft_one(split_pipe, envp);         
    if (nbr_cmd >= 2)
        ft_pipex_multi(split_pipe, nbr_cmd, envp);
	ft_free_tab_simple(split_pipe);
    free(str);
    free(code_caractere);
}
/*
int	ft_init(struct termios *sig)
{
	init_signals(sig);
	return (0);
}*/

int main(int argc, char **argv, char **envp)
{
    (void)argv;
    char *str;
    char **envp_copy;
//    struct termios sig;
    

    envp_copy = ft_malloc_tab(envp);
    ft_cpy_tab(envp, envp_copy);
    handle_global_signals();
    if (argc == 1)
    {
        while (42)
        {
            str = readline("prompt> ");
            if (str == NULL)//CTRL+D
                break;
            add_history(str);
		    ft_exec_cmd(str, envp_copy);
		    //free(str);      
        }
//   		tcsetattr(STDIN_FILENO, TCSANOW, &sig);
    }
    else
        printf("ERROR! IN YOUR FACE!!!\n");
    ft_free_tab_simple(envp_copy);
    return (0);
}