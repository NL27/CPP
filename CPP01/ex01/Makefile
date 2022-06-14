CPP = c++
SRC = zombie.cpp zombiehorde.cpp main.cpp
NAME = smombiehorde
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): *.cpp
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)