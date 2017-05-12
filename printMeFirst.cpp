// printMeFirst.cpp
#include "printMeFirst.h"

/**

   Purpose:

       Print out the programmer’s information such as name, class information

       and date/time the program is run

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param name -  the name of the programmer

   @param courseInfo -  the name of the course

   @return - none

*/

void printMeFirst(string name, string courseInfo)

{

cout <<" Program written by: "<< name << endl; // put your name here

cout <<" Course info: "<< courseInfo << endl;

time_t now = time(0);  // current date/time based on current system

char* dt = ctime(&now); // convert now to string for

   cout << " Date: " << dt << endl;

}
