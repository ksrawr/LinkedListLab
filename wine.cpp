// wine.cpp
#include "wine.h"

Wine::Wine()
{
}

Wine::Wine(string n, int v, int s, double p, string t)
{
	name = n;
	vintage = v;
	score = s;
	price = p;
	type = t;
}

void Wine::setInfo(string n, int v, int s, double p, string t)
{
	name = n;
	vintage = v;
	score = s;
	price = p;
	type = t;
}

void Wine::setPrice(double p)
{
	price = p;
}

string Wine::getName() const
{
	return name;
}

int Wine::getPrice() const
{
	return price;
}

void Wine::printInfo()
{
	cout << setw(32) << left << name << setfill(' ') // coulumn (field) #1 - Wine Name
     << setw(15) << vintage << setfill(' ') // field #2 - Vintage
     << setw(15) << score << setfill(' ') // field #3 - Rating
    << setw(13) << price << setfill(' ') // field #4 - Price
    << setw(10) << type << setfill(' ') // field #5 - Wine type
    << endl;
}

/*
void printWineinfo(List< Wine > & wineList)
{
	Wine * f;
	f = (Wine *) wineList.getInfo(0);
	f->printInfo();
	
	ListNode< Wine > *currentPtr;
	
	currentPtr = personList.getFirstPtr();
	
	cout << "The Wine list is: \n";
	
	while( currentPtr != 0 )
	{
		f = (Wine *) currentPtr;
		f->printInfo();
		currentPtr = currentPtr->getNextptr();
	}
}
*/