
#include <iostream>
#include <typeinfo>
#include "LinkedList.hpp"
#include "person.h"

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
   
} // end main





