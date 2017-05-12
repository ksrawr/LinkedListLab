//LinkedList.hpp

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "LinkedList.h"


/**

   Purpose:

       Assign node data the address of node info which is assigned
       to the address of the variables where we set our info for our class 
       and set nextPtr to NULL.

   @author Ron Sha

   @version 1.0 1/27/2017



   @param &info - node address, assigned the content of our class setInfo
                  function.

   @return - none

*/
// constructor
template< typename NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
{
   data = info;
   nextPtr = 0;
} // end constructor
/**

   Purpose:

       Get data and return it

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param - none

   @return - data

*/
// return a copy of the data in the node
template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
} // end function getData
/**

   Purpose:

       Constructor for list. To assign firstPtr and lastPtr to NULL.

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param - none

   @return - none

*/
// default constructor
template< typename NODETYPE >
List< NODETYPE >::List() 
{ 
   firstPtr = lastPtr = 0; 
} // end constructor
/**

   Purpose:

       insertAtBack our data by using currentPtr->data and then by pointing
       it to the nextPtr via currentPtr->nextPtr.  

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param - none

   @return - none

*/
// copy constructor
template< typename NODETYPE >
List< NODETYPE >::List( const List<NODETYPE> &copy )
{
   firstPtr = lastPtr = 0; // initialize pointers

   ListNode< NODETYPE > *currentPtr = copy.firstPtr;

   // insert into the list
   while ( currentPtr != 0 ) 
   {
      insertAtBack( currentPtr->data );
      currentPtr = currentPtr->nextPtr;
   } // end while
} // end List copy constructor
/**

   Purpose:

       Desconstructor. Print "Destroying nodes..."" when program exits 
       and destroy nodes by using tempPtr. Since is assigned the value pointed by
       currentPtr, and when currentPtr points to data. We can delete it by saying
       delete tempPtr.

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param - none

   @return - none

*/
// destructor
template< typename NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) // List is not empty
   {
      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
      {
         tempPtr = currentPtr;
//         cout << tempPtr->data << ' ';
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      } // end while
   } // end if

   cout << "\nAll nodes destroyed\n\n";
} // end destructor/**
/*
   Purpose:

       Insert our desired node at the front of the list. 

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param &value - The node we are adding to the the front of the list

   @param key - ID key for list

   @return - none

*/
// Insert a node at the front of the list
template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value, int key)
{
   ListNode<NODETYPE> *newPtr = getNewNode( value, key );

   if ( isEmpty() ) // List is empty
      firstPtr = lastPtr = newPtr;
   else // List is not empty
   {
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;
   } // end else
} // end function insertAtFront
/**

   Purpose:

       Insert a node at the back of the list.

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param &value - The node we are adding to the back of the list

   @param key - ID key for list

   @return - none

*/
// Insert a node at the back of the list
template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value, int key)
{
	ListNode<NODETYPE> *newPtr = getNewNode( value, key );
  /*
   * YOU MUST IMPLEMENT THIS FUNCTION AS 
   * PART OF THIS LAB
   * */
  if ( isEmpty() )
  	firstPtr = lastPtr = newPtr;
  else
  {
  	lastPtr->nextPtr = newPtr;
  	lastPtr = newPtr;
  }
  
} // end function insertAtBack
/**

   Purpose:

       Remove a node from the front of the list

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param &value - node we are removing

   @return - none

*/
// Delete a node from the front of the list
template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   else 
   {
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data; // data being removed

      delete tempPtr;
      return true; // delete successful
   } // end else
} // end function removeFromFront
/**

   Purpose:

       Remove node from the back of the list

   @author Ron Sha

   @editted by Kenneth Surban

   @version 1.0 5/11/2017

 

   @param &value - desired node to remove from the back of the list

   @return - none

*/
// delete a node from the back of the list
template< typename NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
	
	/*
	 * Implement this function.  Use removeFromFront as an
	 * example in implemeting this function
	 * */
	 
	 
   if ( isEmpty() )
      return false; // delete unsuccessful
   else 
   {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else 
      {
		  
         ListNode< NODETYPE > *currentPtr = firstPtr;

	/*  this is where you need add more code
	 * First, you need to start from the beginning of the linked list,
	 * and traverse until the node before the last node.
	 * 
	 * Once you got to the node before the last node, you need to 
	 * point the node before last node to the last node so you can 
	 * remove the last node
	 * 
	 * */
	 	while(currentPtr -> nextPtr != lastPtr){
	 		currentPtr = currentPtr -> nextPtr;
    }
	 	lastPtr = currentPtr;
	 	currentPtr->nextPtr = NULL;
  
      // your codes here
      // more codes
  
      } // end else

      value = tempPtr->data;
      delete tempPtr;
      return true; // delete successful
   } // end else
} // end function removeFromBack
/**

   Purpose:

       Assign and return firstPtr to NULL if list is empty. 

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param - none

   @return - none

*/
// Is the List empty?
template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
} // end function isEmpty
/**

   Purpose:

       Get new nodes by returning a pointer a new node. 

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param &value - node to retrieve

   @return - ptr

*/
// Return a pointer to a newly allocated node
template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
   const NODETYPE &value, int)
{
   ListNode< NODETYPE > *ptr = new ListNode< NODETYPE >( value );
   return ptr;
} // end function getNewNode
/**

   Purpose:

       Print out if the list is empty and if not print out its elemenets.

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param - none

   @return - none

*/
// Display the contents of the List
template< typename NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) // empty list
   {
      cout << "The list is empty\n\n";
      return;
   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   //cout << "The list is: ";

   while ( currentPtr != 0 ) // display elements in list
   {
       int i;
       string s;
       double d;
       char c;
       if (typeid(currentPtr->data).name() == typeid(i).name() ||
           typeid(currentPtr->data).name() == typeid(d).name() ||
           typeid(currentPtr->data).name() == typeid(s).name() ||
           typeid(currentPtr->data).name() == typeid(c).name())
       {
        // data value is a simple data type and can be printed
        cout << currentPtr->data << ' ';
       }
       else {
         cout <<"Can't print - Not a simple data type (int, string, char, double)\n";
       }
      currentPtr = currentPtr->nextPtr;
   } // end while

   cout << "\n\n";
} // end function print

