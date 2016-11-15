
//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Raul Perez
//Complier:  g++
//File type: .cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"

// constructor
queue::queue()
{
  count = front = 0;
  rear = -1;
}

//destructor
queue::~queue()
{

}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count == 0) //if current size is zero(empty), returns true
    {
      return true;
    }

  else //else if count is not 0, returns false
    {
      return false;
    }

}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if (count == MAX_SIZE) //if current size matches the max size, returns true
    {
      return true;
    }

  else //else if count is not max, reurns false
    {
      return false;
    }

}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
    //checks if queue is full
    if (isFull())
        {
            throw Overflow{};
        }

    if (rear+1 == MAX_SIZE)// if the last element is at the end of the array, wraps around to the front
    {
        //sets pointer to front of array
        rear = 0;
        //puts new element into new position
        el[rear] = newElem;
        //increments count due to new element that was added
        count++;
        return;
    }

    else //if the rear element is not in the back of the array
    {
        //sets pointer to front of array
        rear++;
        //puts new element into new position
        el[rear] = newElem;
        //increments count due to new element that was added
        count++;
        return;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  //checks if queue is empty
  if (isEmpty())
    {
      throw Underflow{};
    }

    //grabs element now, so I dont forget to do it later
    removedElem = el[front];

    if (front+1 == MAX_SIZE)// if front element is at the back of the array
    {
        //changes pointer to the front of the array
        front = 0;
        //changes count to reflect element removal
        count--;
    }


    else //base case, also catches case when count is only 1
    {
        //moves front counter back one to reflect the change in the removal
        front++;

        //changes count to reflect element removal
        count--;
    }



}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  //checks if queue is empty
  if (isEmpty())
    {
      throw Underflow{};
    }

  //makes passes element equal to the front element in the array
  theElem = el[front];
}

// PURPOSE: returns the current size to make it
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
    if (isEmpty()) //checks to see if array is empty
    {
        cout << "[ empty ]" << endl;
        return;
    }


    else // if the array is not empty
    {
        if (rear < front) //if the array has to wrap around
        {
            cout << "[ " ;

            //outputs everything in array up until the end of the array
            for (int i=front; i < MAX_SIZE; i++ )
            {
                cout << el[i] << " ";
            }

            //outputs everything until it gets to the rear of the array
            for (int i = 0; i <= rear; i++)
            {
                cout << el[i] << " ";
            }

            cout << "]" << endl;
        }

        else //if there is no need to wrap around
        {
            cout << "[ " ;
            for (int i=front; i<(front+count); i++)
                {
                    cout << el[i] << " ";
                }
            cout << "]" << endl;
        }
    }

}


// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
    // ** comment a local variable
    if (isEmpty())
      {
        throw Underflow{};
      }

    else if(count == 1) //if thetre is only one element in the array, there is nothing to move
    {
        return;
    }

    else if(isFull())//checks to see if array is full
    {
        //if the array is full, I pretty much just have to change the pointers since nohing needs to be moved

        if (front+1 < MAX_SIZE && rear+1 < MAX_SIZE)//checks to see if the front and rear elements are not at the very end of the array
        {
            //shifts the rear forward one, moving front to the rear of queue
            rear++;
            //shifts the front forward by one, making second in line the front
            front++;
        }

        else if(front+1 == MAX_SIZE) //if front element is at the very back of the array
        {
            //wraps the front element around to front of the array
            front = 0;
            //increments back position to match the change on the array
            rear++;
        }

        else if(rear+1 == MAX_SIZE) //if the rear element is at the very back of the array
        {
            //moves rear position to point to the front elementate the very front of the array
            rear = 0;
            //moves the front forwards accordingly
            front++;
        }

    }

    else //if the array is not full, but greater than 1
    {
        //holds the front element in a holder variable
        el_t hold = el[front];


        if(front+1 == MAX_SIZE) //if front element is at the very back of the array
        {
            //effectivly moves front forward one, wrapping it around to the very front of the array
            front = 0;

            //increments rear and places the element that was formerly in the front into the back of the array
            rear++;
            el[rear] = hold;
        }

        else if(rear+1 == MAX_SIZE) //if the rear element is at the very back of the array
        {
            //effectivly moves rear forward one, wrapping it around to the very front of the array
            rear = 0;

            //increments front position
            front++;

            //places formerly front variable in the new position
            el[rear] = hold;
        }


        else //if the array is not full, and front and rear are somewhere in the middle of the array
        {
            //increments front position
            front++;

            //moves rear forward one places formerly front variable in the new position
            rear++;
            el[rear] = hold;
        }
    }
}
