#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){
	setTarget("Standard");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137){
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form("ShrubberyCreationForm", 145, 137){
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign){
	setTarget(assign.getTarget());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	
	if (executor.getGrade() <= getEgrade())
	{
		if (getsigned() == true)
			makeTree();
		else
			throw Form::FormNotSignedException();
	}
	else
		throw Form::GradeTooLowException();
}

void ShrubberyCreationForm::makeTree() const{
	std::ofstream outFile;

	outFile.open(getTarget() + "_shrubbery", std::ios::trunc);
	if (outFile.is_open()){
		outFile << "               The Worm's Turn					" << std::endl << std::endl;
		outFile << "		          _{\\ _{\\{\\/}/}/}__			" << std::endl;
		outFile << "             {/{/\\}{/{/\\}(\\}{/\\} _			" << std::endl;
		outFile << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _		" << std::endl;
		outFile << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}	" << std::endl;
		outFile << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}		" << std::endl;
		outFile << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}		" << std::endl;
		outFile << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}	" << std::endl;
		outFile << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}	" << std::endl;
		outFile << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}	" << std::endl;
		outFile << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
		outFile << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
		outFile << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
		outFile << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}	" << std::endl;
		outFile << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}	" << std::endl;
		outFile << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)	" << std::endl;
		outFile << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}		" << std::endl;
		outFile << "             {/{\\{\\{\\/}/}{\\{\\\\}/}			" << std::endl;
		outFile << "              {){/ {\\/}{\\/} \\}\\}			" << std::endl;
		outFile << "              (_)  \\.-'.-/						" << std::endl;
		outFile << "          __...--- |'-.-'| --...__				" << std::endl;
		outFile << "   _...--'   .-'   |'-.-'|  ' -.  '--..__		" << std::endl;
		outFile << " -'    ' .  . '    |.'-._| '  . .  '   jro		" << std::endl;
		outFile << " .  '-  '    .--'  | '-.'|    .  '  . '			" << std::endl;
		outFile << "          ' ..     |'-_.-|						" << std::endl;
		outFile << "  .  '  .       _.-|-._ -|-._  .  '  .			" << std::endl;
		outFile << "              .'   |'- .-|   '.					" << std::endl;
		outFile << "  ..-'   ' .  '.   `-._.-�   .'  '  - .			" << std::endl;
		outFile << "   .-' '        '-._______.-'     '  .			" << std::endl;
		outFile << "        .      ~,								" << std::endl;
		outFile << "    .       .   |\\   .    ' '-.				" << std::endl;
		outFile << "    ___________/  \\____________				" << std::endl;
		outFile << "   /  Why is it, when you want \\				" << std::endl;
		outFile << "  |  something, it is so damn   |				" << std::endl;
		outFile << "  |    much work to get it?     |				" << std::endl;
		outFile << "   \\___________________________/				" << std::endl;
		outFile << " Source: https://ascii.co.uk/art/tree 			" << std::endl;
	}
	else
		std::cout << "Unable to open file " << getTarget() + "_shrubbery" << std::endl;
	outFile.close();
}