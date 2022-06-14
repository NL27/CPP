// CPP03

// =====INHERITANCE=====

class Animal{
	private:
		int _lives;

	public:
		Animal();
		Animal(const Animal &copy);
		~Animal();
		Animal &operator=(const Animal &assign);
		void run(int distance);
}

class Cat : public Animal{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &assign);
		void purr(std::string const &target);
}

class Squad{ // Can access name, run() & lives
	private:
		std::string	name; // Only accessible from an Squad object
	protected:
		int		lives[7]; // Accessible from an Squad or derived object
	public:
		void	run(); // Accessible from everywhere

}

class Team : public Squad{ // Can access run() & lives
}

int main(){ // can only access run()
}