#include <iostream>
#include <list>
#include <memory>
#define interface class

#include "HouseDirector.h"
#include "PartHouse.h"
#include "GreateHouseBuilder.h"

int main()
{
    HouseDirector hd;
    GreatHouseBuilder* ghb = new GreatHouseBuilder();
    hd.setBuilder(ghb);
    hd.BuildAll();
    std::cout << ghb->GetHouse().Result() << std::endl;
    std::cout << ghb->GetHouse().Result() << std::endl;
    system("pause");
    return 0;
}
