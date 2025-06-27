CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bsp

SRC = bsp.cpp Point.cpp Fixed.cpp

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
