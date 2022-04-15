NAME	= minitalk

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

libft:
	make -C libft

client: client.c
	cc $(FLAGS) client.c libft/libft.a -o client

server: server.c
	cc $(FLAGS) server.c libft/libft.a -o server

$(NAME): libft client server
	@echo "(ง ͡ʘ ͜ʖ ͡ʘ)ง***compilation successful***( ͡° ͜ʖ ͡°)"

clean:
	@make -C libft clean
	@rm -f client server
	@echo "(ง ͡ʘ ͜ʖ ͡ʘ)ง***Deleting all OBJ_FILES is successful***☜(˚▽˚)☞" 

fclean: clean
	@make -C libft fclean
	@echo "(ง ͡ʘ ͜ʖ ͡ʘ)ง***Deleting is successful***(•ˇ‿ˇ•)-→" 

re: fclean all

.PHONY: libft
