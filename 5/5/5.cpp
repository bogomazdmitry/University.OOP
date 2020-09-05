#include <iostream>

class Transport
{
private:
    double priceOfPassanger;
    double priceOfPayload;
    int speed;

public:

};

class Autobus : public Transport
{

};

class Bicycle : public Transport
{

};

class Cart : public Transport
{

};

int main()
{
    std::cout.unsetf(std::ios::dec);
    std::cout.setf(std::ios::binary);
    std::cout << 5151151;
}

