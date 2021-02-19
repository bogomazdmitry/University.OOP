#pragma once

#include "House.h"
#include "PartHouse.h"
#include "IHouseBuilder.h"

class HouseDirector
{
private:
	IHouseBuilder* builder;

public:
	HouseDirector() :
		builder(NULL){}

	void setBuilder(IHouseBuilder* builder)
	{
		delete this->builder;
		this->builder = builder;
	}

	~HouseDirector()
	{
		delete builder;
	}

	void BuildAll()
	{
		builder->BuildFloor();
		builder->BuildRoof();
		builder->BuildWall();
	}
};