// CPP01

// ===== NEW & DELETE =====
#include <iostream>
#include <string>
class student{
private:
		std::string _login;
public:
		student(std::string login) : _login(login){
			std::cout << "student " << this->_login << " is born" << std::endl;
		}
		~student(){
			std::cout << "student " << this->_login << " died" << std::endl;
		}
};
int main()
{
	student bob = student("fuu");
	student* jim = new student("bar");
	delete jim;
	return 0;
}

class student{
private:
		std::string _login;
public:
		student() : _login("ldefault"){
			std::cout << "student " << this->_login << " is born" << std::endl;
		}
		~student(){
			std::cout << "student " << this->_login << " died" << std::endl;
		}
};
int main()
{
	student* students = new student[4];
	delete [] students;
	return 0;
}

// ===== REFERENCES =====
// use a reference if something should always exist and never change 
// use a pointer if something should at some point exist or change

int main()
{
	int nbrofBalls = 42;

	int *ballsPtr = &nbrofBalls; //Ptr and assign adress of nbrofBalls to it
	int &ballsRef = nbrofBalls; // reference and assign nbrofBalls to it therefore reference will point on the nbrofBalls variable 
								// reference cannot be changed again as it always points to the same item like a const pointer
	//int &ballsRef2; // doesn't work as it cannot point on nothing. It always has to point on something cannot be uninitialized

	std::cout << nbrofBalls << " " << *ballsPtr << " " << ballsRef << std::endl; // ballsRef is like an alias and a 

	*ballsPtr = 21;
	std::cout << nbrofBalls << std::endl;
	ballsRef = 27;
	std::cout << nbrofBalls << std::endl;
	return 0;
}

void byPtr(std::string *str){
	*str += " and dolphins";
}

void byConstPtr(std::string const *str){
	std::cout << *str << std::endl;
}

void byRef(std::string &str){
	str += " and dolphins";
}

void byConstRef(std::string const &str){
	std::cout << str << std::endl;
}

int main(){
	std::string str = "I like wolves"; 
	std::cout << str << std::endl; // prints out "I like wolves"
	byPtr(&str);				   // adds " and dolphines"
	byConstPtr(&str);			   // prints out everything

	str = "I like tigers";
	std::cout << str << std::endl; // prints out "I like tigers"
	byRef(str);					   // adds " and dolphines"
	byConstRef(str);			   // prints out everything
	return 0;
}

#include <iostream>
#include <string>

class student{
private:
		std::string _login;
public:
		student(std::string const &login) : _login(login){
		}
		std::string &getLoginRef(){
			return this->_login;
		}
		std::string const &getLoginRefConst() const{
			return this->_login;
		}
		std::string *getLoginPtr(){
			return &(this->_login);
		}
		std::string const *getLoginPtrConst() const{
			return &(this->_login);
		}
};

int main(){
	student bob = student("fuu");
	student const jim = student("bar");
	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "bobfuu";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobbar";
	std::cout << bob.getLoginRefConst() << std::endl;

	jim.getLoginRefConst() = "lol";
	std::cout << jim.getLoginRefConst() << std::endl;
}

// ===== FILESTREAMS =====
#include <iostream>
#include <fstream>

int main(){
	std::ifstream ifs("numbers");
	unsigned int dst = 4;
	unsigned int dst2 = 2;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	std::ofstream ofs("test.out");
	ofs << "I like wolves" << std::endl;
	ofs.close();
}