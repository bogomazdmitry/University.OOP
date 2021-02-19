#pragma once
#include <iostream>
#include <string>
#include <list>
#include <memory>
#define interface class

#include "PartHouse.h"

class House
{
private:
    std::list<PartHouse*> partsOfHouse;

public:
    void AddPartHouse(PartHouse* partHouse)
    {
        partsOfHouse.push_back(partHouse);
    }

    std::string Result() const
    {
        std::string str;
        for (auto it = partsOfHouse.begin(); it != partsOfHouse.end(); ++it)
        {
            str += (*it)->getName() + " ";
        }
        return str;
    }

    ~House()
    {
        for (auto it = partsOfHouse.begin(); it != partsOfHouse.end(); ++it)
        {
            delete *it;
        }
    }
};