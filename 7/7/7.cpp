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
	std::vector<std::unique_ptr<RentalTransport>> vector_trans;

	vector_trans.emplace_back(std::unique_ptr<RentalTransport>(new Car()));
	vector_trans.emplace_back(std::unique_ptr<RentalTransport>(new Cart()));
	vector_trans.emplace_back(std::unique_ptr<RentalTransport>(new Bicycle()));

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
	vector_trans[choise]->show(KM);

	system("pause");
	return 0;
}