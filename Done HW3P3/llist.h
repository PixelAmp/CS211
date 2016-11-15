// =======================================================
// HW#: HW3P1 llist
// Your name: Raul Perez
// Compiler:  g++
// File type: header file
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be int (for now)

//a list node is defined here as a struct Node
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist//: public slist
{

 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

 public:

  // Exception handling classes
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes

  //Checks to see if the linked list is empty, returns true if empty, returns false if there is an existing list
  bool isEmpty();

  //Displays the contents in the linked list
  void displayAll();

  //Adds a Node to the fron of the list
  void addFront(el_t);

  //Addds a Node to the back of the list
  void addRear(el_t);

  //deletes the dront Node, making the second one up the new front
  void deleteFront(el_t&);

  //deletes the rear Node
  void deleteRear(el_t&);

  //deletes the Node in the user specified position, throws error if the number is out of range/does not exist
  void deleteIth(int, el_t&);

  //deletes the Node in the front of the user spcified postion, throws error if the number is out of range/does not exist
  void addbeforeIth(int, el_t);

};
