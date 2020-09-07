#include "Cart.h"

Cart::Cart() :
	RentalTransport(10, 20)
{
}

std::string Cart::nameOfTransport() const
{
	return "Повозка";
}
