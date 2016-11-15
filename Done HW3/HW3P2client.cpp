//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet
//DO not forget to Tab on each line

//=========================================================
//HW#: HW3P2 slist
//Your name: **
//Complier:  **
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: **
int main()
{ slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
try
  {
    //  1)add to front once (element 4)
    cout << counter << endl; counter++;
    **
    //  2)add to rear 3 times (elements 6,7,8)
    cout << counter << endl; counter++;
    **
    //  3)displayAll    - 4 6 7 8
    cout << counter << endl; counter++;
    **
    //  4)search for 6, report the result  - found in pos 2
    cout << counter << endl; counter++;
    **
    //  5)replace the 6 with 0 using the search result
    cout << counter << endl; counter++;
    **
    //  6)search for 8 and report the result . found in pos 4
    cout << counter << endl; counter++;
    **
    //  7)replace the 8 with 2 using the search result
    cout << counter << endl; counter++;
    **
    //  8)displayAll                       - 4 0 7 2
    cout << counter << endl; counter++;
    **
    //  9)search for 5 and report the result   - not found
    cout << counter << endl; counter++;
    **
    // 10) replace postion 7 with 10
    cout << counter << endl; counter++;
    **
    }//end of try
    catch(**)
    { cerr << "ERROR: Bad position was given" << endl;}

}//end of program
