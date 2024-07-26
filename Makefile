CC = gcc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "compilation en cours"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

exec:
	@./linked_list 1 2 3

leaks:
	@echo "check des leaks"
	@leaks --atExit --quiet --list -- ./linked_list 1 2 3

clean:
	@echo "suppression des fichiers objets"
	@rm -rf $(OBJ)

fclean:
	@echo "suppression des fichiers objets et exec"
	@rm -rf $(NAME)
	@rm -rf $(OBJ)

re: fclean all

.PHONY: all clean fclean re
