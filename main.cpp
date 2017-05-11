// main.cpp
#include <iostream>
#include <typeinfo>
#include "LinkedList.hpp"
#include "person.h"
#include <mysql.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include "dbconnect.h"
#include "wine.h"



using namespace std;



int main()
{
   int key;
   List< int > list1; // storage for first list
   List< int > list2; // storage for second list


// assign intger into first list, from 1 to 5 
   /*
    * Use insertAtBack function to add to linked list
    * YOU MUST USE insertAtBack in the wine lab, so YOU NEED TO
    * COMPLETE the insertAtBack methold.
    * */
    
   for (int i=0; i <5;  i++)
   {
	  key = i;  // key is an unique value, like your ID
    list1.insertAtBack( i, key );
 //     list1.insertAtBack( i, key ); //YOU MUST IMPLEMENT THIS FUNCTION
   }
   
    
   
   // call function print to print the list
   list1.print();

   // assign from 5 to 10 into second list
      /*
    * Use insertAtFront function to add to linked list
    * */
   for (int i=5; i<10;   i++ )
   {
	  key = i;  // key is an unique value, like your ID
      list2.insertAtFront( i, key );
   }
   list2.print();



	/*
	 * Following code could be adept for your Wine program to 
	 * place data into the linked list.
	 * 
	 * You must use insertAtBack() function to place wine info 
	 * into the linked list
	 * */
	 
	 /*
   // Person LinkedList IE
   Person p;
   List< Person > personList;
 
   
   p.set_info("Ron", 22);
   personList.insertAtFront( p,0 );
   p.set_info("Sha", 30);
   personList.insertAtFront( p,1 );	
   p.set_info("John", 35);
   personList.insertAtFront( p,2 );	

   printNoteInfo (personList);

   // remove last node from Linked List
   // you need to implement removeFromBack method function
   
   // personList.removeFromBack(p);

   personList.removeFromFront(p);  // remove the first node
   printNoteInfo (personList);  
   */


  // mySQL implementation
  MYSQL *conn;    // the connection
  MYSQL_RES *res; // the results
  MYSQL_ROW row;  // the results row (line by line)
  char* sqlcmd;
  string s;
  ostringstream oss;
  
  // Wine LinkedList
  Wine w;
  List< Wine > wineList;

  struct connection_details mysqlD;
  mysqlD.server = (char *)"localhost";  // where the mysql database is
  mysqlD.user = (char *)"root";   // the root user of mysql 
  mysqlD.password = (char *)"password"; // the password of the root user in mysql
  mysqlD.database = (char *)"wine"; // the databse to pick
 
  // connect to the mysql database
  conn = mysql_connection_setup(mysqlD);
 
  // assign the results return to the MYSQL_RES pointer
  
     // use wine database
     res = mysql_perform_query(conn, (char *)"use wine");
     // get me all the wines with these categories
     res = mysql_perform_query(conn, (char *)"select name, vintage, score, price, type from wineInfo");
     /*
      * you need to print out the header.  Make sure it it 
      * nicely formated line up.  Modify the cout statement
      * below so the header is nicely line up.  Hint: use left and setw
      * 
      * WineName   Vintage  Rating  Price  Type
      * */
     cout << left << setw(30) <<"Wine Name" <<
                        left << setw(15) << "Vintage" <<
             left << setw(15) << "Rating" <<
             left << setw(15) << "Price"  <<
             left << setw(15) << "Type"
   << endl;
  
  //int z = 0;

    row = mysql_fetch_row(res);
    int z;
    while ((row = mysql_fetch_row(res)) !=NULL)
    {
    // convert (wineName) char * to string
    std::string wineName(row[0]);
    /*
    istringstream sWN(row[0]);
    string wineName;
    sWN >> wineName;
    */

    // convert char * to int
    std::stringstream sWY(row[1]);
    int wineYear;
    sWY >> wineYear;
/*
    sstringstream strYear;
    strYear << row[1];
    int wineYear;
    strYear >> wineYear;
*/  
    std::stringstream sWR(row[2]);
    int wineRating;
    sWR >> wineRating;
/*
    sstringstream strRating;
    strRating << row[1];
    int wineRating;
    strRating >> wineRating;
*/
    // convert char * to double
    std::string wineType(row[4]);
    /* 
    istringstream sWR(row[3]);
    string winePrice;
    sWR >> winePrice; s
    */

    // convert (wineType) char * to string
    
    istringstream sWP(row[3]);
    double winePrice;
    sWP >> winePrice;

    /*
    cout << setw(32) << left << wineName << setfill(' ') // coulumn (field) #1 - Wine Name
     << setw(15) << wineYear << setfill(' ') // field #2 - Vintage
     << setw(15) << wineRating << setfill(' ') // field #3 - Rating
    << setw(13) << winePrice << setfill(' ') // field #4 - Price
    << setw(10) << wineType << setfill(' ') // field #5 - Wine type
    << endl;
    */
    w.setInfo(wineName, wineYear, wineRating, winePrice, wineType);
    wineList.insertAtFront(w,z);
    z++;
    }
    // w.setInfo(row[0], row[1], row[2], row[3], row[4]);
    //w.setInfo(wineName, wineYear, wineRating, winePrice, wineType);    
    ///wineList.insertAtFront( w , 0);
    


  printNoteInfo(wineList);

  //  print all those wines outs 
   /*
  while ((row = mysql_fetch_row(res)) !=NULL)
  {
   cout << setw(32) << left << row[0] << setfill(' ') // coulumn (field) #1 - Wine Name
     << setw(15) << row[1] << setfill(' ') // field #2 - Vintage
     << setw(15) << row[2] << setfill(' ') // field #3 - Rating
    << setw(13) << row[3] << setfill(' ') // field #4 - Price
    << setw(10) << row[4] << setfill(' ') // field #5 - Wine type
    << endl; // field #7 - UPC
  }
  */
  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
 
  return 0;




} // end main





