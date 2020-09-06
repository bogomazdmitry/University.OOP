#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "Bicycle.h"
#include "Car.h"
#include "Cart.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector<std::unique_ptr<Transport>> vector_trans;

	vector_trans.emplace_back(std::unique_ptr<Transport>(new Car()));
	vector_trans.emplace_back(std::unique_ptr<Transport>(new Cart()));
	vector_trans.emplace_back(std::unique_ptr<Transport>(new Bicycle()));
	
	std::cout << "Выберите вид транспорта:" << std::endl;
	for (int i = 0; i < vector_trans.size(); ++i)
	{
		std::cout << i + 1 << " - " << vector_trans[i]->nameOfTransport() << std::endl;
	}

	int choise;
	do
	{
		std::cin >> choise;
		if (choise < 0 || choise > vector_trans.size())
		{
			std::cout << "Введите еще раз" << std::endl;
		}
		else
		{
			--choise;
			break;
		}
	} while (true);

	std::cout << "Введите длину пути в километрах: " << std::endl;
	double KM;
	std::cin >> KM;

	std::cout << "Транспорт: " << std::setw(21) << vector_trans[choise]->nameOfTransport() << std::endl;
	std::cout << "Цена: " << std::setw(26) << vector_trans[choise]->costOfTravel(KM) << std::endl;
	std::cout << "Время: " << std::setw(21) << vector_trans[choise]->timeOfTravel(KM) << std::endl;
	system("pause");
	return 0;
}