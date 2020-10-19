#include "Pizza.h"

Pizza::Pizza(string size, string style, vector<string> toppings){
	this->size = size;
	this->style = style;
	this->toppings = toppings;
	calcPrice();
}

string Pizza::getSize(){
	return this->size;
}
string Pizza::getStyle(){
	return this->style;
}
vector<string> Pizza::getToppings(){
	return this->toppings;
}
float Pizza::getPrice(){
	return this->price;
}

void Pizza::calcPrice(){
	if(size == "small")
	this->price = 10;
	if(size == "medium")
	this->price = 14;
	if(size == "large")
	this->price = 17;
	
	this->price += toppings.size();
}
