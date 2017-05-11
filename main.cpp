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

  // console program
  int choice;
  int choiceOfOne;
  bool displayMenu = true;

  //option select mySQL
  double xa, xb; // price 1 and price 2
  int ya, yb; // year 1 and year 2
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
        res = mysql_perform_query(conn, (char *)"select name, vintage, score, price, type from wineInfo order by score, price");

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

            /* clean up the database result set */
            mysql_free_result(res);
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

            /* clean up the database result set */
            mysql_free_result(res);
            break;
          }
        }
        break;
      }
      case 2:
      {
        cout << "Enter Desired Price Range\n";
        cin >> xa >> xb;
        oss << "select name, vintage, score, price, type from wineInfo where price between " << xa << " and " << xb << " order by price";
        s = oss.str(); 
        sqlcmd = (char *)s.c_str();
        res = mysql_perform_query(conn,sqlcmd);

        cout << left << setw(30) <<"Wine Name" <<
                            left << setw(15) << "Vintage" <<
                 left << setw(15) << "Rating" <<
                 left << setw(15) << "Price"  <<
                 left << setw(15) << "Type"
            << endl;


            while ((row = mysql_fetch_row(res)) !=NULL)
            {
             cout << setw(32) << left << row[0] << setfill(' ') // coulumn (field) #1 - Wine Name
              << setw(15) << row[1] << setfill(' ') // field #2 - Vintage
              << setw(15) << row[2] << setfill(' ') // field #3 - Rating
              << setw(13) << row[3] << setfill(' ') // field #4 - Price
              << setw(10) << row[4] << setfill(' ') // field #5 - Wine type
              << endl;
            }
            /* clean up the database result set */
        mysql_free_result(res);
            /* clean up the database link */
        break;
      }
      case 3:
      {
        cout << "Enter Year\n";
        cin >> ya >> yb;
        oss << "select name, vintage, score, price, type from wineInfo where vintage between " << ya << " and " << yb << " order by vintage desc, score desc";
        s = oss.str(); 
        sqlcmd = (char *)s.c_str();
        res = mysql_perform_query(conn,sqlcmd);

        cout << left << setw(30) <<"Wine Name" <<
                            left << setw(15) << "Vintage" <<
                 left << setw(15) << "Rating" <<
                 left << setw(15) << "Price"  <<
                 left << setw(15) << "Type"
            << endl;


            while ((row = mysql_fetch_row(res)) !=NULL)
            {
             cout << setw(32) << left << row[0] << setfill(' ') // coulumn (field) #1 - Wine Name
              << setw(15) << row[1] << setfill(' ') // field #2 - Vintage
              << setw(15) << row[2] << setfill(' ') // field #3 - Rating
              << setw(13) << row[3] << setfill(' ') // field #4 - Price
              << setw(10) << row[4] << setfill(' ') // field #5 - Wine type
              << endl;
            }
            /* clean up the database result set */
        mysql_free_result(res);
            /* clean up the database link */
        break;
      }
      case 4:
      {
        mysql_close(conn);
        cout << "You are now exiting... \n";
        displayMenu = false;
        break;
      }
    } // end Switch

  } // end MenuDisplay
 
} // end main





