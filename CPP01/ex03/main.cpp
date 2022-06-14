#include "humana.hpp"
#include "humanb.hpp"
#include "weapon.hpp"

int main(){
	{
		weapon club = weapon("crude spiked club");
		humana bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		weapon club = weapon("crude spiked club");
		humanb jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	// system("leaks killbob");
	return 0;
}