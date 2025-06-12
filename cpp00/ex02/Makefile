CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = account

SRC = Account.cpp tests.cpp

RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all fclean re
