#include <iostream>
#include <string>
#include "function.h"

using namespace std;

istream& operator >> (istream &in, Dish &d)
{
    string name;
    int lvl;
	in >> name;

    // reset d.food
	if(d.food != nullptr)
	{
	    delete d.food; // 清除原本儲存的東西
		d.food = nullptr;
	}

	if(name == "Ramsay")
	{
		in >> lvl;
		d.food  = new IdiotSandwich(lvl); // 記得用 new
	}
	else
	{
	    d.food = new NormalSandwich(name); // 記得用 new
	}
	return in;
}

//destructor
Dish::~Dish()
{
	delete food;
}

void
IdiotSandwich::print(ostream &out)
{
    out << "An idiot sandwich with intelligence level " << getINT() << " only.";
}


void
NormalSandwich::print(ostream &out)
{
	out << getName() << ". Masterpiece of sandwiches.";
}