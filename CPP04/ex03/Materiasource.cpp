#include "Materiasource.hpp"

Materiasource::Materiasource(){
}

Materiasource::Materiasource(const Materiasource &copy){
	(void) copy;
}

Materiasource &Materiasource::operator=(const Materiasource &assign){
	(void) assign;
	return *this;
}

Materiasource::~Materiasource(){
}

void Materiasource::learnMateria(Amateria* materia){
	for (int i = 0; i < 4; i++){
		if (!materias[i]){
			materias[i] = materia;
			break ;
		}
	}
}

Amateria* Materiasource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++)
		if (materias[i]->getType() == type)
			return (materias[i]->clone());
	return 0; 
}