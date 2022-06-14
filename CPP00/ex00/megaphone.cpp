#include <iostream>

int main(int argc, char **argv)
{
	int i = 1;
	int j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		j = 0;
		while (j < (int)strlen(argv[i]))
		{
			std::cout << (char)toupper(argv[i][j]);
			j++;
		}
		i++;
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}

