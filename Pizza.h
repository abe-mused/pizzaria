#ifndef PIZZA_H
#define PIZZA_H
#include<string>
#include<vector>

using namespace std;

class Pizza
{
	friend ostream& operator<<(ostream&, const Pizza);
	private:
		void calcPrice();
	public:
		Pizza(string, string, vector<string>);
		string getSize();
		string getStyle();
		vector<string> getToppings();
		float getPrice();
	protected:
		string size, style;
		vector<string> toppings;
		float price;
};

#endif
