// ====================================================
//HW#: HW3P1 llist
//Your name: Raul Perez
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h"

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
  cout << "llist Constructor done" << endl;
}

//Destructor
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
llist::~llist()
{
  el_t x;

  while (!isEmpty())
    {
      try
        {
            deleteFront(x);
        }

            catch (llist::Underflow())
        {
	  cout << "empty" << endl;
        }
    }

  cout << "llist Destructor done" << endl;
}

//- return true if Front and Rear are both pointing to NULL and Count is 0.
//- (all 3 conditions must be checked)
bool llist::isEmpty()
{
  if (Front == NULL && Rear == NULL && Count == 0)
    {
      return true;
    }

  else
    {
      return false;
    }
}

//- Special case: if the list is empty, display [ empty ] ).
//- Regular:
//  displays each element of the list horizontally starting from Front in [ ].
void llist::displayAll()
{
  Node* p = Front;
  int i = 0;

  if (isEmpty())
    {
      cout << "[ empty ]" << endl;
    }
  else
    {
      cout << "[ ";
      while (p != NULL)
        {
	  //prevents program from overflowing, user should NEVER see this (if I did my job correctly)
	  if (i == Count)
            {
	      cout << "overflow, the nodes were not connected properly you dingus" << endl;
	      return;
            }


	  cout << p->Elem << " ";
	  p = p->Next;

	  i++;
        }
      cout << "]" << endl;

    }
  //cout << "Count is " << Count << endl;
}

void llist::addRear(el_t NewNum)
{
  //Special case: if this is going to be the very first node, you must
  //create a new node and make Front and Rear point to it. Place NewNum and
  //Count is updated.
  if (Count == 0)
    {
      Node* p = new Node;
      p->Elem = NewNum;
      p-> Next = NULL;

      Front = p;
      Rear = p;
      Count++;
    }
  //Regular: adds a new node at the rear and puts NewNum in the Elem field
  //of this new node. Count is updated.
  else
    {
      Rear->Next = new Node;

      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }
}



void llist::addFront(el_t NewNum)
{

  //Special case: if this is going to be the very first node, you must
  //create a new node and make Front and Rear point to it. Place NewNum and
  //Count is updated.

  if (Count == 0)
    {
      Node* p = new Node;
      p->Elem = NewNum;
      p-> Next = NULL;

      Front = p;
      Rear = p;
      Count++;
    }


  //- Regular: add a new node to the front of the list and
  //Count is updated.
  else
    {
      Node *x;
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      Count++;
    }


}


void llist::deleteFront(el_t& OldNum)
{
  //Error case: if the List is empty, throw Underflow
  if (Count == 0)
    {
      throw Underflow();
    }
  //Special case: if currently only one Node,
  // give back the front node element through OldNum (pass by reference) and
  //make sure both Front and Rear become NULL. Count is updated.


  else if (Count == 1)
    {
      OldNum = Front->Elem;
      Front = NULL;
      Rear = NULL;
      Count--; //should be zero at this point
    }


  //Regular: give back the front node element through OldNum (pass by reference)
  //and also removes the front node.  Count is updated.
  else
    {
      //gets the number from the front
      OldNum = Front->Elem;

      //creates a placeholder pointer
      Node *Second;

      //holds the position of the next Node
      Second = Front->Next;

      //deletes the current front Node
      delete Front;

      //makes the second node thake the place of the first Node
      Front = Second;

      //cout << Front->Elem << " is now at the front, after deleteing the other front" << endl;

      Count--;
    }


}



void llist::deleteRear(el_t& OldNum)
{

  //Error case: if empty, throw Underflow
  if (Count == 0)
    {
      throw Underflow();
    }


  //Special case: if currently only one node,
  //give back the rear node element through OldNum (pass by reference) and
  //make sure both Front and Rear become NULL. Count is updated.
  else if (Count == 1)
    {
      OldNum = Rear->Elem;
      Front = NULL;
      Rear = NULL;
      Count--; //should be zero at this point
    }



  //Regular: give back the rear node element through OldNum (pass by reference)
  //and also remove the rear node. Count is updated.
  else
    {
      OldNum = Rear->Elem;
      Node *p = Front;

      while (p->Next->Next != NULL)
        {
	  p = p->Next;
        }

      delete Rear;
      Rear = p;
      Rear->Next = NULL;

      Count--;
    }

}


void llist::deleteIth(int I, el_t& OldNum)
{

  //If I is an illegal value
  if ((I < 1 ) || (I > Count))
    {
      throw OutOfRange();
    }

  //if asking to delete the first node, just calling delete front
  else if (I == 1)
    {
      deleteFront(OldNum);
    }

  //if I is equal to count, that means it wants to deltete the back node, thus just calling delete back
  else if (I == Count)
    {
      deleteRear(OldNum);
    }

  //if the node to be delteted is more than 2, and Node is before the end
  else
    {
      Node *p = Front;
      Node *j = Front->Next;

      //loop to get the j node into the node that is to be deleted, with the p node being one behind it
      for (int i = 2; i < I; i++)
        {
	  p = p->Next;
	  j = j->Next;
        }

      //Grabs the node off the chosen Node
      OldNum = j->Elem;

      //makes it so that the selected node is skipped
      p->Next = p->Next->Next;

      //deletes the j node, which is the one the user wanted to delete
      delete j;

      //decrements count
      Count--;
      //cout << "count is now " << Count << endl;
    }

}




void llist::addbeforeIth(int I, el_t newNum)
{
  //I is an illegal value
  if ((I < 1 ) || (I > Count+1))
    {
      throw OutOfRange();
    }

  //if asking to add before the first node, just calling add front
  else if (I == 1)
    {
      addFront(newNum);
    }

  //if I is equal to count, that means it wants to deltete the back node, thus just calling addRear
  else if (I == Count)
    {
      addRear(newNum);
    }

  //if the node to be added is more than 2, and Node is before the end
  else
    {
      Node *p = Front;
      Node *j = Front->Next;

      //loop to get the j node into the node that is selected, with the p node being one behind it
      for (int i = 1; i < I; i++)
        {
	  p = p->Next;
	  j = j->Next;
        }
      //creates a new node before the selected node
      p->Next = new Node;

      //moves into the new Node
      p = p->Next;

      //inserts the element into the new Node
      p->Elem = newNum;

      //appends the selected element to be after the new node
      p->Next = j;
      cout << j->Elem << endl;

      //increments count
      Count++;
    }
}
