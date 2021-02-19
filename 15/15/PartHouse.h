#pragma once
#include <string>
#include <iostream>

#define interface class

interface PartHouse
{
public:
    virtual std::string getName() const = 0;
    virtual ~PartHouse() {}
};

class Floor : public PartHouse
{
private:
    std::string name;
public:
    Floor() :
        name("Floor") {}

    virtual std::string getName() const
    {
        return name;
    }
};

class Wall : public PartHouse
{
private:
    std::string name;
public:
    Wall() :
        name("Wall") {}

    virtual std::string getName() const
    {
        return name;
    }
};

class Roof : public PartHouse
{
private:
    std::string name;
public:
    Roof() :
        name("Root") {}

    virtual std::string getName() const
    {
        return name;
    }
};