// ====================================================
//HW#: HW3P2 llist
//Your name: Raul Perez
//Complier:  g++
//File type: slist implementation file
//=====================================================
using namespace std;

#include<iostream>
#include "slist.h"

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
slist::slist()
{
  //llist();
  cout << "slist Constructor done" << endl;
}


//search through the list to see if any node contains Key
int slist::Search(el_t Key)
{
  int position = 1;
  Node *p = Front;

  if (Count == 0)
    {
      return 0;
    }

  else
    {
      //looks through nodes in search of matching element
      while (p->Elem!= Key)
        {
	  //fail case if the element is not found within the list
	  if (p->Next == NULL)
            {
	      return 0;
            }
	  //moves on to the next node
	  p = p->Next;
	  //increments the position in the Node
	  position++;
        }
      //returns the position the element was found in, this should only happen if the element was actually found
      return position;
    }
}

//go to the Ith node (I is between 1 and Count) and replace the element there with Elem.
//If I was an illegal value, throw an exception (OutOfRange).
void slist::Replace(el_t usrElem, int I)
{
  Node *p = Front;
  int position = 1;

  //checks to see if I is within the range of the list
  if (I < 1 || I > Count)
    {
      throw OutOfRange();
    }

  else
    {
      //looks through nodes in search of matching element
      while (position != I)
        {
	  //moves on to the next node
	  p = p->Next;
	  //increments the position in the Node
	  position++;
        }

      cout << "replaced " << p->Elem << " with " << usrElem << endl;

      //at this point p should be in the Node requested
      p->Elem = usrElem;
    }
}

//compares two linked lists passed by value without changing them
bool operator== (const slist& first, const slist& second)
{

  //compares the size of both linked lists, if not the same, returns false
  //Does this first because it is the easiest thing to check
  if (first.Count != second.Count)
    {
      return false;
    }

  //creates pointers for each of the linked lists
  Node *firstP = first.Front;
  Node *secondP = second.Front;

  //compares the elements in each level of the linked lists
  for (int i = 0; i < first.Count ; i++)
    {
      //if the elements do not match at any point, returns false
      if (firstP->Elem != secondP->Elem)
        {
	  return false;
        }
      //moves on to next node for both lists
      firstP = firstP->Next;
      secondP = secondP->Next;
    }

  //returns true if all the other tests were passed, meaning that they are the same
  return true;

}


//function to compare the passed slist with the current linked list
//made specifically for the "==" overload function to check if the two functions are the same
//there is proably an easier way to do this, but this works, so meh
bool slist::compare(const slist& second)
{
  Node *firstP = Front;
  Node *secondP = second.Front;


  //special case in the case that both are empty, as both should be pointing to front right now
  if ((firstP == NULL) && (secondP == NULL))
    {
      return true;
    }


  //runs to the end of one of the lists
  //stops if the bottom of one of the lists is reached.
  while((firstP != NULL) && (secondP != NULL))
    {
      //checks each element in each list
      if(firstP->Elem != secondP->Elem)
        {
	  return false;
        }

      //if both are at the bottom of their lists, they are the same length
      if ((firstP->Next == NULL) && (secondP->Next == NULL))
        {
	  return true;
        }


      //moves onto the next node of each list
      firstP = firstP->Next;
      secondP = secondP->Next;
    }


  //returns false because if it gets here, the lists are of different lengths, thus are different
  return false;
}


// Note that Original is being passed by reference
// The resulting List will be returned by reference
slist& slist::operator=(const slist& Original)
{
  //temporary element that holds the thing from deleteFront
  el_t element;

  // First make sure the current list and Original are not the same object.
  // Uses the above function to search through both lists
  if (!compare(Original))// if not the same, just returns back to the call
    {

      //clears out the current list, so that the Original array can be copied into it
      while (!(isEmpty()))
	{
          llist::deleteFront(element);
	}

      //cleates a pointer for Original linked list
      Node* P =  Original.Front;

      while (P != NULL)  // This uses a loop which repeats until you reach the end of Original.
	{
	  //puts element fron original into the copy list
	  addRear(P->Elem);

	  // Go to the next node in Original
	  P = P->Next;
	}
    }// end of if
}

//Copy Constructor
slist::slist(const slist& Original)
{
    //  this-> object is built up by allocating new cells
    //  and copying the values from Original into each cell

    Node* P;  // local pointer for OtherOne
    P = Original.Front;
    while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne.
        {
            this->addRear(P->Elem);    //P’s element is added to this->
            P = P->Next;               // Go to the next node in OtherOne
        }

    //  Nothing to return.
}
