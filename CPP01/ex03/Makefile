CPP = c++
SRC = humana.cpp humanb.cpp weapon.cpp main.cpp
NAME = killbob
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): *.cpp
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)