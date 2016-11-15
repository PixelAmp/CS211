// =======================================================
// HW#: HW3P2 llist
// Your name: Raul Perez
// Compiler:  g++
// File type: header file
//=======================================================
#include "llist.cpp"

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be int (for now)

class slist;

//overloads the "==" operator when comparing two linked lists
bool operator== (const slist& first, const slist& second);


//class slist, inheriting publicly from llist
class slist: public llist
{
    friend bool operator== (const slist& first, const slist& second);

public:

    // constructor to create a list object
    slist();

    //search through the list to see if any node contains Key
    int Search(el_t Key);

    //go to the Ith node (I is between 1 and Count) and replace the element there with Elem.
    //If I was an illegal value, throw an exception (OutOfRange).
    void Replace(el_t Elem, int I);

    slist& operator= (const slist& Original);

    bool compare (const slist& Second);

    slist(const slist& Original);
};
