// Try this
// Does this compile and run?  You have to have completed HW3P1 already

using namespace std;
#include <iostream>
#include "llist.cpp"

int main()
{
  llist A;
  llist B;

  A.addRear(6);
  A.addRear(7);
  A.addRear(8);
  A.displayAll();

  B = A;

  B.addFront(5);
  cout << "B" << endl;
  B.displayAll();

  cout << "A" << endl;
  A.displayAll();

  A.addRear(9);

  cout << "B" << endl;
  B.displayAll();

}


