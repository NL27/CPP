CPP = c++
SRC = Span.cpp main.cpp
HEAD = Span.hpp
NAME = span
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)