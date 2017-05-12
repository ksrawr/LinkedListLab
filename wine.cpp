// wine.cpp
#include "wine.h"
/**

   Purpose:

       Constructor. 

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param - none

   @return - none

*/
Wine::Wine()
{
}
/**

   Purpose:

       Assign the information on Wine class

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param n - wineName

   @param v - wineVintage

   @param s - wineScore

   @param p - winePrice

   @param t - wineType

   @return - none

*/
Wine::Wine(string n, int v, int s, double p, string t)
{
	name = n;
	vintage = v;
	score = s;
	price = p;
	type = t;
}
/**

   Purpose:

       Assign the information on Wine class

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param n - wineName

   @param v - wineVintage

   @param s - wineScore

   @param p - winePrice

   @param t - wineType

   @return - none

*/
void Wine::setInfo(string n, int v, int s, double p, string t)
{
	name = n;
	vintage = v;
	score = s;
	price = p;
	type = t;
}
/**

   Purpose:

       Set Wine Price

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param p - winePrice

   @return - none

*/
void Wine::setPrice(double p)
{
	price = p;
}
/**

   Purpose:

       Retrieve and return wine Name

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param n - wineName

   @return - name

*/
string Wine::getName() const
{
	return name;
}
/**

   Purpose:

       Return and retrieve wine Price

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param p - winePrice

   @return - price

*/
int Wine::getPrice() const
{
	return price;
}
/**

   Purpose:

       Print out the Wines in our class list.

   @author Kenneth Surban

   @version 1.0 5/11/2017

 

   @param - none

   @return - none

*/
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