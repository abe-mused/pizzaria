#ifndef DELIVEREDPIZZA_H
#define DELIVEREDPIZZA_H

#include "Pizza.h"

class DeliveredPizza : public Pizza
{
	friend ostream& operator<<(ostream&, const DeliveredPizza);
	private:
		string address;
		float deliveryFee, totalPrice;
	public:
		DeliveredPizza(string, string, vector<string>, string);
	protected:
};

#endif