/**

   Purpose:

       Get info on list if it's empty and return NULL. If it's not point to
       the values in data. 

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param myKey - ID key required to getInfo

   @return - NULL(if list is empty) otherwise return values of data

*/   
// Display the contents of the List
template< typename NODETYPE >
NODETYPE * List< NODETYPE >::getInfo(int myKey)
{
   if ( isEmpty() ) // empty list
   {
  //    cout << "The list is empty\n\n";
      return NULL;
   } // end if
  
   ListNode< NODETYPE > *currentPtr = firstPtr;

   //cout << "The list is: \n";

   while ( currentPtr != 0 ) // display elements in list
   {
        //if (currentPtr->key == myKey ) { // found
           return (& currentPtr->data);
        //}
 
      currentPtr = currentPtr->nextPtr;
   } // end while

   return NULL;  // can't find
} // end function print


/**

   Purpose:

       Print out the nodes in the list. 

   @author Ron Sha

   @version 1.0 1/27/2017

 

   @param List< NODETYPE > & nodeList - list of nodes

   @return - none

*/
template< typename NODETYPE >
void printNoteInfo (  List< NODETYPE > & nodeList)
{   
   NODETYPE *wp;
   wp = (NODETYPE *) nodeList.getInfo(0); //get node based on key
   
   ListNode< NODETYPE > *currentPtr;     
   currentPtr =  nodeList.getFirstPtr();
  

   
   //cout << "\n The node list is: \n";
   //print out all the info in linked list
   while ( currentPtr != 0 ) // display elements in list
   {
      wp = (NODETYPE *) currentPtr; //convert to correct data type
      currentPtr = currentPtr->getNextPtr();
      wp->printInfo();
   } // end while
}   
         
#endif