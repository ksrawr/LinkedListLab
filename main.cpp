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
  /*
   int key;
   List< int > list1; // storage for first list
   List< int > list2; // storage for second list
  */

// assign intger into first list, from 1 to 5 
   /*
    * Use insertAtBack function to add to linked list
    * YOU MUST USE insertAtBack in the wine lab, so YOU NEED TO
    * COMPLETE the insertAtBack methold.
    * */
/*    
   for (int i=0; i <5;  i++)
   {
	  key = i;  // key is an unique value, like your ID
    list1.insertAtBack( i, key );
 //     list1.insertAtBack( i, key ); //YOU MUST IMPLEMENT THIS FUNCTION
   }
   
    
   
   // call function print to print the list
   list1.print();
*/
   // assign from 5 to 10 into second list
      /*
    * Use insertAtFront function to add to linked list
    * */
/*    
   for (int i=5; i<10;   i++ )
   {
	  key = i;  // key is an unique value, like your ID
      list2.insertAtFront( i, key );
   }
   list2.print();
*/

  // mySQL implementation
  MYSQL *conn;    // the connection
  MYSQL_RES *res; // the results
  MYSQL_ROW row;  // the results row (line by line)
  
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
    // should implement as a function in Wine

    // console program
  int choice;
  int choiceOfOne;
  bool displayMenu = true;

  //option select mySQL
  double x;
  char* sqlcmd;
  string s;
  ostringstream oss;

  // menu selector
  while (displayMenu != false ) { 
    cout << "\n Welcome to the 2010 Wine Finder \n";
    cout << " 1 - Find Wines by Score and Price \n";
    cout << " 2 - Find Wines by Price \n";
    cout << " 3 - Find Wines by Vintage \n";
    cout << " 4 - Exit \n ";
    cout << "Please enter your desired selection: ";
    cin >> choice; 


    switch (choice)
    {
      case 1:
      { 
        cout << "Selecting from the following \n";
        cout << " 1 - Display All Wines by Score and Price \n";
        cout << " 2 - Display All Wines by Score and Price, except the Last one \n";
        cin >> choiceOfOne;
        switch (choiceOfOne)
        {
          case 1:
          {   
            cout << left << setw(30) <<"Wine Name" <<
                            left << setw(15) << "Vintage" <<
                 left << setw(15) << "Rating" <<
                 left << setw(15) << "Price"  <<
                 left << setw(15) << "Type"
            << endl;

            row = mysql_fetch_row(res);
            int z = 0;
            while ((row = mysql_fetch_row(res)) !=NULL)
            {
            // convert (wineName) char * to string
            std::string wineName(row[0]);

            // convert char * to int
            std::string sWY(row[1]);
            stringstream streamYear;
            int wineYear;
            streamYear.str(sWY);
            streamYear >> wineYear;

            std::string sWR(row[2]);
            stringstream streamRating;
            int wineRating;
            streamRating.str(sWR);
            streamRating >> wineRating;

            // convert char * to double
            std::string wineType(row[4]);

            // convert (wineType) char * to string 
            istringstream sWP(row[3]);
            double winePrice;
            sWP >> winePrice;

            w.setInfo(wineName, wineYear, wineRating, winePrice, wineType);
            wineList.insertAtBack(w,z);
            z++;
            }
            
            printNoteInfo(wineList);
            break;
          }
          case 2:
          {
            cout << left << setw(30) <<"Wine Name" <<
                            left << setw(15) << "Vintage" <<
                 left << setw(15) << "Rating" <<
                 left << setw(15) << "Price"  <<
                 left << setw(15) << "Type"
            << endl;

            row = mysql_fetch_row(res);
            int z = 0;
            while ((row = mysql_fetch_row(res)) !=NULL)
            {
            // convert (wineName) char * to string
            std::string wineName(row[0]);

            // convert char * to int
            std::string sWY(row[1]);
            stringstream streamYear;
            int wineYear;
            streamYear.str(sWY);
            streamYear >> wineYear;

            std::string sWR(row[2]);
            stringstream streamRating;
            int wineRating;
            streamRating.str(sWR);
            streamRating >> wineRating;

            // convert char * to double
            std::string wineType(row[4]);

            // convert (wineType) char * to string 
            istringstream sWP(row[3]);
            double winePrice;
            sWP >> winePrice;

            w.setInfo(wineName, wineYear, wineRating, winePrice, wineType);
            wineList.insertAtBack(w,z);
            z++;
            }
            
            for(int i = 0; i < 1; i++) 
            {
              wineList.removeFromBack(w);
            }

            printNoteInfo(wineList);
            break;
          }
        }
        break;
      }
      case 2:
      {
        cout << "Enter Price\n";
        cin >> x;
        oss << "select name, type from wineInfo where price >" << x;
        s = oss.str(); 
        sqlcmd = (char *)s.c_str();
        res = mysql_perform_query(conn,sqlcmd);

            while ((row = mysql_fetch_row(res)) !=NULL)
            {
            // convert (wineName) char * to string
            std::string wineName(row[0]);

            // convert char * to int
            std::string sWY(row[1]);
            stringstream streamYear;
            int wineYear;
            streamYear.str(sWY);
            streamYear >> wineYear;

            std::string sWR(row[2]);
            stringstream streamRating;
            int wineRating;
            streamRating.str(sWR);
            streamRating >> wineRating;

            // convert char * to double
            std::string wineType(row[4]);

            // convert (wineType) char * to string 
            istringstream sWP(row[3]);
            double winePrice;
            sWP >> winePrice;

             cout << setw(15) << row[0] << left << setw(10) << " " // coulumn (field) #1 - Wine Name
               << setw(15) << row[1] << left << "  " // field #2 - Vintage
               << setw(15) << row[2] << left << "  " // field #3 - Rating
              << setw(15) << row[3] << left << "  " // field #4 - Price
              << setw(15) << row[4] << left << "  " // field #5 - Wine type
              << endl; // field #7 - UPC
            }
            /* clean up the database result set */
        mysql_free_result(res);
            /* clean up the database link */
        mysql_close(conn);
        break;
      }
      case 4:
      {
        cout << "You are now exiting... \n";
        displayMenu = false;
        break;
      }
    } // end Switch

  } // end MenuDisplay

  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
 
  return 0;
} // end main





