CPP = c++
SRC = Amateria.cpp Character.cpp Cure.cpp Ice.cpp Materiasource.cpp main.cpp
HEAD = Amateria.hpp Character.hpp Cure.hpp Ice.hpp Icharacter.hpp Imateriasource.hpp Materiasource.hpp
NAME = materia
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)