CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -I$(HOME)/.brew/Cellar/readline/8.1.2/include #-fsanitize=address -fno-omit-frame-pointer

NAME = minishell

SRC = minishell.c\
		get_path.c\
		split_modif.c\
		signals.c\
		exec_builtins.c\
		one_cmd.c\
		multi_cmds.c\
		errors.c\
		echo.c\
		cd.c\
		unset.c\
		env.c\
		export.c\
		pwd.c\
		exit.c\
		export_utils.c\
		minishell_utils.c\
		free.c\
		malloc.c\
		code_char.c\
		redirections_main.c\
		redir_in.c\
		redir_out.c\
		redir_in_out.c\
		quotes.c\
		first_process.c\
		mid_process.c\
		last_process.c\
		close_fd.c\
		dollar.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
#	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -lreadline -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -lreadline  -L$(HOME)/.brew/Cellar/readline/8.1.2/lib -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) -libft/libft.a -lreadline -L$(HOME)/.brew/opt/readline/lib -I$(HOME)/.brew/opt/readline/include


clean:
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re