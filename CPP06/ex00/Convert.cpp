#include "Convert.hpp"

Convert::Convert(){
}

Convert::Convert(const Convert &copy){
	*this = copy;
}

Convert &Convert::operator=(const Convert &assign){
	static_cast<void>(assign);
	return *this;
}

Convert::~Convert(){
}

void Convert::checkInput(const char *argv){
	char c = ' ';
	int i = 0;
	float f = 0.0f;
	long double d = 0.0;
	argv_str = static_cast<std::string>(argv);
	int n = 0;
	int option = -1;
	try{
		if (strcmp(argv, "nan") == 0 || strcmp(argv, "nanf") == 0)
			option = 0;
		else if (strcmp(argv, "+inf") == 0 || strcmp(argv, "+inff") == 0)
			option = 1;
		else if (strcmp(argv, "-inf") == 0 || strcmp(argv, "-inff") == 0)
			option = 2;
		else if (checkChar(argv))
			option = 3;
		else if (checkStr(argv))
			option = 0;
		else{
			if (argv[n] == '-' || argv[n] == '+')
				n++;
			while (isdigit(argv[n])){
				n++;
				if (!checkDouble(argv) && !checkFloat(argv)){
					if (checkInt(argv)){
						option = 4;
						break ;
					}
				}
				if (argv[n] == '.'){
					n++;
					while (isdigit(argv[n]))
						n++;
					if (argv[n] == 'f'){
						option = 5;
						break ;
					}
					else {
						option = 6;
						break ;
					}
				}
			}
		}
		switch (option)
		{
		case 0:
			non();
			break;
		case 1:
			plus();
			break;
		case 2:
			minus();
			break;
		case 3:
			c = argv_str[0];
			if (c >= 33 && c <= 126)
				std::cout << "char: '" << c << "'" << std::endl;
			else if ((c >= 0 && c <= 32) || c >= 127 || c < 0)
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
			break;
		case 4:
			i = atoi(argv);
			if (i >= 33 && i <= 126)
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else if ((i >= 0 && i <= 32) || i >= 127 || i < 0)
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
			break;
		case 5:
			f = atof(argv);
			if (f >= 33 && f <= 126)
				std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
			else if ((f >= 0 && f <= 32) || f >= 127 || f < 0)
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(f) << std::endl;
			std::cout << "float: " << f << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
			break;
		case 6:
			d = atol(argv);
			if (d >= 33 && d <= 126)
				std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
			else if ((d >= 0 && d <= 32) || d >= 127 || d < 0)
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(d) << std::endl;
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			break;
		default:
			std::cout << "Wrong Input!" << std::endl;
			break;
		}
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

bool Convert::checkChar(const char *argv){
	if (argv_str.length() == 1)
		if (isalpha(argv[0]))
			return true;
	return false;
}

bool Convert::checkStr(const char *argv){
	int i = 0;
	while (argv[i] != '\0'){
		i++;
		if (isalpha(argv[i]))
			return true;
	}
	return false;
}

bool Convert::checkInt(const char *argv){
	long n = std::strtol(argv, nullptr, 10);
	if (((n == INT_MIN || n == INT_MAX) && errno == ERANGE) || (n < INT_MIN || n > INT_MAX))
		throw Convert::NOT();
	if (argv_str == "0")
		return true;
	int i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (isdigit(argv[i])){
		i++;
		if (argv[i] == '\0')
			return true;
	}
	return false;
}

bool Convert::checkFloat(const char *argv){
	long n = std::strtol(argv, nullptr, 10);
	if (((n == FLT_MIN || n == FLT_MAX) && errno == ERANGE) || (n < FLT_MIN || n > FLT_MAX))
		throw Convert::NOT();
	int i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (isdigit(argv[i])){
		i++;
		if (argv[i] == '.'){
			i++;
			while (isdigit(argv[i])){
				i++;
				if (argv[i] == 'f'){
					i++;
					if (argv[i] == '\0')
						return true;
				}
			}
		}
	}
	return false;
}

bool Convert::checkDouble(const char *argv){
	long n = std::strtol(argv, nullptr, 10);
	if (((n == DBL_MIN || n == DBL_MAX) && errno == ERANGE) || (n < DBL_MIN || n > DBL_MAX))
		throw Convert::NOT();
	int i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (isdigit(argv[i])){
		i++;
		if (argv[i] == '.'){
			i++;
			while (isdigit(argv[i])){
				i++;
				if (argv[i] == '\0')
					return true;
			}
		}
	}
	return false;
}

void Convert::minus(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inf" << std::endl;
	std::cout << "double: -inff" << std::endl;
}

void Convert::plus(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inf" << std::endl;
	std::cout << "double: +inff" << std::endl;
}

void Convert::non(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
