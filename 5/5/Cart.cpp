#include "Cart.h"

Cart::Cart() :
	Transport(10, 20)
{
}

std::string Cart::nameOfTransport()
{
	return "Повозка";
}
