#include "DeliveredPizza.h"

DeliveredPizza::DeliveredPizza(string size, string style, vector<string> toppings, string address):Pizza(size, style, toppings)
{
	this->address = address;
	this->deliveryFee = 3.5;
	if(price <20)
	this->deliveryFee = 5;
}
