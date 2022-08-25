#include <iostream>
#include <string>


int main(){
	std::string nome1, nome2;

	std::cin >> nome1;
	std::cin >> nome2;
	
	if (nome1 < nome2)
	{
		std::cout << nome1 << std::endl;
		std::cout << nome2;
	}
	else
	{
		std::cout << nome2 << std::endl;
		std::cout << nome1;
	}
}
