//abe mused
#include <iostream>
#include <iomanip>
#include "Pizza.h"
#include "DeliveredPizza.h"
using namespace std;

/* this is a program that interacts with customers and takes their orders for a pizzeria*/
ostream& operator<<(ostream& , const Pizza);
ostream& operator<<(ostream& , const DeliveredPizza);
void askForData(int &, int &, vector<string> &);
void validateInt(int , int , int &);
bool searchToppings(vector<string> , string );

int main(int argc, char** argv) {
	cout<<setprecision(2)<<fixed;
	string sizeArray [] = {"small", "medium", "large"};
	string styleArray [] = {"classic", "deep dish", "thin crust"};
	int size, type, deliveryChoice;
	vector<string> toppings;
	
	askForData(size, type, toppings);
	cout<<"Would you like 1 - pick up or 2 - delivery? "<<endl;
	cin>>deliveryChoice;
	validateInt(1, 2, deliveryChoice);
	
	Pizza pizza(sizeArray [size-1], styleArray [type-1], toppings);
	
	switch(deliveryChoice){
		case 1:
			cout<<pizza;
			break;
		case 2:
			string address;
			cout<<"enter your address: "<<endl;
			getchar();
			getline(cin, address);
			DeliveredPizza pizza(sizeArray [size-1], styleArray [type-1], toppings, address);
			cout<<pizza;
			break;
	}
	return 0;
}

ostream& operator<<(ostream& o, const Pizza pizza){
	cout<<"you ordered a "<<pizza.size<<" "<<pizza.style<<" pizza with ";
	for(string topping : pizza.toppings){
		cout<<topping<<" ";
	}
	cout<<endl<<"price: "<<pizza.price<<endl;
	return o;
}
ostream& operator<<(ostream& o, const DeliveredPizza pizza){
	cout<<"you ordered a "<<pizza.size<<" "<<pizza.style<<" pizza ";
	( pizza.toppings.size()>0 )? cout<<"with ": cout<<"";
	for(string topping : pizza.toppings){
		cout<<topping<<" ";
	}
	cout<<endl<<"pizza price: "<<pizza.price<<endl;
	cout<<"delivery fee: "<<pizza.deliveryFee<<endl;
	cout<<"total price: "<<pizza.price + pizza.deliveryFee<<endl<<endl;
	cout<<"delivered to: "<<pizza.address<<endl;
	return o;
}

void askForData(int &size, int &type, vector<string> &toppings){
	string toppingsArray [] = {"Pepperoni", "Mushrooms", "Onions", " Green Peppers ", "Tomatoes", "Jalapenos"};
	int choice = 0;
	cout<<"What size pizza would you like to order?"<<endl;
	cout<<"\t1 - small"<<endl<<"\t2 - Medium"<<endl<<"\t3 - Large"<<endl;
	cin>>size;
	validateInt(1, 3, size);
	
	cout<<"What type of crust would you like to order?"<<endl;
	cout<<"\t1 - classic"<<endl<<"\t2 - deep dish"<<endl<<"\t3 - thin crust"<<endl;
	cin>>type;
	validateInt(1, 3, type);
	
	do{
		cout<<"enter the number of topping you would like to add to your pizza, enter 0 when you're done: "<<endl;
		for(int toppingIndex = 0; toppingIndex < 6; toppingIndex++){
			cout<<"\t"<<toppingIndex+1<<") "<<toppingsArray[toppingIndex]<<endl;
		}
		cin>>choice;
		validateInt(0, 6, choice);
		if(choice != 0 && searchToppings(toppings, toppingsArray[choice-1]))
		toppings.push_back(toppingsArray[choice-1]);
	}while (choice != 0);
}

void validateInt(int lowerLimit, int upperLimit, int &input){
	while (input < lowerLimit || upperLimit < input){
		cout<<"error, please enter a number between "<<lowerLimit<<" and "<<upperLimit<<endl;
		cin>>input;
	}
	system("cls");
}
bool searchToppings(vector<string> toppings, string selectedTopping){
	for(string topping: toppings)
	if(selectedTopping == topping)
	return false;
	return true;
}
