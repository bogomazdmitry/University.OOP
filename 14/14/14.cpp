#include <iostream>
#include <list>
#include <string>

class Auto
{
private:
    std::string name;
    unsigned speed;
public:
    Auto(std::string name, unsigned speed) :
        name(name),
        speed(speed) {}

    std::string getName() const
    {
        return name;
    }

    unsigned getSpeed() const
    {
        return speed;
    }
};

std::ostream& operator<<(std::ostream& o, const Auto& avto)
{
    o << "Name :\t" << avto.getName() << "\tSpeed :\t" << avto.getSpeed();
    return o;
}

int main()
{
    std::list<Auto> LA;
    LA.push_back({"Mers" , 150});
    LA.push_back({"Audi" , 100});
    LA.push_back({"Volga", 80 });
    LA.push_back({"Tesla", 200});
    for (auto it = LA.cbegin(); it != LA.cend(); it++)
    {
        std::cout << *it << std::endl;
    }
    system("pause");
    return 0;
}

