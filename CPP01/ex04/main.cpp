#include <iostream>
#include <fstream>

std::string ft_replace(std::string readLine, std::string search, std::string replace, bool &replaced){
	
	size_t i = 0;
	
	while (readLine[i] != '\0'){
		i = readLine.find(search, i);
		if (i == std::string::npos)
			break;
		readLine.erase(i, search.length());
		readLine.insert(i, replace);
		replaced = true;
		i++;
	}
	return readLine;
}

int main (int argc, char **argv){
	
	std::string readLine;
	std::ifstream readFile;
	std::ofstream writeFile;
	bool	replaced = false;
	
	if (argc != 4){
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return -1;
	}
	std::string const filename = argv[1];
	readFile.open(argv[1]);
	if (readFile.is_open()){
		writeFile.open(filename + ".replace", std::ios::trunc);
		if (writeFile.is_open()){
			while(getline(readFile, readLine)){
				readLine = ft_replace(readLine, argv[2], argv[3], replaced);
				writeFile << readLine;
				if (readFile.peek() != EOF)
					writeFile << std::endl;
			}
			writeFile << std::endl;
			if (replaced == false)
				std::cout << "No occurance of " << argv[2] << " in the file." << std::endl;
		} else
			std::cout << "Unable to open file: " << filename + ".replace" << std::endl;
	} else
		std::cout << "Unable to open file: " << argv[1] << std::endl;

	readFile.close();
	writeFile.close();
	return 0;
}