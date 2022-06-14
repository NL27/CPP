// CPP04

// =====SUB-TYPING POLYMORPHISM=====
#include <string>
#include <iostream>

class Character{
	public:
		// if we put a "virtual" infront of the void function
		// we will get twice the warrior saying f*** off ppl
		// as he does not pretend to be a character then
		virtual void saySmth(std::string const &target);
};

class Warrior : public Character{
	public:
		void saySmth(std::string const &target); 
};

class Cat{
};

void Character::saySmth(std::string const &target){
	std::cout << "Hello " << target << std::endl;
}

void Warrior::saySmth(std::string const &target){
	std::cout << "F*** off " << target << " or you will regret it!"<< std::endl;
}

int main(){
	// This is OK, obvisously, Warrior IS a Warrior
	Warrior *one = new Warrior();
	
	// This is also OK, as Warrior IS a Character
	Character *two = new Warrior();
	
	// This would NOT be OK as Character IS NOT a Warrior
	// Warrior *three = new Character();
	
	// This would also NOT be OK as Cat IS NOT a Character
	// Character *four = new Cat();

	one->saySmth("ppl");
	two->saySmth("ppl");
}

// =====ABSTRACT CLASSES & INTERFACES=====

class ACharacter{ // "A" added to front becasue it is Abstract
	private:
		std::string name;

	public:
		// all the children classes MUST have the attack function
		// the attack function does NOT exist for characters but for warriors
		virtual void attack(std::string const &target) = 0;
		void	saySmth(std::string const &target);
};

class Warrior : public ACharacter{
	public:
		virtual void attack(std::string const &target); 
};

void ACharacter::saySmth(std::string const &target){
	std::cout << "Hello " << target << std::endl;
}

void Warrior::attack(std::string const &target){
	std::cout << "*attacks " << target << " with his bare fists*"<< std::endl;
}

// in the Interface it's NOT possible to have attributes 
class ITeaTime{ // "I" added to the front because of Interface
	public:
		virtual void boilWater(ITeaTime *src) = 0;
		virtual ITeaTime *boilTea(std::string const &type) = 0;
};

int main(){
	ACharacter *one = new Warrior();

	// This would NOT be OK as ACharacter is abstract
	// ACharacter *two = new ACharacter();

	one->saySmth("ppl");
	one->attack("Bill");
}