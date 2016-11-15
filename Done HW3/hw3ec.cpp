//=========================================================
//HW#: HW3P3 Extra Credit
//Your name: Raul Perez
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.cpp"

//PURPOSE: This function simply tests the overloaded "==" of the slist class
int main()
{
  slist L1, L2;
  int temp;
  int counter = 1;
  
  //makes space
  cout << endl;
  
  
  cout << "1. L1 is empty and L2 is empty" << endl;
  if (L1 == L2)
    {
      cout << "true" << endl;
    }
  else
    {
      cout << "false" << endl;
    }
  
  
  cout << "2. L1 is empty and L2 has 2 elements" << endl;
  L2.addRear(1);
  L2.addRear(2);
  if (L1 == L2)
    {
      cout << "true" << endl;
    }
  else
    {
      cout << "false" << endl;
    }
  
  cout << "3. L2 is empty and L1 has 2 elements" << endl;
  L2.deleteFront(temp);
  L2.deleteFront(temp);
  L1.addRear(1);
  L1.addRear(2);
  if (L1 == L2)
    {
      cout << "true" << endl;
    }
  else
    {
      cout << "false" << endl;
    }
  
  cout << "4. L1 has 1,2,3 and L2 has 1,2,3" << endl;
  L1.addRear(3);
  
  L2.addRear(1);
  L2.addRear(2);
  L2.addRear(3);
  if (L1 == L2)
    {
      cout << "true" << endl;
    }
  else
    {
      cout << "false" << endl;
    }
  
  cout << "5. L1 has 1,2,3 and L2 has 1,2" << endl;
  
  L2.deleteRear(temp);
  if (L1 == L2)
    {
      cout << "true" << endl;
    }
  else
    {
      cout << "false" << endl;
    }
  
  cout << "6. L1 has 1,2,3 and L2 has 1,2,3,4" << endl;
  
  L2.addRear(3);
  L2.addRear(4);
  if (L1 == L2)
    {
      cout << "true" << endl;
    }
  else
    {
      cout << "false" << endl;
    }
  
  
  cout << "6. L1 has 1,2,3 and L2 has 1,2,4" << endl;
  
  L2.deleteIth(3, temp);
  if (L1 == L2)
    {
      cout << "true" << endl;
    }
  else
    {
      cout << "false" << endl;
    }
  
}
