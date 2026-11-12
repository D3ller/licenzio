NAME = licenzio
SRC = main.c command.c utils.c
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRC) licenzio.h
	cc $(CFLAGS) $(SRC) -o $(NAME).x