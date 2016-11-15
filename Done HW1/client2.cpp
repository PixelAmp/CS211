//INSTRUCTION
//Look for ** to complete this program
//The string output should match my hw1queueDemo.out
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Raul Perez
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.cpp"

//Purpose of the program: all strings using A, B, and C as the letters
//Algorithm: **
int main()
{
    bool good = true;
    int amount = 0;

    queue codeBreak;  // this is the queue object Q

    string element, newCode;

    //starts off the element queue
    codeBreak.add("A");
    codeBreak.add("B");
    codeBreak.add("C");



  while(good)    //loop -- indefinitely
    {
        codeBreak.remove(element);
      try
      {
        for (int i =0; i < 3; i++) //goes through the 3 letters
        {
            if (i == 0) //A
            {
                newCode = element+'A';
                codeBreak.add(newCode); //adds new code to the back with an added A

            }

            else if (i == 1) //B
            {
                newCode = element+'B';
                codeBreak.add(newCode); //adds new code to the back with an added B
            }

            else if (i == 2) //C
            {
                newCode = element+'C';
                codeBreak.add(newCode); //adds new code to the back with an added C
            }
        }

      }
        catch(queue::Overflow)
        {
            cerr << "Error: Overflow, reached max size of the Queue." << endl;
            break;
        }


      codeBreak.displayAll();
      amount = codeBreak.getSize();
      cout << "There are " << amount << " items in the queue";
      cout << endl;
    }

    return 0;
}

