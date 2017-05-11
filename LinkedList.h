// LinkedList.h
#include <iostream>
#include <typeinfo>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template< typename T > class List; // forward declaration

template< typename NODETYPE  >
class ListNode 
{

public:
   friend class List< NODETYPE >; // make List a friend
   ListNode( const NODETYPE & ); // constructor
   NODETYPE getData() const; // return the data in the node

   // set nextPtr to nPtr
   void setNextPtr( ListNode *nPtr ) 
   { 
      nextPtr = nPtr; 
   } // end function setNextPtr
   
   // return nextPtr
   ListNode *getNextPtr() const 
   { 
      return nextPtr; 
   } // end function getNextPtr

private:
   NODETYPE data; // data
   int key; // used for key for the list
   ListNode *nextPtr; // next node in the list
}; // end class ListNode

template< typename NODETYPE  >
class List 
{
public:
   List(); // default constructor
   List( const List< NODETYPE > & ); // copy constructor
   ~List(); // destructor

   void insertAtFront( const NODETYPE &, int );
   void insertAtBack( const NODETYPE &, int );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;
   void printPtrFunc(   );
   void printNoteInfo(   );
   NODETYPE * getInfo(int myKey);
      // return nextPtr
   ListNode< NODETYPE >  *getFirstPtr() const 
   { 
      return firstPtr; 
   } // end function getNextPtr
   
 protected:
   ListNode< NODETYPE > *firstPtr; // pointer to first node
   ListNode< NODETYPE > *lastPtr; // pointer to last node

   // Utility function to allocate a new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE &, int );
}; // end class template List

#endif