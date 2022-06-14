CPP = c++
SRC = main.cpp
HEAD = MutantStack.hpp
NAME = mutant
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)