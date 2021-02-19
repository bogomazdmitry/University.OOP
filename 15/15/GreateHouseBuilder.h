#pragma once
#include <iostream>
#include <memory>
#define interface class

#include "House.h"
#include "PartHouse.h"

class GreatHouseBuilder : public IHouseBuilder
{
private:
    House* house;

public:
    GreatHouseBuilder()
    {
        house = new House();
    }

    void Reset()
    {
        delete house;
        house = new House();
    }

    virtual void BuildFloor()
    {
        house->AddPartHouse(new Floor());
    }

    virtual void BuildWall()
    {
        house->AddPartHouse(new Wall());
    }

    virtual void BuildRoof()
    {
        house->AddPartHouse(new Roof());
    }

    const auto& GetHouse() const
    {
        return (*house);
    }

    virtual ~GreatHouseBuilder()
    {
        delete house;
        house = NULL;
    };
};