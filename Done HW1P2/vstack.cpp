//=========================================================
//HW#: HW1P1 stack
//Your name: Raul Perez
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;
#include <iostream>
#include <vector>
#include "vstack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{
    // indicate an empty stack
}

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{
      // nothing to do
}

//PURPOSE:  checks top and returns true if empty, false otherwise.
bool stack::isEmpty()
{
  if((el.size()) == 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//PURPOSE: checks top and returns true if full, false otherwise.
bool stack::isFull()
{
  return false;
}

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed
void stack::push(el_t elem)
{
  if (isFull())
    {
      throw Overflow();
    }

  else
    {
      el.push_back(elem);
    }

}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{
  int topSpot = top();

  if (isEmpty())
    {
      throw Underflow();
    }

  else
    {
      elem = el[topSpot];
      el.pop_back();
    }
}

//PURPOSE: returns the top element in the stack
//calls isEmpty and if true, throws an exception (underflow)
//Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{
  if (isEmpty())
    {
      throw Underflow();
    }
  else
    {
      elem = el[top()];
    }

}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//Otherwise, diplays the elements vertically.
void stack::displayAll()
{
  if (isEmpty())
    {
      cout << "[ empty ]" << endl;
      return;
    }

  else
    {
      cout << "[ " ;
      for (int i=0; i < el.size(); i++)
	{
	  cout << el[i]  << " " ;

	  cout << "]" << endl;
	}

    }

}
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
  el_t locVar;

  while (!isEmpty())
    {
      for(int i=top(); i>=0; i--)
        {
	  pop(locVar);
        }
    }

}

//PURPOSE: returns the size of the vector / the position of the top element
int stack::top()
{
  return (el.size()-1);
}

