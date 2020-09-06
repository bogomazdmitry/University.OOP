#include "Cart.h"

Cart::Cart() :
	Transport(10, 20)
{
}

std::string Cart::nameOfTransport() const
{
	return "Повозка";
}
