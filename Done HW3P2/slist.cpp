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
    llist();
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
