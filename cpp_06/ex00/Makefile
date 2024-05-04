CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ScalarConverter.cpp 

OBJ = $(SRC:.cpp=.o)

NAME = cpp_6_ex00

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all