CPP = c++
SRC = animal.cpp cat.cpp dog.cpp brain.cpp main.cpp
NAME = abstract
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): *.cpp
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)