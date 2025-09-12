#include <iomanip>
#include <iostream>

int	main(void)
{
	std::string texto;

	texto = "1234567890123";
	std::cout << "Prueba con setw y righ" << std::endl;
	std::cout << std::setw(10) << texto << "|";
	if (texto.length() > 10)
		texto = texto.substr(0, 9) + ".";
	std::cout << std::setw(10) << texto << std::endl;
	std::cout << std::setw(10) << "123" << std::endl;
	std::cout << std::setw(10) << std::right << "123" << std::endl;
	return (0);
}