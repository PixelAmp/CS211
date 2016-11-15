//=========================================================
//HW#: HW3P2 slist
//Your name: Raul Perez
//Complier:  g++
//File type: client program (tester)
//===========================================================

#include <iostream>
#include "slist.cpp"
using namespace std;

//PURPOSE of the program: To be able to extend the linked list class to allow additional functionality through inheritance
int main()
{
  slist L;  // the list
  int foundPos; // to hold the found position
  int counter = 1; // used to display test line number
  try
    {
      //  1)add to front once (element 4)
      cout << counter << endl; counter++;
      L.addFront(4);
	//  2)add to rear 3 times (elements 6,7,8)
	cout << counter << endl; counter++;
      L.addRear(6);
      L.addRear(7);
      L.addRear(8);

	//  3)displayAll    - 4 6 7 8
	cout << counter << endl; counter++;
      L.displayAll();

	//  4)search for 6, report the result  - found in pos 2
	cout << counter << endl; counter++;
    foundPos = L.Search(6);
    cout << "found in position " << foundPos << endl;

	//  5)replace the 6 with 0 using the search result
	cout << counter << endl; counter++;
      foundPos = L.Search(6);
      L.Replace(0,foundPos);

	//  6)search for 8 and report the result . found in pos 4
	cout << counter << endl; counter++;
    foundPos = L.Search(8);
    cout << "found in position " << foundPos << endl;

	//  7)replace the 8 with 2 using the search result
	cout << counter << endl; counter++;
      L.Replace(2, foundPos);


	//  8)displayAll                       - 4 0 7 2
	cout << counter << endl; counter++;
      L.displayAll();

	//  9)search for 5 and report the result   - not found
	cout << counter << endl; counter++;
      try
      {
          foundPos = L.Search(8);
          if (foundPos== 0)
          {
                cout << "element not found" <<endl;
          }
          else
          {
                cout << "found in position " << foundPos << endl;
          }
      }

      catch(slist::OutOfRange)
      {
          cout << "Out of range" << endl;
      }

	// 10) replace postion 7 with 10
	cout << counter << endl; counter++;
      L.Replace(10,7);

	}//end of try
  catch(llist::OutOfRange)
    { cerr << "ERROR: Bad position was given" << endl;}

}//end of program
