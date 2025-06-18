CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = moar_brainz

SRC = zombieHorde.cpp Zombie.cpp main.cpp

RM = rm -f

all: $(NAME) target

$(NAME): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

target:
	$(info $(NAME))

.PHONY:
	all fclean re target
