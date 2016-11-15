//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: **
//Complier:  **
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "llist.h"

void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list
  int x;  // to hold a removed element

  //1 check empty and report the result  
  cout << 1 << endl;
  **
  //2 display the list  
  cout << 2 << endl;
  **
  //3 add 4 integers 1,2,3,4    
  cout << 3 << endl;
  **
  //4 display the list  
  cout << 4 << endl;
  **
  //5 remove from front twice (and display the elements removed)
  cout << 5 << endl;
  **
  //6 display the list
  cout << 6 << endl;
  **
  //7 check empty and report the result 
   cout << 7 << endl;
   **
  //8 remove from the rear twice (display the element removed)
   cout << 8 << endl;
   **
  //9 check empty again and report the result
   cout << 9 << endl; 
  **
}//end of case 1 
 
void caseTwo()
{ 
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list
  int x;   // to hold the removed element 
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << c << endl; c++;
  **
  // 2.add to front again  (element 4)
  cout << c << endl; c++;
  **
  // 3.delete Front
  cout << c << endl; c++;
  **
  // 4.add to rear 3 times (elements 6,8,9)
  cout << c << endl; c++;
  **
  // 5. display all
  cout << c << endl; c++;
  **
  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << c << endl; c++;
  **
  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << c << endl; c++;
  **
  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << c << endl; c++;
  **
  // 9.add before the 9th  (element 12) . error (out of range)
  cout << c << endl; c++;
  try{** } 
  catch(**){**}
  // 10.add before the 0th (element 0) . error (out of range)
  cout << c << endl; c++;
  try{** } 
  catch(**){**}
  // 11.displayAll
  cout << c << endl; c++;
  **
  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << c << endl; c++;
  **
  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
  cout << c << endl; c++;
  **
  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << c << endl; c++;
  **
  // 15.delete Ith I==5 . error (out of range)
  cout << c << endl; c++;
  try {** }
  catch(**){** }
  // 16.delete Ith I==0 . error (out of range)
  cout << c << endl; c++;
  try {**}
  catch(**){**}
  // 17.displayAll
  cout << c << endl; c++;
  **
  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << c << endl; c++;
  **
  // 19.displayAll  
  cout << c << endl; c++;
  **

}//end of case 2

void caseThree()
{
  cout << "Case 3:-------------------- " << endl;
  llist L3;
  int x;  // to hold the removed element

  // 1.add before the 0th . error (out of range)
  cout << 1 << endl;;
  try {**}
  catch (**){**}
  //2.delete front . error (underflow)
  cout 2 << endl;
  try {**}
  catch (**){**}
}   //end of case 3

void caseFour()
{
  cout << "Case 4:------------------------ " << endl;
  llist L4;
  int x;  // to hold the removed element

  //   1.delete 2nd . error (out of range)
  cout << 1 << endl;
  try {** }
  catch (**){**}
  //    2.delete rear . error (underflow)
  cout << 2 << endl;
  try {** }
  catch (**){**}
} // end of case 4


//PURPOSE of the Program: **
//Algorithm/Design: 4 test cases are divided into 3 functions and **
int main()
{
  int selection; // this will indicate what the user wants to do
  
  do
    {
      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Case 1  " << endl;
      cout << "   (2) Case 2  " << endl;
      cout << "   (3) Case 3  " << endl;
      cout << "   (4) Case 4 " << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";
      
      cin >> selection;
      
      switch(selection)
	{
	case 1: caseOne(); break;
	case 2: caseTwo(); break;
	case 3: caseThree(); break;
	case 4: caseFour(); break;
	}
    }
  while(selection !=0);

}// end of main

