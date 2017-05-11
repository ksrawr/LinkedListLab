// wine.h
#include <iostream>
#include <typeinfo>
#include <iomanip>


#ifndef WINE_H
#define WINE_H


using namespace std;


class Wine
{
	public:
		Wine();
		Wine(string n, int v, int s, double p, string t);
		void setInfo(string n, int v, int s, double p, string t);
		void setPrice(double p);
		string getName() const;
		int getPrice() const;
		void printInfo();
		//void printWineinfo(List< Wine > & wineList);

	
	private:
		string name;
		int vintage;
		int score;
		double price;
		string type;
};

#endif
