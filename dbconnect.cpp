
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "dbconnect.h"

/**

   Purpose:

       Set up connection with mySQL and print if there's an error. 

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param connection_details mysql_details - mySQL login information

   @return - connection

*/
MYSQL* mysql_connection_setup(struct connection_details mysql_details)
{
     // first of all create a mysql instance and initialize the variables within
    MYSQL *connection = mysql_init(NULL);
 
    // connect to the database with the details attached.
    if (!mysql_real_connect(connection,mysql_details.server, 
	mysql_details.user, mysql_details.password, 
	mysql_details.database, 0, NULL, 0)) {
      printf("Conection error : %s\n", mysql_error(connection));
      exit(1);
    }
    return connection;
}
/**

   Purpose:

       Use mySQL statements to print and sort database

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param *connection - Connect to mySQL

   @param *sql_query - mySQL statement

   @return - none

*/ 
MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query)
{
   // send the query to the database
   if (mysql_query(connection, sql_query))
   {
      printf("MySQL query error : %s\n", mysql_error(connection));
      exit(1);
   }
 
   return mysql_use_result(connection);
}
 
