// person.h
#include <iostream>
#include <typeinfo>

#ifndef PERSON_H
#define PERSON_H

using namespace std;


class Person
{
public:
   Person();
   Person(string pname, int page);
   void set_name(string n) {name = n;};
   void set_age(int a) {age = a;};
   void set_info(string n, int a) {name = n; age=a;};
   string get_name() const;
   int get_age() const;
   void printInfo() { cout <<"Name: "<<name;
                    cout << "\tAge: "<<age<<endl; };
private:
   string name;
   int age; /* 0 if unknown */
};

#endif