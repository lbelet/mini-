#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdbool.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdarg.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <limits.h>
#include <dirent.h>
#include <termios.h>

char **g_nos_variables;

void    display_prompt(int num);
void    define_input_signals(void);
int     ft_echo(char **cmd_test);
void    ft_execute_inbuilt(char **cmd_test, char **envp);
void    ft_process_onlyone(char *path_cmd, char **cmd, char **envp);
//int     ft_process_one_classic(int *pid, char **cmd, char **envp);
int ft_process_one_classic(char **cmd, char **envp);
int     ft_process_one_nosplit(int *pid, char **cmd, char **envp);
int     ft_process_one_split(int *pid, char **cmd, char **envp);
// void    ft_one(char **split_pipe, char **envp, int *code_caractere);
void    ft_one(char **split_pipe, char **envp);
void    ft_process_first(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp);
int     ft_process_middle(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp);
void    ft_process_last(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp);
int     ft_multi(int *pid, int i, int k, char **split_pipe, int nbr_cmd, int **fd, char **envp);
int     ft_giant_pipex(char **split_pipe, int nbr_cmd, char **envp, int * code_caractere);
char    **ft_get_path(void);
char    *ft_path(char *str);
void    ft_process_onlyone(char *path_cmd, char **cmd, char **envp);
void    ft_process_first(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp);
int     ft_process_middle(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp);
void  ft_process_last(int fd_in, int fd_out, char *path_cmd, char **cmd, char **envp);
int ft_multiple_pipes(int i, int j, int *pid, int nbr_cmd, char **split_pipe, char **envp);
int ft_multiple_pipes_bis(int i, int j, int *pid, int nbr_cmd, char **split_pipe, char **envp);
int *ft_quote_place(char *str);
int ft_nbr_quote(char *str);
void  ft_check_quote(char **tab, int n);
char **ft_parsing_quote(char *str);
char **ft_split_modif(char *s, char c, int *code_caractere);
int ft_cmd_error(char *path_cmd, char **cmd_infile, int *pid);
int ft_check_builtins(char **cmd);
void    ft_execute_inbuilt_fd(int fd_out, char **cmd_test, char **envp);
int ft_cd(char **cmd_test, char **envp);
void ft_unset(char **cmd_test, char **args_in);
int ft_env(char **envp, char **args_in);
char  **ft_export(char **cmd_test, char **envp, char **args);
int    ft_pwd(void);
int    ft_echo_fd(int fd_out, char **cmd_test);
int    ft_exit(char *args[]);
void ft_sort_alpha(char **sorted);
int ft_nbr_args(char **cmd_test);
char    **ft_malloc_tab(char **original);
char    **ft_malloc_var(char **original);
void    ft_sort_alpha(char **sorted);
void    ft_printf_all(char **sorted);
void	ft_free_tab_simple(char **tab);
int ft_subopen_code_caractere(char  *str, int i);
void ft_check_redir(int *fd, char **cmd, char **commande);
int ft_pipex_multi(char **split_pipe, int nbr_cmd, char **envp);
void ft_cpy_tab(char **original, char **copy);
int	ft_error(char *path_cmd, char **cmd_infile);
void ft_exec_in(int fd_in, char **commande, char **envp);
void ft_exec_in_out(int *fd, char **commande, char **envp);
void ft_exec_out(int fd_out, char **commande, char **envp);
char	*ft_check_quote_simple(char *tab);
int *ft_code_char(char *str);
char *ft_set_file(char **cmd, int *j, int i);
void ft_error_fd(int fd, char *infile);
void ft_infile_split(char **cmd, int *fd, int *i);
void ft_infile_nosplit(char **cmd, int *fd, int *j, int i);
void ft_outfile_split(char **cmd, int *fd, int *i);
void ft_outfile_nosplit(char **cmd, int *fd, int i, int *j);
void ft_outfile_nosplit_append(char **cmd, int *fd, int i, int *j);
void ft_free_tab_int(int **fd, int *pid, int nbr_cmd);
void ft_first_process(char **split_pipe, int *fd_redir, int **fd_pipe, char **envp);
void ft_middle_process(int k, int i, char **split_pipe, int *fd_redir, int **fd_pipe, char **envp);
void ft_last_process(int k, char **split_pipe, int *fd_redir, int **fd_pipe, char **envp);
void ft_close_middle(int k, int nbr_cmd, int **fd_pipe);
void ft_close_all(int nbr_cmd, int **fd_pipe);
void ft_close_fl(int k, int nbr_cmd, int **fd_pipe);
char *ft_check_dollars(char *str, char **envp, int *code_caractere);
char	*ft_strjoin_modif(char *s1, char const s2);
int ft_static(int i);
void ft_files(char **cmd, int *fd, int *j, int *i);
int ft_write_tmp(int fd_out, char *str);
void ft_infile_tmp(char **cmd, int *fd, int i, int *j);
char *ft_absolute(char **cmd);
void    ft_write_all(int fd_out, char **sorted);
char    **ft_export_fd(int fd_out, char **cmd_test, char **envp, char **args);
int ft_env_fd(int fd_out, char **envp, char **args_in);
int    ft_pwd_fd(int fd_out);
char *ft_error_cmd(char **cmd);
//void init_signals(struct termios *sig);
void	handle_global_signals(void);

#endif