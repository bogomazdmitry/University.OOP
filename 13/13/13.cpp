#include <iostream>
#include <ctime>

#include "List2.h"

int main()
{
    srand((unsigned)time(NULL));
    List2<int> l;
    l.random(5);
    std::cout << l << std::endl;

    for (auto ite = l.get_end(), it = l.get_begin(); it != ite; ++it, --ite)
    {
        std::swap(*it, *ite);
    }
    std::cout << l << std::endl;
    system("pause");
    return 0;
}
