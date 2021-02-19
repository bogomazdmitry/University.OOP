#pragma once
#define interface class

interface IHouseBuilder
{
public:
    virtual void BuildFloor() = 0;
    virtual void BuildWall() = 0;
    virtual void BuildRoof() = 0;
    virtual ~IHouseBuilder() {};
};