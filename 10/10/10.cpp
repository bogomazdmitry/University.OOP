#include <iostream>
#include "String.h"
#include "Node.h"

int main()
{
    Tree<String> t;
    t.add_element("dsadsdf");
    t.add_element("bdvsvsd");
    t.add_element("advsvdscdscd");
    t.add_element("sdvsvdscdscd");
    std::cout << t << std::endl;
    const auto str = "bdvsvsd";
    try
    {
        t.find(str);
        std::cout << str << " is founded!" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << str << " " << e.what() << std::endl;
    }
    return 0;
}