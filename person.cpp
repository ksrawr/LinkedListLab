// person.cpp
#include "person.h"


Person::Person()
{
}

Person::Person(string pname, int page)
{
   name = pname;
   age = page;
}

string Person::get_name() const
{
   return name;
}

int Person::get_age() const
{
   return age;
}



