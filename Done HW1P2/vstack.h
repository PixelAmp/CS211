// =======================================================
// HW#: HW1P2 vstack
// Your name: Raul Perez
// Compiler:  g++
// File type: header file vstack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;      // the el_t type is int currently
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{

 private: // to be hidden from the client

  vector<el_t> el;       // el is  an array of el_t's

 public: // prototypes to be used by the client
  // Note that no parameter variables are given

  // exception handling classes
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object

  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);

  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);

  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: pass by refrence the top element
  void topElem(el_t&);


  //PURPOSE: Checks to see if empty of elements, returns true if empty, false if containing elements
  bool isEmpty();
  //PURPOSE: Checks to see if full, returns true number of emements matches MAX, false if size limit is not reached
  bool isFull();
  //PURPOSE: Displays all elements in the stack
  void displayAll();
  //PURPOSE: Clears elements from the stack
  void clearIt();
  //PURPOSE: returns rhe size fof the vector/the position of the top element
  int top();
};

// Note: semicolon is needed at the end of the header file

