#include <iostream>

int main()
{
    int kzv;
    kzv=10;
	for (int i = 0; i < kzv; i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
	for (int i = 0; i < kzv - 2; i++)
	{
		std::cout << '*';
		for (int j = 0; j < kzv - 2; j++)
		{
			std::cout << ' ';
		}
		std::cout << '*' << std::endl;
	}
	for (int i = 0; i < kzv; i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
}